#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

int N,M;
char line[30];
vector <int> V[200];

int main(){
	// freopen("in","r",stdin);
	int T;
	scanf("%d",&T); 
	fgets(line,sizeof line,stdin);
	while(T--){
		scanf("%d %d",&N,&M);
		fgets(line,sizeof line,stdin);

		for(int i=1;i<=M;i++){
			V[i].clear();
			fgets(line,sizeof line,stdin);

			char *p = strtok(line," \n");
			while(p != NULL){
				int xx = atoi(p);
				V[i].push_back(xx);
				p = strtok(NULL," \n");
			}
		}

		for(int i=0;i<(1<<N);i++){
			for(int j=1;j<=M;j++){
				int val = 0;
				for(int k=0;k<(int)V[j].size();k++){
					if( (1<<(V[j][k]-1))&i ) val = val * 2 + 1;
					else val = val * 2;
				}
				if(val == 0 or val == (1<<(int)V[j].size())-1 ) goto again;
			}
			goto possible;
			again:;
		}

		printf("N");
		continue;

		possible:
		printf("Y");
	}
	return 0;
}