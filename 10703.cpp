#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int W,H,N;
int A[600][600];

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d %d %d",&W,&H,&N) == 3){
		if(W+H+N == 0) break;
		memset(A,0,sizeof A);
		for(int i=1;i<=N;i++){
			int x1,y1,x2,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			A[min(y1,y2)][min(x1,x2)]++;
			A[max(y1,y2)+1][min(x1,x2)]--;
			A[min(y1,y2)][max(x1,x2)+1]--;
			A[max(y1,y2)+1][max(x1,x2)+1]++;
		}
		int ans = 0;
		for(int i=1;i<=H;i++) for(int j=1;j<=W;j++){
			A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
			if(A[i][j] == 0) ans++;
		}
		if(!ans) printf("There is no empty spots.\n");
		else if(ans == 1) printf("There is one empty spot.\n");
		else printf("There are %d empty spots.\n",ans);
	}
	return 0;
}