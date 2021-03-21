#include <bits/stdc++.h>
using namespace std;

int distL[1000000], distR[1000000];
char line[1000000];
int main(){
    while(scanf("%s", line) != EOF){
        int N = strlen(line);
        int posL = -1e9;
        int posR = 1e9;

        for(int i=0, j=N-1; i<N; i++, j--){
            if(line[i] == 'X') posL = i;
            else distL[i] = posL;

            if(line[j] == 'X') posR = j;
            else distR[j] = posR;
        }

        int ans = 0;
        for(int i=0; i<N; i++){
            if(line[i] == '.'){
                ans = max(ans, min(i - distL[i], distR[i] - i) - 1);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}