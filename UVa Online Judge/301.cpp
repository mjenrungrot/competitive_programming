#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int cap,N,M;
int A[100],B[100],nn[100];

int fenwick[100];
void add(int at,int val){ at++; for(int i=at;i<100;i+=i&-i) fenwick[i] += val; }
int ask(int at){ at++; int ans = 0; for(int i=at;i>0;i-=i&-i) ans += fenwick[i]; return ans;}

int f(int now){	
	if(now == M) return 0;

	int v1 = 0, v2 = 0;
	bool possible = true;
	for(int i=A[now];i<B[now];i++){
		if(ask(i) > cap) return -1e9;
		if(ask(i) + nn[now] > cap or i > N) possible = false;
	}
	if(possible){
		add(A[now],nn[now]);
		add(B[now],-nn[now]);
		v1 = (B[now] - A[now]) * nn[now] + f(now+1);
		add(A[now],-nn[now]);
		add(B[now],nn[now]);
	}
	v2 = f(now+1);
	return max(v1,v2);
}

int main(){
	// freopen("in","r",stdin);
	while(scanf("%d %d %d",&cap,&N,&M) == 3){
		if(cap+N+M == 0) break;
		for(int i=0;i<M;i++) scanf("%d %d %d",&A[i],&B[i],&nn[i]);
		memset(fenwick,0,sizeof fenwick);
		int ans = f(0);
		printf("%d\n",ans);
	}
	return 0;
}