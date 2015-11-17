#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

int N,K,A[20][20];
int pass[20],to[20];
vector <int> V[20];
bool found = false;

void dfs(int p,int u,int len){
	to[p] = u;
	if(len == K){
		found = true;
		int now = 1;
		printf("(%d",now);
		for(int i=1;i<=K;i++){
			now = to[now];
			printf(",%d",now);
		}
		printf(")\n");
		return ;
	}

	pass[u] = true;
	for(int i=0;i<(int)V[u].size();i++){
		int v = V[u][i];
		if(v == p) continue;
		if(not pass[v]) dfs(u,v,len+1);
	}

	pass[u] = false;
}

int main(){
	// freopen("in","r",stdin);
	bool enter = false;
	while(scanf("%d",&N) == 1){
		if(N == -9999) continue;
		scanf("%d",&K);
		for(int i=1;i<=N;i++) V[i].clear();

		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++){
			scanf("%d",&A[i][j]);
			if(A[i][j]) V[i].push_back(j);
		}

		if(enter) printf("\n");
		enter = true;
		
		found = false;
		memset(pass,0,sizeof pass);
		dfs(0,1,0);
		if(not found) printf("no walk of length %d\n",K);
	}
	return 0;
}