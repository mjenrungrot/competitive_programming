#include <cstdio>
#include <cassert>
#include <map>
using namespace std;

map <long long,int> pass;

bool found;
int P,N,A[50];
char str[50];
long long vv,ans;
void print(long long x);

bool f(int type,int L,int M,int R){
	int yy = (L<<2) + (M<<1) + (R<<0);
	return ((1<<yy)&type) > 0;
}
long long replace(int pos,long long val){
	long long a,b,c;
	// print(val); 

	if(pos == 0){
		a = (2LL&val) > 0;
		b = (1LL&val) > 0;
		c = ((1LL<<(N-1))&val) > 0;
	}else if(pos == N-1){
		a = (1LL&val) > 0;
		b = ((1LL<<(N-1))&val) > 0;
		c = ((1LL<<(N-2))&val) > 0;
	}else{
		a = ((1LL<<(pos+1))&val) > 0;
		b = ((1LL<<(pos))&val) > 0;
		c = ((1LL<<(pos-1))&val) > 0;
	}
	if(b) val -= (1LL<<pos);
	assert(a <= 1 and b <= 1 and c <= 1 and a >= 0 and b >= 0 and c >= 0);
	assert(((1<<pos)&val) == 0);
	if(f(P,a,b,c)){
		printf("val = %d %lld\n",val);
		val += (long long)(1LL<<pos);
	}
	return val;
}

void g(int tt, long long yy){
	if(found) return ;
	if(tt == 0 and yy == ans){
		found = true;
		return ;
	}
	if(pass.count(yy)) return ;
	if(tt == 0) pass[yy] = true;

	for(int i=0;i<N;i++){
		yy = replace(i,yy);
		if(!pass.count(yy)) g(0,yy);
		if(found) return ;
	}
}

// #include <stack>
// using namespace std;
// stack <long long> S;

// void print(long long v){
// 	for(int i=1;i<=N;i++){
// 		S.push(v%2LL);
// 		v /= 2;
// 	}
// 	for(int i=1;i<=N;i++){
// 		printf("%lld",S.top());
// 		S.pop();
// 	}
// }

int main(){
	freopen("in","r",stdin);
	// freopen("out","w",stdout);
	while(scanf("%d %d",&P,&N) == 2){
		scanf("%s",str);
		vv = 0LL;
		for(int i=0;i<N;i++){
			A[i] = (str[i] == '1');
			vv *= 2LL;
			vv += (long long)A[i];
		}
		ans = vv;

		pass.clear();
		found = false;
		g(1,vv);
		
		if(found) printf("REACHABLE\n");
		else printf("GARDEN OF EDEN\n");
	}
	return 0;
}