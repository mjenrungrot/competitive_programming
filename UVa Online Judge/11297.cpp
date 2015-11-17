#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N,M,A[505][505];
int minans = INF, maxans = -INF;
class segment1D{
private:
	int minval[4005],maxval[4005];

public:
	void init(int node,int L,int R,int y){
		if(L < R){
			init(2*node,L,(L+R)/2,y);
			init(2*node+1,(L+R)/2+1,R,y);
			minval[node] = min(minval[2*node],minval[2*node+1]);
			maxval[node] = max(maxval[2*node],maxval[2*node+1]);
		}else{
			minval[node] = A[y][L];
			maxval[node] = A[y][L];
		}
	}
	int findmin(int node,int L,int R,int wantL,int wantR){
		if(wantL > R or wantR < L) return INF;
		if(wantL <= L and R <= wantR) return minval[node];

		int v1 = findmin(2*node,L,(L+R)/2,wantL,wantR);
		int v2 = findmin(2*node+1,(L+R)/2+1,R,wantL,wantR);
		return min(v1,v2);
	}
	int findmax(int node,int L,int R,int wantL,int wantR){
		if(wantL > R or wantR < L) return -INF;
		if(wantL <= L and R <= wantR) return maxval[node];
		int v1 = findmax(2*node,L,(L+R)/2,wantL,wantR);
		int v2 = findmax(2*node+1,(L+R)/2+1,R,wantL,wantR);
		return max(v1,v2);
	}
	void setval(int node,int L,int R,int want,int val){
		if(L == R){
			minval[node] = maxval[node] = val;
			return ;
		}

		if(want <= (L+R)/2) setval(2*node,L,(L+R)/2,want,val);
		else setval(2*node+1,(L+R)/2+1,R,want,val);

		minval[node] = min(minval[2*node],minval[2*node+1]);
		maxval[node] = max(maxval[2*node],maxval[2*node+1]);
	}
}T[505];


int main(){
	// freopen("in","r",stdin);
	int Q;
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++) scanf("%d",&A[j][i]);
	}
	for(int i=1;i<=M;i++) T[i].init(1,1,N,i);

	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		int x1,y1,x2,y2,val;
		char str[5];
		scanf("%s",str);

		if(str[0] == 'q'){
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			minans = INF;
			maxans = -INF;
			for(int j=y1;j<=y2;j++){
				int xx = T[j].findmin(1,1,N,x1,x2);
				minans = min(minans,xx);

				int yy = T[j].findmax(1,1,N,x1,x2);
				maxans = max(maxans,yy);
			}
			printf("%d %d\n",maxans,minans);
		}else{
			scanf("%d %d %d",&x1,&y1,&val);
			T[y1].setval(1,1,N,x1,val);
		}

	}
	return 0;
}