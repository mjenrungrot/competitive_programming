#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N,permu[10];;
string A[8];
char tmp[30];

int main(){
	// freopen("in","r",stdin);
	int T,test = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=N;i++){
			scanf("%s",tmp);
			A[i] = tmp;
			permu[i] = i;
		}

		int ans = 1e9;
		do{
			string now = A[permu[1]];
			for(int i=2;i<=N;i++){
				for(int j=A[permu[i]].length()-1;j+1 >= 0;j--){
					if((int)now.length() < j) continue;

					int L = now.length();
					for(int k=0;k<=j;k++){
						if(now[L-1-j+k] != A[permu[i]][k]) goto fail;
					}

					for(int k=j+1;k<A[permu[i]].length();k++) now += A[permu[i]][k];
					break;

					fail:;
				}
			}
			// for(int i=1;i<=N;i++) printf("[%d]",permu[i]); printf("\n");
			ans = min(ans,(int)now.length());
		}while(next_permutation(permu+1,permu+N+1));
		printf("Case %d: %d\n",++test,ans);
	}
	return 0;
}