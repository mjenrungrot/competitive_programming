#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,A[30],B[30];
int abs(int x){ return x < 0 ? -x : x;}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&N) == 1){
		memset(B,0,sizeof B);
		for(int i=1;i<=N;i++) scanf("%d",&A[i]);

		int ans = 0;
		for(int i=1;i<=N;i++){
			int xx;
			scanf("%d",&xx);
			for(int j=1;j<=N;j++) if(xx == A[j]){
				for(int k=1;k<j;k++) if(B[A[k]] == 0) ans++;
				break;
			}
			B[xx] = 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}