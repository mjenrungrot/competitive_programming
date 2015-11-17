#include <cstdio>
#include <algorithm>
using namespace std;

int N,M,A[30],B[30];

int main(){
	// freopen("in","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d %d",&A[i],&B[i]);
	scanf("%d",&M);
	for(int i=1;i<=M;i++){
		long long v1,v2,sum1 = 0LL,sum2 = 0LL,minval = 1e18;
		scanf("%lld %lld",&v1,&v2);
		
		for(int j=0;j<(1<<N);j++){
			sum1 = sum2 = 0LL;
			for(int k=0;k<N;k++) if(j&(1<<k)) sum1 += A[k], sum2 += B[k];
			if(sum1 * v2 >= v1) minval = min(minval,sum2);
		}
		if(minval == 1e18) printf("Case %d: IMPOSSIBLE\n",i);
		else printf("Case %d: %lld\n",i,minval);
	}
	return 0;
}