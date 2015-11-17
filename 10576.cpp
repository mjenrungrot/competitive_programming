#include <cstdio>
#include <algorithm>
using namespace std;

long long s,d;

int main(){	
	// freopen("in","r",stdin);
	while(scanf("%lld %lld",&s,&d) == 2){

		long long ans = -1e18;
		for(int i=0;i<(1<<12);i++){
			long long sum = 0LL;
			for(int j=4;j<=11;j++){
				long long tmp = 0LL;
				for(int k=j-4;k<=j;k++) tmp += ((i&(1<<k)) ? s : -d);
				if(tmp >= 0LL) goto impossible;
			}
			for(int j=0;j<=11;j++) sum += ((i&(1<<j)) ? s : -d);
			ans = max(ans,sum);

			impossible:;
		}	
		if(ans > 0) printf("%lld\n",ans);
		else printf("Deficit\n");
	}
	return 0;
}