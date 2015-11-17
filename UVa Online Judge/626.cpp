#include <cstdio>
#include <cstring>
int A[105][105],N;

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&N) == 1){
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) scanf("%d",&A[i][j]);

		int ans = 0;
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) for(int k=1;k<=N;k++) if(A[i][j] and A[j][k] and A[k][i]){
			if(i == j or i == k or j == k) continue;
			if(i < j and j > k) continue;
			if(i > j and j < k) continue;
			printf("%d %d %d\n",i,j,k);
			ans++;
		}
		printf("total:%d\n\n",ans);
	}

	return 0;
}