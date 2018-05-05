/*
 * Problem: Ant Stack
 * Link: https://codejam.withgoogle.com/2018/challenges/0000000000007765/dashboard/000000000003e0a8
 * Source: Google Code Jam 2018 1C
 */
#include <cstdio>
#include <vector>
using namespace std;

const long long INF = 1e18;
const int MAXN = 1e5+100;
const int MAXK = 142;

/*
 * dp[i][j] = minimum sum of weights such given W[0..i] to build a stack of j ants.
 */
long long dp[MAXN][MAXK];

void runTest(int testId){
    int N;
    vector <long long> W;
    scanf("%lld",&N);
    for(int i=1;i<=N;i++){
        long long x;
        scanf("%lld", &x);
        W.push_back(x);
    }

    for(int i=0;i<MAXN;i++) for(int j=0;j<MAXK;j++) dp[i][j] = INF;
    
    dp[0][0] = 0;
    for(int i=1;i<=N;i++) dp[i][0] = 0;

    for(int i=1;i<=N;i++){
        for(int j=1;j<MAXK;j++){
            /*
             * dp[i][j] = min{
             *                  dp[i-1][j]               (not putting i-th at the bottom)
             *                  dp[i-1][j-1] + W[i-1]    (putting i-th at the bottom)
             *               }
             */
            dp[i][j] = dp[i-1][j];
            if(dp[i-1][j-1] <= 6*W[i-1]){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + W[i-1]);
            }
        }
    }

    int answer = 0;
    for(int i=1;i<MAXK;i++) if(dp[N][i] != INF) answer = max(answer, i);

    printf("Case #%d: %d\n", testId, answer);
}

int main(){
    int T; scanf("%d", &T);
    for(int i=1;i<=T;i++) runTest(i);
    return 0;
}
