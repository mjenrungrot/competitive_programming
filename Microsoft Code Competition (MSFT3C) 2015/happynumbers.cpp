#include <cstdio>
#include <cstring>
int N,dp[1000];
const int MAXVAL = 800;

int sumdigit(int xx){
	int ans = 0;
	while(xx > 0){
		int vv = (xx % 10);
		ans += (vv*vv);
		xx /= 10;
	}
	return ans;
}

int main(){
	freopen("Happy-numbers_InputForSubmission_1.txt","r",stdin);
	freopen("Happy-numbers_InputForSubmission_1.out","w",stdout);
	
	while(scanf("%d",&N) == 1){	
		bool happy = false;
		memset(dp,0,sizeof dp);

		int counter = 0,ans ;
		while(true){
			if(N > MAXVAL){
				counter++;
				N = sumdigit(N);
			}else{
				if(dp[N]){
					ans = counter;
					break;
				}if(N == 1){	
					ans = counter;
					happy = true;
					break;
				}
				dp[N] = true;
				N = sumdigit(N);
				counter++;
			}
			// printf("N = %d [%d]\n",N,counter);
		}
		if(happy) printf("happy %d\n",ans);
		else printf("unhappy %d\n",ans);
	}
	return 0;
}