#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int abs(int x){ return x > 0 ? x : -x;}

char line[1000];
char name[50];
int X[30],Y[30],pos[30];

int main(){
	// freopen("in","r",stdin);
	while(scanf("%s",line) == 1){
		if(line[0] == '#') break;

		vector <string> A;
		string S;

		char *p = strtok(line,":;");
		while(p != NULL){
			A.push_back(S = p);
			p = strtok(NULL,":;");
		}

		map <char,int> M;
		int counter = 0;
		for(int i=0;i<(int)A.size();i++) for(int j=0;j<A[i].length();j++) M[A[i][j]] = 1;
		for(map<char,int>::iterator it=M.begin();it!=M.end();it++){
			it->second = (++counter);
			name[counter] = it->first;
		}

		vector <int> V[30];
		for(int i=0;i<(int)A.size();i+=2){
			int now = M[A[i][0]];
			for(int j=0;j<(int)A[i+1].length();j++){
				int to = M[A[i+1][j]];
				V[now].push_back(to);
				V[to].push_back(now);
			}
		}

		int ans = 1e9;
		for(int i=0;i<counter;i++) X[i] = i+1;
		do{
			for(int i=0;i<counter;i++) pos[M[name[X[i]]]] = i;

			int tmp = 0;
			for(int i=0;i<counter;i++){
				int from = M[name[X[i]]];
				for(int j=0;j<(int)V[from].size();j++){
					int to = V[from][j];
					tmp = max(tmp,abs(i-pos[to]));
				}
			}
			// for(int i=0;i<counter;i++) printf("%c ",name[X[i]]);
			// printf(" [%d]\n",tmp);

			if(tmp < ans){
				ans = tmp;
				for(int i=0;i<counter;i++) Y[i] = X[i];
			}
		}while(next_permutation(X,X+counter));

		for(int i=0;i<counter;i++) printf("%c ",name[Y[i]]);
		printf("-> %d\n",ans);
	}
	return 0;
}