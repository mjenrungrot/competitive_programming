#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
using namespace std;

typedef pair<int,int> ii;
vector <ii> V[10005];
priority_queue <ii> PQ;

int main(){
	// freopen("in","r",stdin);
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c) == 3){
		V[a].push_back(ii(b,c));
		V[c].push_back(ii(0,c));
	}
 	PQ.push(ii(0,10005));
 	int now = 0,nextend = 0;
 	vector <int> ans;
	for(int i=0;i<=10000;i++){
		if(V[i].empty()) continue;
		for(int j=0;j<V[i].size();j++) PQ.push(V[i][j]);
		while(!PQ.empty() and PQ.top().second <= i) PQ.pop();

		assert((int)PQ.size() >= 1);
		if(i == nextend){
			ans.push_back(i);
			ans.push_back(PQ.top().first);
			now = PQ.top().first;
			nextend = PQ.top().second;
		}

		int nextval = PQ.top().first;
		if(nextval > now){
			ans.push_back(i);
			ans.push_back(nextval);
			now = nextval;
			nextend = PQ.top().second;
		}
	}

	for(int i=0;i<(int)ans.size();i++){
		if(i) printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}