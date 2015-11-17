#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> V[300];
bool found;
int N,pass[300],ans[300],len;
char str[5];

void f(int u){
	if(len == N-1){
		bool possible = false;
		for(int i=0;i<(int)V[u].size();i++) if(V[u][i] == 1){
			possible = true;
			break;
		}
		if(possible){
			found = true;
			for(int i=0;i<=len;i++){
				if(i) printf(" ");
				printf("%d",ans[i]);
			}
			printf(" 1\n");
		}
		return ;
	}

	pass[u] = true;
	for(int i=0;i<(int)V[u].size();i++){
		int v = V[u][i];
		if(not pass[v]){
			len++;
			ans[len] = v;
			f(v);
			if(found) return ;
			len--;
		}
	}
	pass[u] = false;
}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&N) == 1){
		for(int i=0;i<=N;i++) V[i].clear();

		int u,v;
		while(scanf("%s",str) == 1){
			if(str[0] == '%') break;
			u = atoi(str);
			
			scanf("%d",&v);
			V[u].push_back(v);
			V[v].push_back(u);
		}

		// for(int i=1;i<=N;i++) sort(V[i].begin(),V[i].end());
		memset(pass,0,sizeof pass);
		memset(ans,0,sizeof ans);
		len = 0;
		found = false;
		ans[len] = 1;
		f(1);
		if(not found) printf("N\n");
	}
	return 0;	
}