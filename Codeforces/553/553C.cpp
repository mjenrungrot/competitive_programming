#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;

typedef pair<int,int> ii;

const int MAXN = 1e5+100;
const int MOD = 1e9+7;

int N,M;
vector <int> V1[MAXN],V0[MAXN];
int deg1[MAXN],deg0[MAXN];
bool notconsidered[MAXN];

int main(){
	scanf("%d %d",&N,&M);
	for(int i=1;i<=M;i++){
		int u,v,d;
		scanf("%d %d %d",&u,&v,&d);
		if(d) deg1[u]++, deg1[v]++, V1[u].push_back(v), V1[v].push_back(u);
		else  deg0[u]++, deg0[v]++, V0[u].push_back(v), V0[v].push_back(v);
	}

	long long ans = 1LL;
	for(int i=1;i<=N;i++){
		if(deg1[i] > 1) notconsidered[i] = true;
		else if(deg1[i] == 1){
			assert((int)V1[i].size() == 1);
			int v = V1[0];

		}
	}
	return 0;
}