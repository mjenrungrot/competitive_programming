#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N,xx;
vector <int> V;

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d",&N) == 1){
		V.clear();
		for(int i=1;i<=N;i++){
			scanf("%d",&xx);
			V.push_back(xx);
		}
		sort(V.begin(),V.end());
		if((int)V.size()%2 == 1){
			int a = V[(int)V.size()/2];
			int xx = 0;
			for(int i=0;i<(int)V.size();i++) if(V[i] == a) xx++;
			printf("%d %d %d\n",a,xx,1);
		}else{
			int a = V[(int)V.size()/2-1];
			int b = V[(int)V.size()/2];
			int xx = 0;
			for(int i=0;i<(int)V.size();i++) if(V[i] == a or V[i] == b) xx++;
			printf("%d %d %d\n",a,xx,max(b-a+1,1));
		}
	}
	return 0;
}