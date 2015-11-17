#include <cstdio>
#include <vector>
using namespace std;

int check(long long a){
	int cc[20];
	for(int i=0;i<=9;i++) cc[i] = 0;

	while(a){
		cc[a%10]++;
		a /= 10;
	}
	for(int i=0;i<=9;i++) if(cc[i] > 1) return false;
	return true;
}

int main(){
	// freopen("in","r",stdin);
	int T; 
	scanf("%d",&T);
	while(T--){
		long long N;
		scanf("%lld",&N);

		for(long long i=1;N*i < 1e10;i++){
			if(check(i) and check(N*i)){
				printf("%lld / %lld = %lld\n",i*N,i,N);
			}
		}
		if(T) printf("\n");
	}
	return 0;
}
