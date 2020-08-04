#include <bits/stdc++.h>
using namespace std;

int N, S[100005];
int dp[100005];

void run(){

    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%d", &S[i]);

    memset(dp, 0, sizeof(dp));
    
    int ans = 1;
    
    dp[1] = 1;
    for(int i=2;i<=N;i++){
        if(S[i] > S[1]){
            dp[i] = 2;
            ans = max(ans, dp[i]);
        }else{
            dp[i] = 1;
        }
    }

    for(int i=2;i<=N;i++){
        for(int j=i+i;j<=N;j+=i){
            if(S[j] > S[i]){
                dp[j] = max(dp[j], dp[i]+1);
                ans = max(ans, dp[j]);
            }
        }
    }
    printf("%d\n", ans);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++) run();
}