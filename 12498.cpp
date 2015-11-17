#include <cstdio>
#include <algorithm>
using namespace std;

char A[70][70];
int R,C,qs[70][70];

int sum(int r,int x,int y){
	return qs[r][y] - qs[r][x-1];
}

int f(int col){
	int ans = 0;
	for(int i=1;i<=R;i++){
		if(A[i][col] == '0') continue;

		if(sum(i,1,col-1) == col-1 and sum(i,col+1,C) == C-col) return 1e9;

		int v_left,v_right;
		if(sum(i,1,col-1) == col-1) v_left = 1e9;
		if(sum(i,col+1,C) == C-col) v_right = 1e9;

		for(int j=col-1;j>=1;j--) if(A[i][j] == '0'){
			v_left = col-j;
			break;
		}
		for(int j=col+1;j<=C;j++) if(A[i][j] == '0'){
			v_right = j-col;
			break;
		}
		ans += min(v_left,v_right);
	}
	return ans;
}

int main(){
	// freopen("in","r",stdin);	
	int T, test = 0;
	scanf("%d",&T);
	while(T--){
		printf("Case %d: ",++test);
		scanf("%d %d",&R,&C);
		for(int i=1;i<=R;i++) scanf("%s",&A[i][1]);
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++) qs[i][j] = qs[i][j-1] + (A[i][j] == '1');
		}

		int ans = 1e9;
		for(int i=1;i<=C;i++) ans = min(ans,f(i));

		if(ans == 1e9) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}