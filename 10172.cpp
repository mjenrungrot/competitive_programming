#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int N,S,Q,universal_time;
queue <int> qq[105];
stack <int> carrier;

int move(int now){ return now < N ? now + 1 : 1;}
bool done(){ 
	if(!carrier.empty()) return false;
	for(int i=1;i<=N;i++) if(!qq[i].empty()) return false; 
	return true;
}

void run(){
	int now = 1, cap = 0;
	while(true){
		while(!carrier.empty() and (carrier.top() == now or qq[now].size() < Q)){
			if(carrier.top() != now){
				qq[now].push(carrier.top());
			}
			carrier.pop();
			cap -= 1;
			universal_time += 1;
		}
		while(!qq[now].empty() and cap < S){
			carrier.push(qq[now].front());
			qq[now].pop();
			cap += 1;
			universal_time += 1;
		}
		if(done()) break;
		now = move(now);
		universal_time += 2;
	}
}

int main(){
	// freopen("in","r",stdin);
	int T; scanf("%d",&T);
	while(T--){
		
		scanf("%d %d %d",&N,&S,&Q);
		for(int i=1;i<=N;i++){
			while(!qq[i].empty()) qq[i].pop();
			int Qi;
			scanf("%d",&Qi);
			for(int j=1;j<=Qi;j++){
				int xx;
				scanf("%d",&xx);
				qq[i].push(xx);
			}
		}
		universal_time = 0;
		run();
		printf("%d\n",universal_time);
	}
	return 0;
}