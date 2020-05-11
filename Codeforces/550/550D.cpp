#include <cstdio>
using namespace std;

int main(){
	// freopen("in","r",stdin);
	int K; scanf("%d",&K);

	if(K == 1) printf("YES\n2 1\n1 2\n");
	else if(K%2 == 0) printf("NO\n");
	else{
		printf("YES\n");
		printf("%d %d\n",2*K+4,(K+2)*K);

		printf("1 2\n");
		for(int i=3;i<=2*K-1;i+=2) printf("1 %d\n",i);
		for(int i=3;i<=2*K-1;i+=2) for(int j=i+2;j<=2*K-1;j+=2){
			if(j - i == 2 and i%4 == 3) continue;
			printf("%d %d\n",i,j);
		}
		for(int i=3;i<=2*K-1;i+=2){
			printf("%d %d\n",i,2*K+1);
			printf("%d %d\n",i,2*K+3);
		}	
		printf("%d %d\n",2*K+1,2*K+3);

		for(int i=4;i<=2*K;i+=2) printf("2 %d\n",i);
		for(int i=4;i<=2*K;i+=2) for(int j=i+2;j<=2*K;j+=2){
			if(j - i == 2 and i%4 == 0) continue;
			printf("%d %d\n",i,j);
		}
		for(int i=4;i<=2*K;i+=2){
			printf("%d %d\n",i,2*K+2);
			printf("%d %d\n",i,2*K+4);
		}	
		printf("%d %d\n",2*K+2,2*K+4);
	}
	return 0;
}