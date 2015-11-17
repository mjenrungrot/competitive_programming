#include <cstdio>
#include <set>
using namespace std;

int N;

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&N) == 1){
		if(not N) break;

		multiset <int> S;
		long long ans = 0LL;
		for(int i=1;i<=N;i++){
			int xx,yy;
			scanf("%d",&xx);
			for(int j=1;j<=xx;j++){
				scanf("%d",&yy);
				S.insert(yy);
			}
			multiset <int>::iterator a,b;
			a = S.begin();
			b = --S.end();
			ans += (*b) - (*a);
			S.erase(S.lower_bound(*a));
			S.erase(S.lower_bound(*b));
		}
		printf("%lld\n",ans);
	}
	return 0;
}