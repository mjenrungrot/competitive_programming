#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char line[100];
int N,P;
vector <int> V[105];

class unionTree{
	private:
		int P[105],R[105];
	public:
		void init(){
			for(int i=1;i<=N;i++) P[i] = i, R[i] = 1;
		}
		void uu(int u,int v){
			int ru = root(u);
			int rv = root(v);
			if(ru == rv) return ;
			if(R[ru] < R[rv]) P[ru] = rv;
			else if(R[ru] > R[rv]) P[rv] = ru;
			else{
				P[ru] = rv;
				R[rv]++;
			}
		}
		int root(int x){
			if(x == P[x]) return x;
			return P[x] = root(P[x]);
		}

};

bool isSame(int a,int b){
	if(V[a].size() != V[b].size()) return false;
	for(int i=0;i<(int)V[a].size();i++) if(V[a][i] != V[b][i]) return false;
	return true;
}

bool same[105][105];

int main(){
	// freopen("in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&N,&P);
		fgets(line,sizeof line,stdin);

		for(int i=0;i<105;i++) V[i].clear();

		int a,b;
		while(fgets(line,sizeof line,stdin)){
			if(line[0] == '\n') break;
			sscanf(line,"%d %d",&a,&b);
			V[a].push_back(b);
		}
		for(int i=0;i<105;i++){
			sort(V[i].begin(),V[i].end());
			V[i].erase(unique(V[i].begin(),V[i].end()),V[i].end());
		}

		unionTree unionTree;
		unionTree.init();
		memset(same,0,sizeof same);

		int ans = N;
		for(int i=1;i<=N;i++) for(int j=i+1;j<=N;j++) if(isSame(i,j)) same[i][j] = same[j][i] = true;

		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++) for(int k=j+1;k<=N;k++){
				if(same[j][k]){
					if(unionTree.root(j) != unionTree.root(k)) ans--;
					unionTree.uu(j,k);
				}
			}
		}
		printf("%d\n",ans);
		if(T) printf("\n");		
	}
	return 0;
}