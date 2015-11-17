#include <cstdio>
#include <algorithm>
using namespace std;

char str[1005];

int main(){
	// freopen("in","r",stdin);
	int T,test = 0;
	scanf("%d",&T);
	while(T--){
		int N,K;
		scanf("%d %d",&N,&K);
		scanf("%s",str+1);

		int ans = 0;
		for(int i=2;i<=N;i++) for(int j=max(i-K,1);j<i;j++){
			if(str[j] == str[i]){
				ans++;
				break;
			}
		}
		printf("Case %d: %d\n",++test,ans);
	}
	return 0;	
}