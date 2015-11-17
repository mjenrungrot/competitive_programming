#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int A[100][100],B[100],C[100][100];

int main(){
	// freopen("in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int N,M;
		scanf("%d %d",&N,&M);
		memset(A,0,sizeof A);
		memset(B,0,sizeof B);
		memset(C,0,sizeof C);

		for(int i=1;i<=N;i++) for(int j=1;j<=M;j++){
			scanf("%d",&A[i][j]);
			B[j] += A[i][j];
		}

		for(int i=1;i<=M;i++) if(B[i] > 2 or B[i] <= 1) goto fault;

		for(int i=1;i<=M;i++){
			int aa,bb,idx = 0;
			while(A[idx][i] == 0) idx++;
			aa = idx;

			idx++;
			while(A[idx][i] == 0) idx++;
			bb = idx;

			if(C[aa][bb] == 0) C[aa][bb] = C[bb][aa] = 1;
			else goto fault;
		}
		printf("Yes\n");
		continue;
		fault: printf("No\n");
	}
	return 0;
}