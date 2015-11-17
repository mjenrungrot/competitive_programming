#include <cstdio>

int T = 720;

int main(){
	freopen("in","w",stdout);

	printf("%d\n",T);
	for(int i=1;i<=T;i++){
		printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n%d\n",i);
	}

	return 0;
}