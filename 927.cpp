#include <cstdio>
#include <cstdlib>

int d,k,n;
long long C[30];

long long f(int x){
	long long ans = C[0];;
	long long base = 1LL;
	for(int i=1;i<=n;i++){
		base *= (long long)x;
		ans += base * C[i];
	}
	return ans;
}

int main(){
	// freopen("in","r",stdin);
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		for(int i=0;i<=n;i++) scanf("%lld",&C[i]);
		scanf("%d %d",&d,&k);

		int xx = 0;
		for(int i=1;i<=k;i++){
			long long maxval = (long long)i * (long long)d;
			for(long long j=1;j<=maxval;j++){
				xx++;
				if(xx == k){
					printf("%lld\n",f(i));
					goto end;
				}
			}
		}
		end:;
	}
	return 0;
}