#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
vector <ii> V;

int N1,N2;
char T1[20][20],T2[20][20];

void gen(){
	int base_r,base_c;
	for(int i=1;i<=N2;i++) for(int j=1;j<=N2;j++) if(T2[i][j] == '*'){
		base_r = i;
		base_c = j;
		for(int k=base_r;k<=N2;k++) for(int m=1;m<=N2;m++){
			if(T2[k][m] == '*'){
				if(k == base_r and m == base_c) continue;
				V.push_back(ii(k-base_r,m-base_c));
			}
		}
		return ;
	}
}

bool del(int y,int x){
	T1[y][x] = '.';
	for(int i=0;i<V.size();i++){
		int yy = y+V[i].first, xx = x+V[i].second;
		if(T1[yy][xx] != '*') return false;
		T1[yy][xx] = '.';
	}
	return true;
}

int main(){	
	// freopen("in","r",stdin);
	while(scanf("%d %d",&N1,&N2) == 2){
		if(N1 == 0) break;
		for(int i=1;i<=N1;i++) scanf("%s",&T1[i][1]);
		for(int i=1;i<=N2;i++) scanf("%s",&T2[i][1]);
		V.clear();
		gen();

		bool possible = true;
		int success = 0;
		for(int i=1;i<=N1 and success <= 1;i++) for(int j=1;j<=N1 and success <= 1;j++) if(T1[i][j] == '*'){
			possible &= del(i,j);
			success++;
		}
		// for(int i=1;i<=N1;i++) printf("%s\n",&T1[i][1]);
		printf("%d\n",(int)possible);
	}
	return 0;
}