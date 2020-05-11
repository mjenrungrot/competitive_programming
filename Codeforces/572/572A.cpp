#include <cstdio>

const int MAXN = 100005;
int na,nb,k,m,A[MAXN],B[MAXN];

int main(){
	scanf("%d %d",&na,&nb);
	scanf("%d %d",&k,&m);
	for(int i=1;i<=na;i++) scanf("%d",&A[i]);
	for(int i=1;i<=nb;i++) scanf("%d",&B[i]);
	printf("%s\n",A[k] < B[nb - m + 1] ? "YES" : "NO");
	return 0;
}