#include <bits/stdc++.h>
using namespace std;

int T;
string A;
string S;
const int MOD = 1e9+7;

int main(){
    scanf("%d", &T);
    for(int _i=1;_i<=T;_i++){
        cin >> A;
        int N = A.length();

        S = "";
        int start_i, start_j;
        if(N % 2 == 1){
            S += A[N / 2];
            start_i = N/2 - 1;
            start_j = N/2 + 1;
        }else{
            start_i = N / 2 - 1;
            start_j = N / 2;
        }
        for(int i=start_i, j=start_j; j<=N; i--, j++){
            if(A[i] > A[j]){
                S += A[i];
                S += A[j];
            }else{
                S += A[j];
                S += A[i];
            }
        }

        int ans = 0;
        int factor = 1;
        for(int i=N-1;i>=0;i--){
            ans = (ans + ((S[i] == '1' ? 1 : 0) * factor)) % MOD;
            factor = (factor * 2) % MOD;
        }
        printf("Case #%d: %d\n", _i, ans);
    }
    return 0;
}