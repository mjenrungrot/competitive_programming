#include <cstdio>
int N,A[10005];

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&N) == 1){
		if(!N) break;
		for(int i=1;i<=N;i++) scanf("%d",&A[i]);

		bool have_non0 = false;
		for(int i=1;i<=N;i++) if(A[i] > 0){
			have_non0 = true;
			break;
		}

		if(not have_non0){
			printf("0\n");
			continue;
		}

		bool space = false;
		for(int i=1;i<=N;i++){	
			if(A[i] > 0){
				if(space) printf(" ");
				space = true;
				printf("%d",A[i]);
			}
		}
		printf("\n");
	}
	return 0;
}