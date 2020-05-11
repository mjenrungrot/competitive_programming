#include <cstdio>

int N,A[200005];

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);

	bool have1 = false;
	for(int i=1;i<=N;i++) if(A[i] == 1) have1 = true; // there is at least one 1 in A[].

	if(have1) printf("-1\n");
	else printf("1\n");
	return 0;
}