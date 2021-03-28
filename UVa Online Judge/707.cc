#include <bits/stdc++.h>
using namespace std;

const int UNKNOWN = 0;
const int NO = 1;
const int MAYBE = 2;

int W, H, t;
int nt, nq;
int possible[105][105][105];

int solve(int y, int x, int curr_time){
    if(x < 1 or y < 1 or x > W or y > H) return NO;
    if(possible[curr_time][y][x] != UNKNOWN) return possible[curr_time][y][x];
    if(curr_time == t){
        possible[curr_time][y][x] = MAYBE;
        return MAYBE;
    }

    int a = solve(y, x, curr_time+1);
    int b = solve(y+1, x, curr_time+1);
    int c = solve(y-1, x, curr_time+1);
    int d = solve(y, x+1, curr_time+1);
    int e = solve(y, x-1, curr_time+1);
    if(a == MAYBE or b == MAYBE or c == MAYBE or d == MAYBE or e == MAYBE){
        possible[curr_time][y][x] = MAYBE;
    }else{
        possible[curr_time][y][x] = NO;
    }
    return possible[curr_time][y][x];
}

int main(){
    while(scanf("%d %d %d", &W, &H, &t) != EOF){
        if(W == 0 and H == 0 and t == 0) break;
        for(int i=1; i<=W; i++) for(int j=1;j<=H;j++) for(int k=1;k<=t;k++) possible[k][j][i] = UNKNOWN;
        scanf("%d", &nq);
        

        for(int i=1; i<=nq; i++){
            int t0, l, t, r, b;
            scanf("%d %d %d %d %d", &t0, &l, &t, &r, &b);
            for(int r0=t; r0<=b; r0++) for(int c0=l; c0<=r; c0++) possible[t0][r0][c0] = NO;
        }

        bool ok = false;
        for(int r=1;r<=H;r++) for(int c=1;c<=W;c++){
            if(solve(r, c, 1) == MAYBE){
                ok = true;
            }
        }

        printf("Robbery #%d:\n", ++nt);
        if(not ok) printf("The robber has escaped.\n");
        else{
            ok = false;
            for(int curr_time=1; curr_time<=t; curr_time++){
                int x = 0, y = 0;
                for(int r=1; r<=H; r++) for(int c=1; c<=W; c++){
                    if(possible[curr_time][r][c] == MAYBE){
                        if(x == 0 and y == 0) y = r, x = c;
                        else x = y = -1;
                    }
                }
                if(x != -1 and y != -1){
                    ok = true;
                    printf("Time step %d: The robber has been at %d,%d.\n", curr_time, x, y);
                }
            }
            if(not ok) printf("Nothing known.\n");
        }
        printf("\n");
    }
    return 0;
}