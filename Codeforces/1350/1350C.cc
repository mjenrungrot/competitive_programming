#include <bits/stdc++.h>
using namespace std;

int N;
long long A[100005], pre[100005], suf[100005];

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%ld", &A[i]);
    
    pre[1] = A[1];
    suf[N] = A[N];
    for(int i=2,j=N-1;i<=N;i++,j--){
        pre[i] = __gcd(pre[i-1], A[i]);
        suf[j] = __gcd(suf[j+1], A[j]);
    }

    long long ans = 1LL;
    for(int i=1;i<=N;i++){
        if(i == 1){
            ans *= suf[2];
        }else if(i == N){
            ans = (ans * pre[N-1]) / __gcd(ans, pre[N-1]);
        }else{
            ans = (ans * __gcd(pre[i-1], suf[i+1])) / __gcd(ans, __gcd(pre[i-1], suf[i+1]));
        }
    }
    printf("%lld\n", ans);
    return 0;
}