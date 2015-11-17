#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int A[100],N,P;
int ans;

void f(int nn,int vv){
	if(nn > P) return ;

	if(A[nn] == 0){
		A[nn] = vv;
		ans = max(ans,vv);
		f(nn,vv+1);
		return ;
	}

	for(int i=1;i<=nn;i++){
		int vv2 = A[i] + vv;
		int vv3 = (int)sqrt((double)vv2);
		if(vv3 * vv3 == vv2){
			A[i] = vv;
			ans = max(ans,vv);
			f(nn,vv+1);
			return ;
		}
	}
	f(nn+1,vv);
}

int main(){
	// freopen("in","r",stdin);
	scanf("%d",&N);
	while(N--){
		scanf("%d",&P);
		memset(A,0,sizeof A);
		ans = 0;
		f(1,1);
		printf("%d\n",ans);
	}
	return 0;
}