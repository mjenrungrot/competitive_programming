#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int BEGINNING = 100;
int N,A[1005];

int pass[1005], pp[1005];

bool cannot[1005];
vector <int> V[1005];

int dfs_pass[1005];

int dfs(int node){
	dfs_pass[node] = 1;
	int maxval = 0;
	for(int i=0;i<V[node].size();i++){
		if(dfs_pass[V[node][i]]) continue;
		maxval = max(maxval, 1 + dfs(V[node][i]));
	}
	return maxval;
}

int evaluate(int start){
	int length = 0;

	int now = start;
	pass[now] = BEGINNING;
	while(pass[A[now]] == false){
		pp[A[now]] = now;
		now = A[now];
		pass[now] = true;
		length++;
	}
	if(A[now] == now){
		assert(false);
		return 0;
	}
	// case 1
	if(pass[A[now]] == BEGINNING){
		return length + 1;
	}

	// case kuy
	if(A[now] == pp[now]){
		memset(cannot ,false , sizeof cannot);
		for(int i=1;i<=N;i++) V[i].clear();
		for(int i=1;i<=N;i++) if(pass[i] != 0) cannot[i] = true;

		cannot[now] = false;
		for(int i=1;i<=N;i++) if(not cannot[i]) V[A[i]].push_back(i);
		memset(dfs_pass, 0, sizeof dfs_pass);
		int ans = dfs(now);

		return ans + length + 1;
	}


	// case 2 ans = 0
	if(A[now] != pp[now]){
		return 0;
	}

	// 
	return -1e9;
}

int run(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);
	int maxval = 0;
	for(int i=1;i<=N;i++){
		memset(pass,0,sizeof pass);
		memset(pp, 0,sizeof pp);
		memset(cannot,0,sizeof cannot);
		maxval = max(maxval, evaluate(i));
	}
	return maxval;
}

int main(){
	freopen("in","r",stdin);
	// freopen("C-small-attempt1.in","r",stdin);
	// freopen("C-small-attempt1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: %d\n",i,run());
	}
	return 0;
}