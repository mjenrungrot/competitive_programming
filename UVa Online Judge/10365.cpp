#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> factor(int n){
	vector <int> ans;
	for(int i=1;i <= n;i++) if(n%i == 0) ans.push_back(i);
	return ans;
}

int main(){
	// freopen("in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int N;
		scanf("%d",&N);
		vector <int> V = factor(N);
		// for(int i=0;i<(int)V.size();i++) printf("[%d]",V[i]);
		// printf("\n");

		int ans = 1e9;
		for(int i=0;i<(int)V.size();i++) for(int j=i;j<(int)V.size();j++){
			if( N % (V[i] * V[j]) ) continue;
			int k = N / (V[i] * V[j]);
			int area = 2*(V[i]*V[j] + V[j]*k + V[i]*k);
			ans = min(ans,area);
		}
		printf("%d\n",ans);
	}
	return 0;
}