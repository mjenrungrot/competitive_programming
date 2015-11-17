#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector <int> V[30];
int N,M;
int pass[30][30],ans;

void f(int p,int u,int len){
	pass[p][u] = pass[u][p] = true;
	ans = max(ans,len);
	// printf("push [%d-%d]\n",p,u);
	for(int i=0;i<(int)V[u].size();i++){
		int v = V[u][i];
		if(v == p) continue;
		if(not pass[u][v]) f(u,v,len+1);
	}
	// printf("pop [%d-%d]\n",p,u);
	pass[p][u] = pass[u][p] = false;
}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d %d",&N,&M) == 2){
		if(N + M == 0) break;
		for(int i=0;i<N;i++) V[i].clear();

		for(int i=1;i<=M;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			V[u].push_back(v);
			V[v].push_back(u);
		}
		ans = 0;
		for(int i=0;i<N;i++){
			memset(pass,0,sizeof pass);
			f(28,i,0);
		}
		printf("%d\n",ans);
	}
	return 0;
}