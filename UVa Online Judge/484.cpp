#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main(){
	// freopen("in","r",stdin);
	int xx;
	vector <int> V;
	map <int,int> M;
	while(scanf("%d",&xx) == 1){
		V.push_back(xx);
		M[xx]++;
	}
	for(int i=0;i<(int)V.size();i++){
		if(M.count(V[i])){
			printf("%d %d\n",V[i],M[V[i]]);
			M.erase(V[i]);
		}
	}
	return 0;
}