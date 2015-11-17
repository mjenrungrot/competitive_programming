#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
vector <ii> V;

int N,x;

int main(){
	// freopen("in","r",stdin);
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&x);
		V.push_back(ii(x,i));
	}
	sort(V.begin(),V.end());
	
	int vv=0,v_max=1,xx = 0;
	for(int i=0;i<(int)V.size();i++){
		if(xx and V[i].first == xx){
			vv++;
			v_max = max(v_max,vv);
		}else{
			xx = V[i].first;
			vv = 1;
		}
	}

	int L=0,R,ans=1e9,ansL,ansR;
	xx = 0;
	for(int i=0;i<(int)V.size();i++){
		if(xx and V[i].first == xx){
			vv++;
		}else{
			xx = V[i].first;
			vv = 1;
			L = R = V[i].second;
		}
		
		if(vv == v_max){
			R = V[i].second;
			if(R-L+1 < ans){
				ans = R-L+1;
				ansL = L;
				ansR = R;
			}
		}
	}
	printf("%d %d\n",ansL,ansR);
	return 0;
}
