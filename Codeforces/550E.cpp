#include <cstdio>

const int MAXN = 1e5+10;
int N;
int A[MAXN];

void f(){
	if(A[N] == 1){
		printf("NO\n");
		return ;
	}

	if(N == 1 and A[1] == 0){
		printf("YES\n0\n");
		return ;
	}

	if(N == 2 and A[1] == 0 and A[2] == 0){
		printf("NO\n");
		return ;
	}

	if(A[N-1] == 1 and A[N] == 0){
		printf("YES\n");
		printf("%d",A[1]);
		for(int i=1;i<N;i++) printf("->%d",A[i+1]);
		return ;
	}

	bool pass = false;
	int idx = -1;
	for(int i=1;i<=N-2;i++) if(A[i] == 0) pass = true, idx = i;

	if(not pass){
		printf("NO\n");
		return ;
	}else{
		printf("YES\n");
		if(idx == 1){
			printf("(");
		}else{
			printf("%d",A[1]);
			for(int i=2;i<=idx-1;i++) printf("->%d",A[i]);
			printf("->(");
		}
		printf("%d",A[idx]);
		printf("->(%d",A[idx+1]);
		// printf("[%d]",idx+1);
		for(int i=idx+2;i<N;i++) printf("->%d",A[i]);
		printf("))");
		printf("->%d\n",A[N]);
	}
}

int main(){
	// freopen("in","r",stdin);
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);
	f();
	return 0;
}