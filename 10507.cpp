#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int THRESHOLD = 3;

int N,M;
char str[30];

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d %d",&N,&M) == 2){
		set <int> awake;
		vector <int> V[30];

		scanf("%s",str);
		for(int i=0;str[i];i++){
			int xx = str[i] - 'A' + 1;
			awake.insert(xx);
		}

		for(int i=1;i<=M;i++){
			scanf("%s",str);
			int xx = str[0] - 'A' + 1;
			int yy = str[1] - 'A' + 1;
			V[xx].push_back(yy);
			V[yy].push_back(xx);
		}

		bool possible = false;
		for(int i=1;i<=28;i++){
			if((int)awake.size() == N){
				possible = true;
				printf("WAKE UP IN, %d, YEARS\n",i-1);
				break;
			}

			vector <int> to_add;
			for(int j=1;j<=26;j++){
				if(awake.count(j)) continue;

				int cc = 0;
				for(int k=0;k<V[j].size();k++) if(awake.count(V[j][k])) cc++;
				if(cc >= THRESHOLD) to_add.push_back(j);
			}

			for(int j=0;j<to_add.size();j++){
				awake.insert(to_add[j]);
			}
		}
		if(not possible) printf("THIS BRAIN NEVER WAKES UP\n");
	}
	return 0;
}