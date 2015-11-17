#include <cstdio>
#include <algorithm>
using namespace std;

int A[10],B[10];
const int OK = (1<<9) - 2;

int f(int now,int L,int M,int R){
	if(now == 9) return 0;
	int pos = OK & (~(L|M|R));
	
	int ans = 1e9;
	for(int i=1;i<=8;i++){
		if((1<<i)&pos){
			int p = (1<<i);
			if(i == A[now]) ans = min(ans,f(now+1,(L|p)<<1,M|p,(R|p)>>1));
			else ans = min(ans,f(now+1,(L|p)<<1,M|p,(R|p)>>1)+1);
		}
	}
	return ans;
}

int main(){
	// freopen("in","r",stdin);
	int test = 0;
	while(scanf("%d",&A[1]) == 1){
		for(int i=2;i<=8;i++) scanf("%d",&A[i]);
		printf("Case %d: %d\n",++test,f(1,0,0,0));
	}
	return 0;
}