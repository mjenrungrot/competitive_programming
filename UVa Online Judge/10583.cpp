#include <cstdio>
#include <algorithm>
using namespace std;

class unionTree{
	private:
	int R[50005],P[50005],S[50005];
	public:
	void init(int nn){
		for(int i=1;i<=nn;i++) R[i] = 1, P[i] = i, S[i] = 1;
	}
	int root(int x){
		if(x == P[x]) return x;
		return P[x] = root(P[x]);
	}
	void link(int u,int v){
		int pu = root(u);
		int pv = root(v);
		if(pu == pv) return ;
		if(R[pu] < R[pv]) P[pu] = pv, S[pv] += S[pu];
		else if(R[pu] > R[pv]) P[pv] = pu, S[pu] += S[pv];
		else{
			P[pu] = pv;
			R[pv]++;
			S[pv] += S[pu];
		}
	}
	int findsize(int u){
		u = root(u);
		return S[u];
	}
}unionTree;

int N,M;


int main(){
	// freopen("in","r",stdin);
	int test = 0;
	while(scanf("%d %d",&N,&M) == 2){
		if(N == 0 and M == 0) break;
		printf("Case %d: ",++test);

		int ans = N;
		unionTree.init(N);
		for(int i=1;i<=M;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			if(unionTree.root(a) != unionTree.root(b)) ans--;
			unionTree.link(a,b);
		}
		printf("%d\n",ans);
	}
	return 0;
}