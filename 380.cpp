#include <cstdio>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

struct data{
	data(){}
	data(int from,int to,int duration):from(from),to(to),duration(duration){}
	int from,to,duration;
};

const int MAXN = 10005;
vector <struct data> V[MAXN],del[MAXN];
map <int,int> M;
int T,test;

int counter,pass[MAXN];
int f(int x){
	pass[x] = counter;
	
	if(M.count(x)){
		if(pass[M[x]] != counter) return f(M[x]);
		else return 9999;
	}else return x;
}

int main(){
	// freopen("in","r",stdin);
	scanf("%d",&T);
	printf("CALL FORWARDING OUTPUT\n");
	while(T--){
		printf("SYSTEM %d\n",++test);\

		M.clear();
		for(int i=0;i<MAXN;i++){
			V[i].clear();
			del[i].clear();
		}

		int a,b,c,d;
		while(scanf("%d",&a) == 1){
			if(a == 0) break;
			scanf("%d %d %d",&b,&c,&d);
			V[b].push_back(data(a,d,c));
			del[b+c].push_back(data(a,d,c));
		}

		int now1 = 0,now2 = 0;
		while(scanf("%d",&a) == 1){
			if(a == 9000) break;
			scanf("%d",&b);

			while(now2 < a){
				if(not del[now2].empty()){
					for(int i=0;i<(int)del[now2].size();i++){
						map<int,int>::iterator it = M.lower_bound(del[now2][i].from);
						// printf("pop %d %d\n",it->first,it->second);
						assert(M.count(it->first));
						M.erase(it);
					}
				}
				now2++;
			}
			while(now1 <= a){
				if(not V[now1].empty()){
					 for(int i=0;i<(int)V[now1].size();i++){
					 	M[V[now1][i].from] = V[now1][i].to;
					 }
				}
				now1++;
			}

			counter++;
			int x = f(b);
			printf("AT %04d CALL TO %04d RINGS %04d\n",a,b,x);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}