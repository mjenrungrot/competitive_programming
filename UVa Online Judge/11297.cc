#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
const int MAXN = 505;  
typedef pair<int,int> ii;

int N;
int A[MAXN][MAXN];
int min_st[4*MAXN][4*MAXN], max_st[4*MAXN][4*MAXN];

int ll(int p){ return p<<1;}
int rr(int p){ return (p<<1)+1;}

void build_x(int px, int py, int Lx, int Rx, int row, bool single_row){
    if(Lx == Rx){
        if(single_row){
            min_st[py][px] = max_st[py][px] = A[row][Lx];
        }else{
            min_st[py][px] = min(min_st[ll(py)][px], min_st[rr(py)][px]);
            max_st[py][px] = max(max_st[ll(py)][px], max_st[rr(py)][px]);
        }
        return ;
    }
    int m = (Lx+Rx)>>1;
    build_x(ll(px), py, Lx, m, row, single_row);
    build_x(rr(px), py, m+1, Rx, row, single_row);
    min_st[py][px] = min(min_st[py][ll(px)], min_st[py][rr(px)]);
    max_st[py][px] = max(max_st[py][ll(px)], max_st[py][rr(px)]);
}
void build_y(int py, int Ly, int Ry){
    if(Ly == Ry){
        build_x(1, py, 0, N-1, Ly, true);
        return ;
    }
    int m = (Ly+Ry)>>1;
    build_y(ll(py), Ly, m);
    build_y(rr(py), m+1, Ry);
    build_x(1, py, 0, N-1, -1, false);
}

void update_x(int px, int py, int Lx, int Rx, int x, int val, int row, bool single_row){
    if(Lx == Rx){
        if(single_row) min_st[py][px] = max_st[py][px] = val;
        else{
            min_st[py][px] = min(min_st[ll(py)][px], min_st[rr(py)][px]);
            max_st[py][px] = max(max_st[ll(py)][px], max_st[rr(py)][px]);
        }
        return ;
    }
    int m = (Lx+Rx)>>1;
    if(x<=m) update_x(ll(px), py, Lx, m, x, val, row, single_row);
    else     update_x(rr(px), py, m+1, Rx, x, val, row, single_row);
    min_st[py][px] = min(min_st[py][ll(px)], min_st[py][rr(px)]);
    max_st[py][px] = max(max_st[py][ll(px)], max_st[py][rr(px)]);            
}
void update_y(int py, int Ly, int Ry, int y, int x, int val){
    if(Ly == Ry){
        update_x(1, py, 0, N-1, x, val, Ly, true);
        return;
    }
    int m = (Ly+Ry)>>1;
    if(y<=m) update_y(ll(py), Ly, m, y, x, val);
    else     update_y(rr(py), m+1, Ry, y, x, val);
    update_x(1, py, 0, N-1, x, val, -1, false);
}

void query_x(int px, int py, int Lx, int Rx, int x1, int x2, int &min_val, int &max_val){
    if(x2 < Lx or x1 > Rx) return;
    if(x1 <= Lx and Rx <= x2){
        min_val = min(min_val, min_st[py][px]);
        max_val = max(max_val, max_st[py][px]);
        return ;
    }
    int m = (Lx+Rx)>>1;
    query_x(ll(px), py, Lx, m, x1, x2, min_val, max_val);
    query_x(rr(px), py, m+1, Rx, x1, x2, min_val, max_val);
}
void query_y(int py, int Ly, int Ry, 
                int y1, int y2, int x1, int x2, 
                int &min_val, int &max_val){
    if(y2 < Ly or y1 > Ry) return;
    if(y1<=Ly and Ry<=y2){
        query_x(1, py, 0, N-1, x1, x2, min_val, max_val);
        return;
    }
    int m = (Ly+Ry)>>1;
    query_y(ll(py), Ly, m, y1, y2, x1, x2, min_val, max_val);
    query_y(rr(py), m+1, Ry, y1, y2, x1, x2, min_val, max_val);
}


void build(){
    build_y(1, 0, N-1);
}
void update(int y, int x, int val){
    update_y(1, 0, N-1, y, x, val);
}
void query(int y1, int y2, int x1, int x2, int &min_val, int &max_val){
    query_y(1, 0, N-1, y1, y2, x1, x2, min_val, max_val);
}

int Q, x;
char ch;

int main(){
    cin >> N;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++){
        cin >> A[i][j];
    }
    build();
    
    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> ch;
        if(ch == 'q'){
            int lx, ly, rx, ry, min_val = INF, max_val = -INF;
            cin >> ly >> lx >> ry >> rx;
            lx--, ly--, rx--, ry--;
            query(ly, ry, lx, rx, min_val, max_val);
            cout << max_val << " " << min_val << endl;
        }else{
            int xx, yy, val;
            cin >> yy >> xx >> val;
            xx--, yy--;
            update(yy, xx, val);
        }
    }

    return 0;
}