#include <cstdio>

const int MAXN = 1e4+100;
int A[MAXN];

int main(){
	// freopen("in","r",stdin);
	int N; while(scanf("%d",&N) == 1){
		if(!N) break;
		for(int i=1;i<=N;i++) scanf("%d",&A[i]);
		A[0] = A[N];
		A[N+1] = A[1];

		int ans = 0;
		for(int i=1;i<=N;i++){
			if(A[i] > A[i-1] and A[i] > A[i+1]) ans++;
			else if(A[i] < A[i-1] and A[i] < A[i+1]) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}