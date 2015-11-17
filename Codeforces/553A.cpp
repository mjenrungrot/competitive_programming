#include <cstdio>

const int MOD = 1e9 + 7;
const int MAXN = 1005;
int N,A[MAXN],qs[MAXN];
long long r[MAXN];

int main(){
	// freopen("in","r",stdin);
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);
		qs[i] = qs[i-1] + A[i];
	}

	long long ans = 1LL;
	for(int i=1;i<=N;i++){
		for(int j=qs[i-1]+1;j<qs[i];j++){
			ans *= (long long)j;
			ans %= MOD;
		}
	}
	r[1] = 1;
	for(int i=2;i<=1000;i++) r[i] = (MOD - (MOD/i) * r[MOD%i] % MOD) % MOD;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=A[i]-1;j++){
			ans *= r[j];
			ans %= MOD;
		}
	}
	printf("%lld\n",ans);
	return 0;
}