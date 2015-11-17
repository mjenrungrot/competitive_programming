#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int A[10][10],N;
int dp[1000],pass[1000];

int f(int bitmask){
	if(bitmask == (1<<N)-1) return 0;
	
	if(pass[bitmask]) return dp[bitmask];
	pass[bitmask] = true;

	int cc = 0;
	for(int i=0;i<N;i++) if((1<<i)&bitmask) cc++;

	int tmp = INF;
	for(int j=0;j<N;j++){
		if((1<<j)&bitmask) continue;
		tmp = min(tmp,A[cc][j] + f(bitmask|(1<<j)));
	}
	return dp[bitmask] = tmp;
}

int main(){
	// freopen("in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(pass,0,sizeof pass);

		scanf("%d",&N);
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) scanf("%d",&A[i][j]);
		int ans = f(0);
		printf("%d\n",ans);
	}
	return 0;
}