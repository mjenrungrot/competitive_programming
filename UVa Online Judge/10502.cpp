#include <cstdio>

const int MAXN = 105;

char T[MAXN][MAXN];
int R,C,A[MAXN][MAXN];
int qs[MAXN][MAXN];

void build(){
	for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) qs[i][j] = qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1] + A[i][j];
}
int sum(int r1,int r2,int c1,int c2){
	return qs[r2][c2] - qs[r1-1][c2] - qs[r2][c1-1] + qs[r1-1][c1-1];
}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&R) == 1){
		if(R == 0) break;
		scanf("%d",&C);
		for(int i=1;i<=R;i++){
			scanf("%s",&T[i][1]);
			for(int j=1;j<=C;j++) A[i][j] = T[i][j] - '0';
		}

		build();

		int ans = 0;
		for(int x1=1;x1<=R;x1++) for(int y1=1;y1<=C;y1++) for(int x2=x1;x2<=R;x2++) for(int y2=y1;y2<=C;y2++){
			if( (x2-x1+1)*(y2-y1+1) == sum( x1,x2,y1,y2 ) ) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}