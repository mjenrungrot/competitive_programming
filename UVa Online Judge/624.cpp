#include <cstdio>
#include <deque>
using namespace std;

deque <int> D,X;
int N,M,A[30],sum,ans;

void f(int i){
	if(i == M){
		if(N-sum < ans){
			ans = N-sum;
			X = D;
		}
		return;
	}

	if(sum + A[i] <= N){
		sum += A[i];
		D.push_back(A[i]);
		f(i+1);
		sum -= A[i];
		D.pop_back();
	}

	f(i+1);
}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d %d",&N,&M) == 2){
		for(int i=0;i<M;i++) scanf("%d",&A[i]);
		ans = 1e9;
		f(0);
		for(int i=0;i<(int)X.size();i++) printf("%d ",X[i]);
		printf("sum:%d\n",N-ans);
	}
	return 0;
}