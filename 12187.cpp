#include <cstdio>
#include <cstring>

const int dify[] = {-1,0,1,0};
const int difx[] = {0,-1,0,1};
int A[105][105],B[105][105];
int N,R,C,K;

int next(int now){
	if(now != N-1) return now+1;
	return 0;
}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d %d %d %d",&N,&R,&C,&K) == 4){
		if(N == 0) break;
		for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) scanf("%d",&A[i][j]);
		for(int i=1;i<=K;i++){
			memset(B,-1,sizeof B);
			for(int j=1;j<=R;j++) for(int k=1;k<=C;k++) for(int m=0;m<4;m++){
				if(j+dify[m] >= 1 and j+dify[m] <= R and k+difx[m] >= 1 and k+difx[m] <= C and A[j+dify[m]][k+difx[m]] == next(A[j][k])){
					B[j+dify[m]][k+difx[m]] = A[j][k];
				}
			}
			for(int j=1;j<=R;j++) for(int k=1;k<=C;k++) if(B[j][k] != -1) A[j][k] = B[j][k];
		}
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++){
				if(j > 1) printf(" ");
				printf("%d",A[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}