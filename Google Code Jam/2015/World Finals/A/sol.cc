#include <cstdio>
#include <cstring>
int T;
int A[1000005],N;

char ss[1000005];

void run(){
	scanf("%s",ss);
	N = strlen(ss);
	for(int i=1;i<=N;i++) A[i] = ss[i-1] - '0';

	int ans = 0;
	for(int i=1;i<=N;i++) ans = max(ans, calc(1, n, i));
	return ans;
}

int main(){
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: ",i);
		run();
	}
	return 0;
}