#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int f,r,A[20],B[20];

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&f) == 1){
		if(f == 0) break;
		scanf("%d",&r);
		for(int i=1;i<=f;i++) scanf("%d",&A[i]);
		for(int i=1;i<=r;i++) scanf("%d",&B[i]);

		vector <double> V;
		for(int i=1;i<=f;i++) for(int j=1;j<=r;j++) V.push_back((double)B[j]/(double)A[i]);
		sort(V.begin(),V.end()); 

		double ans = -1.0;
		for(int i=1;i<(int)V.size();i++) ans = max(ans,V[i]/V[i-1]);
		printf("%.2lf\n",ans);
	}
	return 0;
}