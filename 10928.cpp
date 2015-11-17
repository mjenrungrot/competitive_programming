#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

vector <int> V[1005];
char line[8000];

int main(){
	// freopen("in","r",stdin);
	int T; scanf("%d",&T);
	while(T--){
		int N; scanf("%d",&N);
		fgets(line,sizeof line,stdin);

		int minval = 1e9;
		for(int i=1;i<=N;i++){
			V[i].clear();
			
			fgets(line,sizeof line,stdin);
			char *p = strtok(line," \n");
			while(p != NULL){
				V[i].push_back(atoi(p));
				p = strtok(NULL," \n");
			}
			minval = min(minval,(int)V[i].size());
		}

		bool space = false;
		for(int i=1;i<=N;i++){
			if((int)V[i].size() == minval){
				if(space) printf(" ");
				space = true;
				printf("%d",i);
			}
		}
		printf("\n");

	}
	return 0;
}