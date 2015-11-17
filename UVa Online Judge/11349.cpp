#include <cstdio>

long long A[105][105];
int N;

int main(){
	// freopen("in","r",stdin);
	int T;
	scanf("%d\n",&T);
	for(int i=1;i<=T;i++){
		scanf("N = %d\n",&N);

		bool negative = false;
		for(int j=1;j<=N;j++) for(int k=1;k<=N;k++){
			scanf("%lld ",&A[j][k]);
			if(A[j][k] < 0) negative = true;
		}
		// for(int j=1;j<=N;j++){
		// 	for(int k=1;k<=N;k++) printf("[%lld]",A[j][k]);
		// 	printf("\n");
		// }

		bool symmetric = true;
		for(int j=1;j<=N;j++) for(int k=1;k<=N;k++) if(A[j][k] != A[N-j+1][N-k+1]) symmetric = false;
		if(!negative and symmetric) printf("Test #%d: Symmetric.\n",i);
		else printf("Test #%d: Non-symmetric.\n",i);
	}
	return 0;
}