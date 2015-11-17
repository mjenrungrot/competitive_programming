#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1030;

int qs[MAXN][MAXN];
int sum(int r1,int r2,int c1,int c2){ return qs[r2][c2] - qs[r1-1][c2] - qs[r2][c1-1] + qs[r1-1][c1-1]; }
int sum(int r,int c,int d){ return sum(max(r-d,1),min(r+d,1025),max(c-d,1),min(c+d,1025)); }

int main(){
	// freopen("in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(qs,0,sizeof qs);
		int d,n;
		scanf("%d %d",&d,&n);
		for(int i=1;i<=n;i++){
			int c,r,val;
			scanf("%d %d %d",&c,&r,&val);
			r++;
			c++;
			qs[r][c] += val;
		}
		for(int i=1;i<MAXN;i++) for(int j=1;j<MAXN;j++) qs[i][j] += qs[i][j-1] + qs[i-1][j] - qs[i-1][j-1];

		int rr,cc,val = 0;
		for(int i=1;i<=1025;i++) for(int j=1;j<=1025;j++){
			if(sum(j,i,d) > val){
				val = sum(j,i,d);
				rr = j;
				cc = i;
			}
		}
		printf("%d %d %d\n",cc-1,rr-1,val);
	}
	return 0;
}