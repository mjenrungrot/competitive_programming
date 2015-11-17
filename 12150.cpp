#include <cstdio>
#include <cstring>

int N;
int occupied[1005];

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&N) == 1){
		if(!N) break;
		memset(occupied,0,sizeof occupied);
		
		bool isPossible = true;
		for(int i=1;i<=N;i++){
			int C,P;
			scanf("%d %d",&C,&P);

			if(i+P < 1 or i+P > N){
				isPossible = false;
				continue;
			}
			if(occupied[i+P]){
				isPossible = false;
				continue;
			}
			occupied[i+P] = C;
		}

		if(not isPossible) printf("-1\n");
		else{
			for(int i=1;i<=N;i++){
				if(i > 1) printf(" ");
				printf("%d",occupied[i]);
			}
			printf("\n");
		}
	}
	return 0;
}