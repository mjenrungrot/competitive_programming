#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long C;
vector <int> V;

char line[10000];
int f(string SS){
	long long ans = 0, tmp = 1LL;
	for(int i=SS.length()-1;i>=0;i--){
		ans += (long long)(SS[i] - 'a' + 1LL) * tmp;
		tmp *= 32LL;
	}
	return ans;
}

bool conflict(){
	for(int i=0;i<(int)V.size()-1;i++){
		for(int j=i+1;j<(int)V.size();j++){
			if( (C/(long long)V[i])%(long long)N == (C/(long long)V[j])%(long long)N ) return true;
		}
	}
	return false;
}

int main(){
	freopen("in","r",stdin);
	while(fgets(line,sizeof line,stdin)){
		printf("%s",line);
		if(line[strlen(line)-1] != '\n') printf("\n");

		V.clear();
		char *p = strtok(line," \n");
		while(p != NULL){
			string S = p;
			V.push_back(f(S));
			p = strtok(NULL," \n");
		}
		N = (int)V.size();

		// while(conflict()){
		C = V[0];
		for(int i=1;i<(int)V.size();i++) C = min(C,(long long)V[i]);
		// printf("C = %d\n",C);

		while(true){
			if(not conflict()) break;
			for(int j=0;j<(int)V.size()-1;j++) for(int k=j+1;k<(int)V.size();k++){
				if( (C/(long long)V[j])%(long long)N == (C/(long long)V[k])%(long long)N ){
					C = min( ((C/(long long)V[j])+1LL)*(long long)V[j] , ((C/(long long)V[k])+1LL)*(long long)V[k]  );
				}
			}
		}
		printf("%lld\n\n",C);
	}
	return 0;
}