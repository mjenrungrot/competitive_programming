#include <bits/stdc++.h>
using namespace std;

const int NONE = -1;

class seg_tree{
    private:
    int n;
    vector<int> A, st, lazy;

    int l(int p){ return p<<1;}
    int r(int p){ return (p<<1)+1;}

    int conquer(int a, int b){
        if(a == NONE) return b;
        if(b == NONE) return a;
        return min(a, b);
    }
    
    void build(int p, int L, int R){
        if(L == R) st[p] = A[L];
        else{
            int m = (L+R)>>1;
            build(l(p), L, m);
            build(r(p), m+1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    void propagate(int p, int L, int R){
        if(lazy[p] != -1){
            st[p] = lazy[p];
            if(L!=R) lazy[l(p)] = lazy[r(p)] = lazy[p];
            else A[L] = lazy[p];
            lazy[p] = NONE;
        }
    }

    int RMQ(int p, int L, int R, int i, int j){
        propagate(p, L, R);
        if(i > j) return -1;
        if((L>=i) and (R<=j)) return st[p];
        int m = (L+R)>>1;
        return conquer(RMQ(l(p), L, m, i, min(m,j)),
                       RMQ(r(p),m+1,R, max(i,m+1), j));
    }

    void update(int p, int L, int R, int i, int j, int val){
        propagate(p, L, R);
        if(i>j) return;
        if((L>=i) and (R<=j)){
            lazy[p] = val;
            propagate(p, L, R);
        }else{
            int m = (L+R)>>1;
            update(l(p), L, m, i, min(m,j), val);
            update(r(p), m+1, R, max(i,m+1), j, val);
            int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
            st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
        }
    }

    public:
    seg_tree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {}   
    seg_tree(vector<int> &initialA) : seg_tree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }
    void update(int i, int j, int val){ update(1, 0, n-1, i, j, val);}
    int RMQ(int i, int j){ return RMQ(1, 0, n-1, i, j);}
    int at(int i){ return A[i];}
};


int main(){
    int N, M, x;
    vector <int> A;

    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++){
        scanf("%d", &x);
        A.push_back(x);
    }

    char commands[40], *token;
    seg_tree T(A);
    vector<int> params; 
    for(int i=1;i<=M;i++){
        scanf("%s", commands);
        params.clear();
        token = strtok(&commands[6], ",)");
        while(token != NULL){
            params.push_back(atoi(token) - 1);
            token = strtok(NULL, ",)");
        }

        if(commands[0] == 'q'){
            printf("%d\n", T.RMQ(params[0], params[1]));
        }else{
            int tmp = T.at(params[0]);
            for(int j=0;j<params.size()-1;j++){
                T.update(params[j], params[j], T.at(params[j+1]));
            }
            T.update(params[params.size()-1], params[params.size()-1], tmp);
        }
    }

    return 0;
}