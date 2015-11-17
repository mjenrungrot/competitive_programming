#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAXN = 1e5+100;
int N,A[MAXN];
int B[MAXN],yy;

int gcd(int a,int b){ return b == 0 ? a : gcd(b,a%b); }
bool check(int val){
	while(val%2 == 0) val /= 2;
	return val == 1;
}

int f(int to){
	if(check(to) == false){
		int ans = 0;
		for(int i=1;i<=N;i++){
			if(B[i] == yy) continue;
			int x = B[i];
			if(x > to){
				while(x > to) x /= 2, ans++;
				if(x != to) return INF;
			}else{
				while(x < to) x *= 2, ans++;
				if(x != to) return INF;
			}
		}
		return ans;
	}
	int ans = 0;
	for(int i=1;i<=N;i++){
		bool test = check(B[i]);
		int vv = B[i];
		if(test){
			while(vv < to) vv *= 2, ans++;
			while(vv > to) vv /= 2, ans++;
		}else{
			while(vv > 1){
				vv /= 2, ans++;
				if(check(vv)) break;
			}
			while(vv > to) vv /= 2, ans++;
			while(vv < to) vv *= 2, ans++;
		}
	}	
	return ans;
}

int main(){
	// freopen("in","r",stdin);
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);
	int xx = 0;
	for(int i=1;i<=N;i++){
		B[i] = A[i];
		xx = max(xx,B[i]);
	}

	int ans = 1e9;
	for(int i=0;i<=18;i++) ans = min(ans,f(1<<i));
	yy = xx;
	int base = 0;
	while(xx > 0){
		for(int j=xx,k=0;j<=yy;j*=2,k++) ans = min(ans,f(j)+k+base);
		xx /= 2;
		base++;
	}
	printf("%d\n",ans);
	return 0;
}