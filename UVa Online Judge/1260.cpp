#include <cstdio>

int N,A[1005];

int main(){
	// freopen("in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=N;i++) scanf("%d",&A[i]);
		int ans = 0;
		for(int i=2;i<=N;i++) for(int j=1;j<i;j++) if(A[i] >= A[j]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}