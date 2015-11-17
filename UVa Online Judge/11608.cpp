#include <cstdio>

int S,A[20],B[20];

int main(){
	// freopen("in","r",stdin);
	int test = 0;
	while(scanf("%d",&S) == 1){
		if(S < 0) break;

		int now = S;
		for(int i=1;i<=12;i++) scanf("%d",&A[i]);
		for(int i=1;i<=12;i++) scanf("%d",&B[i]);

		printf("Case %d:\n",++test);
		for(int i=1;i<=12;i++){
			if(now >= B[i]){
				now -= B[i];
				printf("No problem! :D\n");
				now += A[i];
			}else{
				now += A[i];
				printf("No problem. :(\n");
			}
		}
	}
	return 0;
}