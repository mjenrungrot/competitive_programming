#include <cstdio>
#include <set>
using namespace std;

int main(){
	// freopen("in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int N,M;
		scanf("%d %d",&N,&M);
		multiset <int> S;
		int ans = 0;
		for(int i=1;i<=N;i++){
			int xx;
			scanf("%d",&xx);
			S.insert(xx);
		}
		for(int i=1;i<=M;i++){
			int xx;
			scanf("%d",&xx);
			if(S.count(xx)) S.erase(S.lower_bound(xx));
			else ans++;
		}
		printf("%d\n",(int)S.size() + ans);
	}
	return 0;
}