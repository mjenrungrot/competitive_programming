#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int TL[105][105],TR[105][105],BL[105][105],BR[105][105];
char A[105][105];
int T,R,C,Q;

int main(){
	// freopen("in","r",stdin);
	scanf("%d",&T);
	while(T--){
		memset(A,0,sizeof A);
		memset(TL,0,sizeof TL);
		memset(TR,0,sizeof TR);
		memset(BL,0,sizeof BL);
		memset(BR,0,sizeof BR);

		scanf("%d %d %d",&R,&C,&Q);
		for(int i=1;i<=R;i++) scanf("%s",&A[i][1]);

		for(int i=1;i<=R;i++) for(int j=1;j<=C;j++){
			if(A[i][j] == A[i][j-1] and A[i][j] == A[i-1][j] and A[i][j] == A[i-1][j-1]){
				TL[i][j] = min(TL[i-1][j],TL[i][j-1]);
				TL[i][j] = min(TL[i][j],TL[i-1][j-1]) + 1;
			}else{
				TL[i][j] = 1;
			}
		}
		for(int i=1;i<=R;i++) for(int j=C;j>=1;j--){
			if(A[i][j] == A[i][j+1] and A[i][j] == A[i-1][j] and A[i][j] == A[i-1][j+1]){
				TR[i][j] = min(TR[i-1][j],TR[i][j+1]);
				TR[i][j] = min(TR[i][j],TR[i-1][j+1]) + 1;
			}else{
				TR[i][j] = 1;
			}
		}
		for(int i=R;i>=1;i--) for(int j=1;j<=C;j++){
			if(A[i][j] == A[i][j-1] and A[i][j] == A[i+1][j] and A[i][j] == A[i+1][j-1]){
				BL[i][j] = min(BL[i+1][j],BL[i][j-1]);
				BL[i][j] = min(BL[i][j],BL[i+1][j-1]) + 1;
			}else{
				BL[i][j] = 1;
			}
		}
		for(int i=R;i>=1;i--) for(int j=C;j>=1;j--){
			if(A[i][j] == A[i][j+1] and A[i][j] == A[i+1][j] and A[i][j] == A[i+1][j+1]){
				BR[i][j] = min(BR[i+1][j],BR[i][j+1]);
				BR[i][j] = min(BR[i][j],BR[i+1][j+1]) + 1;
			}else{
				BR[i][j] = 1;
			}
		}

		printf("%d %d %d\n",R,C,Q);
		for(int i=1;i<=Q;i++){
			int rr,cc;
			scanf("%d %d",&rr,&cc);
			rr++; cc++;

			int vv1 = min(TL[rr][cc],TR[rr][cc]);
			int vv2 = min(BL[rr][cc],BR[rr][cc]);
			int vv3 = min(vv1,vv2);
			printf("%d\n",2*vv3-1);
			// printf("[%d][%d][%d][%d]\n",TL[rr][cc],TR[rr][cc],BL[rr][cc],BR[rr][cc]);
		}
	}
	return 0;
}