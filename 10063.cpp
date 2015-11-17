#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

char str[100];
deque <char> D;
int N,len,enter;

void f(int n){
	if(n == N){
		for(int i=0;i<N;i++) printf("%c",D[i]);
		printf("\n");
		return ;
	}

	for(int idx=0;idx<(int)D.size();idx++){
		D.insert(D.begin()+idx,str[n]);
		f(n+1);
		D.erase(D.begin()+idx);
	}
	D.push_back(str[n]);
	f(n+1);
	D.erase(D.end());
}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%s",str) == 1){
		N = strlen(str);
		if(enter) printf("\n");
		enter = true;
		f(0);
	}
	return 0;
}