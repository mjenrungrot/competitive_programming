#include <bits/stdc++.h>
using namespace std;

int N;
char triangles[105][205];

bool check_down_triangle(int k){
    for(int i=1; i<=N-k+1; i++){
        int max_width_i = 2*(N-i+1)-1;
        int width_triangle = 2*k-1;
        for(int j=1; j<=max_width_i - width_triangle + 1; j+=2){
            for(int ti=i,lv=k; lv>=1; ti++,lv--) for(int tj=j, width=1; width<=2*lv-1; tj++, width++){
                if(triangles[ti][tj] == '#') goto skip;
            }
            return true;
            skip:;
        }
    }
    return false;
}

bool check_up_triangle(int k){
    for(int i=k; i<=N; i++){
        int max_width_i = 2*(N-i+1)-1;
        int width_triangle = 2*k-1;
        for(int j=2; j<=max_width_i - width_triangle + 1; j+=2){
            for(int ti=i, lv=k; lv>=1; ti--, lv--) for(int tj=j+2*(k-lv), width=1; width<=2*lv-1; tj++, width++){
                if(triangles[ti][tj] == '#') goto skip;
            }
            return true;
            skip:;
        }
    }
    return false;
}


int main(){
    int t = 0;
    while(scanf("%d", &N) != EOF){
        if(N == 0) break;
        for(int i=1; i<=N; i++) scanf("%s", &triangles[i][1]);

        int ans = 0;
        for(int i=1;i<=N;i++){
            bool val = check_down_triangle(i) or check_up_triangle(i);
            if(val) ans = max(ans, i);
            else break;
        }
        printf("Triangle #%d\n", ++t);
        printf("The largest triangle area is %d.\n\n", ans * ans);
    }
    return 0;
}