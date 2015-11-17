#include <cstdio>
#include <algorithm>
using namespace std;

int N; 
long long A[30];

long long product(int i,int j){
	long long ans = 1LL;
	for(int x=i;x<=j;x++) ans *= A[x];
	return ans;
}

int main(){
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	int test = 0;
	while(scanf("%d",&N) == 1){
		for(int i=1;i<=N;i++) scanf("%lld",&A[i]);

		long long ans = 0;
		for(int i=1;i<=N;i++) for(int j=i;j<=N;j++){
			ans = max(ans,product(i,j));
			// printf("product[%d,%d] = %lld\n",i,j,product(i,j));
		}
		printf("Case #%d: The maximum product is %lld.\n\n",++test,ans);
	}
	return 0;
}