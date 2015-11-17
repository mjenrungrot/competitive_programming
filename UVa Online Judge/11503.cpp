#include <cstdio>
#include <map>
#include <string>
using namespace std;

const int MAXN = 1e5+100;
int P[MAXN],R[MAXN],S[MAXN];

int root(int x){
	if(x == P[x]) return x;
	return P[x] = root(P[x]);
}

void link(int x,int y){
	int rx = root(x);
	int ry = root(y);
	if(rx == ry) return ;
	if(R[rx] < R[ry]){
		P[rx] = ry;
		S[ry] += S[rx];
	}else if(R[rx] > R[ry]){
		P[ry] = rx;
		S[rx] += S[ry];
	}else{
		P[rx] = ry;
		R[ry]++;
		S[ry] += S[rx];
	}
}

int findsize(int x){
	int rx = root(x);
	return S[rx];
}

void run(){
	int counter = 0;
	map <string,int> toId;

	int N;
	char str1[50],str2[50];
	string S1,S2;

	scanf("%d",&N);
	for(int i=1;i<=N; i++){
		scanf("%s %s",str1,str2);
		S1 = str1;
		S2 = str2;
		if(!toId.count(S1)){
			toId[S1] = ++counter;
			P[counter] = counter;
			R[counter] = 1;
			S[counter] = 1;
		}
		if(!toId.count(S2)){
			toId[S2] = ++counter;
			P[counter] = counter;
			R[counter] = 1;
			S[counter] = 1;
		}
		link(toId[S1],toId[S2]);
		printf("%d\n",findsize(toId[S1]));
	}
}

int main(){
	// freopen("in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--) run();
	return 0;
}