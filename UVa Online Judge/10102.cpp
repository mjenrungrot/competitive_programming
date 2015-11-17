#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

char A[205][205];
int N;

int abs(int x){ return x < 0 ? -x : x;}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&N) == 1){
		for(int i=1;i<=N;i++) scanf("%s",&A[i][1]);

		int ans = 0;	
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(A[i][j] == '1'){
			int tmp = 1e9;
			for(int x=1;x<=N;x++) for(int y=1;y<=N;y++){
				if(A[x][y] == '3') tmp = min(tmp,abs(x-i) + abs(y-j));
			}
			ans = max(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}