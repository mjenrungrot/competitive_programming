#include <cstdio>
#include <algorithm>
using namespace std;
int P,N;
int A[105];
int B[105];

int cc(int x){ int ans = 0; for(int i=0;i<P;i++) if(x&(1<<i)) ans++; return ans;}
bool f(int bitmask){
	for(int i=1;i<=N;i++) B[i] = A[i]&bitmask;
	for(int i=1;i<=N-1;i++) for(int j=i+1;j<=N;j++) if(B[i] == B[j]) return false;
	return true;
}

int main(){
	// freopen("in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&P,&N);
		for(int i=1;i<=N;i++){
			A[i] = 0;
			for(int j=0;j<P;j++){
				int xx;
				scanf("%d",&xx);
				A[i] *= 2;
				A[i] += xx;
			}
		}

		int ans = 1e9;
		for(int i=0;i<(1<<P);i++) if(f(i)) ans = min(ans,cc(i));
		printf("%d\n",ans);
	}
	return 0;
}