#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
vector <ii> V[2];

int N;

int f(int start){
	int id[2] = {};
	int ans = 0;
	while(id[start] < (int)V[start].size()){
		ans += V[start][id[start]].second;
		id[start]++;
		start = 1-start;
	}
	return ans;
}

int main(){
	// freopen("in","r",stdin);
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if(x < 0) V[0].push_back(ii(-x,y));
		else V[1].push_back(ii(x,y));
	}
	sort(V[0].begin(),V[0].end());
	sort(V[1].begin(),V[1].end());
	int ans = f(1);
	ans = max(ans,f(0));
	printf("%d\n",ans);
	return 0;
}