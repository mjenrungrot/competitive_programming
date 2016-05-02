#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

string A[20],B[20];
int N;

int dp[1<<20];

int f(int bitmask){
	if(bitmask == (1<<N)-1){
		return 0;
	}

	if(dp[bitmask] != -1){
		return dp[bitmask];
	}

	int ans = 0;
	for(int i=0;i<N;i++){
		if(bitmask&(1<<i)) continue;

		bool addOne = false;
		bool addTwo = false;
		for(int j=0;j<N;j++){
			if(i == j) continue;
			if(bitmask&(1<<j)){
				if(A[j] == A[i]) addOne = true;
				if(B[j] == B[i]) addTwo = true;
			}
		}

		if(addOne and addTwo){
			ans = max(ans, 1 + f(bitmask|(1<<i)));
		}else{
			ans = max(ans, f(bitmask|(1<<i)));
		}
	}
	return dp[bitmask] = ans;
}

void run(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) cin >> A[i] >> B[i];

	memset(dp,-1,sizeof dp);
	printf("%d\n",f(0));
}

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);

	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: ",i);
		run();
	}
	return 0;
}