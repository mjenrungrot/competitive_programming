#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXLEN = 15;
int N,A[MAXLEN];
int B[MAXLEN],minlen;
int ans[MAXLEN],test;

void f(int len){
	bool sorted = true;
	for(int i=0;i<N-1;i++) if(B[i] > B[i+1]) sorted = false;
	if(sorted){
		minlen = min(minlen,len);
		ans[len]++;
		return ;
	}
	if(len == minlen) return ;

	for(int i=0;i<N-1;i++){
		if(B[i] > B[i+1]){
			int tmp = B[i];
			B[i] = B[i+1];
			B[i+1] = tmp;
			f(len+1);
			tmp = B[i];
			B[i] = B[i+1];
			B[i+1] = tmp;
		}
	}
}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&N) == 1){
		if(N == 0) break;
		for(int i=0;i<N;i++){
			scanf("%d",&A[i]);
			B[i] = A[i];
		}
		minlen = 11;
		memset(ans,0,sizeof ans);
		f(0);
		printf("There are %d swap maps for input data set %d.\n",minlen > 0 ? ans[minlen] : 0,++test);
	}
	return 0;
}