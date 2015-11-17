#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

const int MAXN = 100005;
int N,p[MAXN],q[MAXN];
int skip;

void run(){
	scanf("%d",&N);
	assert(N < 100001);
	for(int i=1;i<=N;i++) scanf("%d",&p[i]);
	for(int i=1;i<=N;i++) scanf("%d",&q[i]);

	skip = 0;
	for(int i=1;i<=N;i=skip){
		int fuel = 0,now = i;
		bool isPossible = true;
		for(int j=1;j<=N;j++){
			fuel += p[now];
			if(fuel < q[now]){
				if(now + 1 <= skip){
					printf("Not possible\n");
					return ;
				}else skip = now + 1;
				isPossible = false;
				break;
			}
			fuel -= q[now];
			now = (now < N) ? (now + 1) : 1;
		}
		// printf("[%d] : %d\n",i,skip);
		if(not isPossible) continue;
		else{
			printf("Possible from station %d\n",i);
			return ;
		}
	}
	printf("Not possible\n");
}

int main(){
	// freopen("in","r",stdin);
	int T; scanf("%d",&T);
	assert(T < 25);
	for(int i=1;i<=T;i++){
		printf("Case %d: ",i);
		run();
	}
	return 0;
}