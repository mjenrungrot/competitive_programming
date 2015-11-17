#include <cstdio>
#include <vector>
using namespace std;

vector <int> type;
vector < vector<int> > V;

char str[5];
int N,K;
bool test(int id){
	// less
	for(int i=0;i<K;i++){
		if(type[i] == 0){
			for(int j=0;j<V[i].size();j++) if(V[i][j] == id) return false;		
		}else{
			bool have = false;
			for(int j=0;j<V[i].size();j++) if(V[i][j] == id){
				have = true;
				break;
			}
			if(not have) return false;
		}
	}
	return true;
}

void run(){
	scanf("%d %d",&N,&K);
	V.clear();
	type.clear();
	for(int i=1;i<=K;i++){
		int xx; scanf("%d",&xx);
		vector <int> vv;
		for(int j=1;j<=xx*2;j++){
			int yy; scanf("%d",&yy);
			vv.push_back(yy);
		}
		scanf("%s",str);

		V.push_back(vv);
		if(str[0] == '<') type.push_back(-1);
		else if(str[0] == '=') type.push_back(0);
		else type.push_back(1);
	}

	int n_possible = 0,val_possible = -1;
	for(int i=1;i<=N;i++){
		if(test(i)) n_possible++, val_possible = i;
	}
	if(n_possible == 1) printf("%d\n",val_possible);
	else printf("0\n");
}

int main(){
	// freopen("in","r",stdin);
	int TT; scanf("%d",&TT);
	while(TT--){
		run();
		if(TT) printf("\n");
	}
	return 0;
}