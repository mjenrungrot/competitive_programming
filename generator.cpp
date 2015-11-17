#include <cstdio>
#include <ctime>
#include <cstdlib>
int main(){
	freopen("in","w",stdout);
	srand(time(NULL));

	int T = 5;
	printf("%d\n",T);
	for(int i=1;i<=T;i++){
		int N = 10;
		printf("%d\n",N);
		for(int i=1;i<=N;i++) printf("%d ",rand()%10); printf("\n");
		for(int i=1;i<=N;i++) printf("%d ",rand()%10); printf("\n");
	}
	return 0;
}