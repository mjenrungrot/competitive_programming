#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int T,N,K;
char str[105],tmp[105];
string S;
vector <string> V;

void f(int n,int m){
	if(n == N and m == K){
		tmp[n] = 0;
		V.push_back(S = tmp);
		return ;
	}
	if(n == N) return ;

	// same
	tmp[n] = str[n];
	f(n+1,m);

	// not same
	tmp[n] = 'A';
	f(n+1,m+1);
	tmp[n] = 'C';
	f(n+1,m+1);
	tmp[n] = 'G';
	f(n+1,m+1);
	tmp[n] = 'T';
	f(n+1,m+1);
}

int main(){
	// freopen("in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&N,&K);
		scanf("%s",str);
		
		V.clear();
		f(0,0);
		sort(V.begin(),V.end());
		V.erase(unique(V.begin(),V.end()),V.end());

		printf("%d\n",(int)V.size());
		for(int i=0;i<(int)V.size();i++) printf("%s\n",V[i].c_str());

	}
	return 0;
}