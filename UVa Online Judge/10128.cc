#include <bits/stdc++.h>
using namespace std;

long long dp[20][20][20];
int T, N, P, R;

int main(){
    dp[1][1][1] = 1;
    for(int n=2;n<=13;n++) for(int be=1;be<=n;be++) for(int af=1;af<=n;af++){
        dp[n][be][af] = dp[n-1][be-1][af] + dp[n-1][be][af-1] + (n-2) * dp[n-1][be][af];
    }

    cin >> T;
    while(T--){
        cin >> N >> P >> R;
        cout << dp[N][P][R] << endl;
    }
    return 0;
}