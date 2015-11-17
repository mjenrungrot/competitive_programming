#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXW = 200005;
const long long MOD = (long long)1e9 + 7;
const int MAXN = 2005;

struct point{
	point(){}
	point(int r,int c):r(r),c(c){}
	int r,c;

	bool operator < (struct point x) const{
		if(r != x.r) return r < x.r;
		return c < x.c;
	}

}A[MAXN];

long long fact[MAXW],inverse_mod[MAXW],inverse_fact[MAXW];
int H,W,N;

long long bigmod(long long base,long long expo){
	if(expo == 0) return 1LL;
	if(expo&1) return (base * bigmod(base,expo-1))%MOD;
	else{
		long long ans = bigmod(base,expo/2);
		return (ans*ans)%MOD;
	}
}

void gen(){
	fact[0] = 1LL;
	for(int i=1;i<MAXW;i++){
		fact[i] = fact[i-1] * (long long)i;
		fact[i] %= MOD;
	}

	inverse_fact[0] = 1;
	for(int i=1;i<MAXW;i++){
		inverse_mod[i] = bigmod(i,MOD-2);
		inverse_fact[i] = inverse_fact[i-1] * inverse_mod[i];
		inverse_fact[i] %= MOD;
	}
}

long long nCr(int n,int r){
	long long ans = fact[n];
	ans *= inverse_fact[r];
	ans %= MOD;
	ans *= inverse_fact[n-r];
	ans %= MOD;
	return ans;
}
long long way(int W,int H){ 	return nCr(W+H,H); }
long long dp[MAXN];
int pass[MAXW],counter;

int main(){
	// freopen("in","r",stdin);
	gen();
	scanf("%d %d %d",&H,&W,&N);
	for(int i=1;i<=N;i++){
		int rr,cc;
		scanf("%d %d",&rr,&cc);
		A[i] = point(rr,cc);
	}
	A[++N] = point(H,W);
	sort(&A[1],&A[N+1]);

	for(int i=1;i<=N;i++){
		++counter;
		dp[i] = way(A[i].r-1,A[i].c-1);
		for(int j=i-1;j>=1;j--){
			if(A[j].c > A[i].c) continue;
			int r = A[j].r;
			int c = A[j].c;
			dp[i] -= dp[j] * way(A[i].c - c, A[i].r - r);
			dp[i] = ((dp[i]%MOD)+MOD)%MOD;
		}
	}
	printf("%lld\n",dp[N]%MOD);
	return 0;
}