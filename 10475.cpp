#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <set>
using namespace std;

char str[50];
string in(){
	scanf("%s",str);
	string S = str;
	return S;
}

int cmp_table[20][20];
bool can_cmp[20][20];

int T,test;
int N,P,S,counter;
bool restriction[20][20];
string name[20];
map <string,int> ID; 

vector < vector<int> > V;

int cmp1(int aa,int bb){ return cmp_table[aa][bb];}
int cmp2(vector <int> aa, vector <int> bb){
	for(int i=0;i<S;i++) if(can_cmp[aa[i]][bb[i]]) return cmp_table[aa[i]][bb[i]];
	return 0;
}

void f(int lv,int bitmask){
	if(lv == S){
		vector <int> x;
		for(int i=1;i<=N;i++) if((1<<i)&bitmask) x.push_back(i);
		sort(x.begin(),x.end(),cmp1);
		V.push_back(x);
		return ;
	}
	for(int i=1;i<=N;i++){
		if((1<<i)&bitmask) continue;

		bool possible = true;
		for(int j=1;j<=N;j++) if((1<<j)&bitmask){
			if(restriction[i][j]){
				possible = false;
				break;
			}
			if(can_cmp[i][j] and cmp_table[i][j]){
				possible = false;
				break;
			}
		}
		if(possible) f(lv+1,bitmask|(1<<i));
	}
}

int main(){
	freopen("in","r",stdin);	
	// freopen("out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(restriction,false,sizeof restriction);
		memset(cmp_table,false,sizeof cmp_table);
		memset(can_cmp,false,sizeof can_cmp);
		ID.clear();
		counter = 0;

		scanf("%d %d %d",&N,&P,&S);
		for(int i=1;i<=N;i++) name[i] = in();
		sort(&name[1],&name[N+1]);

		for(int i=1;i<=N;i++){
			ID[name[i]] = ++counter;
			restriction[counter][counter] = true;
			printf("name[%d] = %s\n",counter,name[i].c_str());
		}
		for(int i=1;i<=P;i++){
			int A = ID[in()];
			int B = ID[in()];
			restriction[A][B] = restriction[B][A] = true;
		}
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++){
			if((int)name[i].length() != (int)name[j].length())  cmp_table[i][j] = ((int)name[i].length() > (int)name[j].length()), can_cmp[i][j] = 1;
			else if(name[i] != name[j]) cmp_table[i][j] = (name[i] < name[j]), can_cmp[i][j] = 1;
			else cmp_table[i][j] = 0, can_cmp[i][j] = 0;
			if(can_cmp[i][j] and cmp_table[i][j]) printf("%s > %s\n",name[i].c_str(),name[j].c_str());
		}

		V.clear();
		f(0,0);

		printf("Set %d:\n",++test);
		for(int i=0;i<(int)V.size();i++){
			for(int j=0;j<(int)V[i].size();j++){
				if(j) printf(" ");
				printf("%s",name[V[i][j]].c_str());
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}