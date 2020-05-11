#include <cstdio>
#include <algorithm>
#include <map>
#include <cassert>
#include <cmath>
using namespace std;

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

struct point{
	point(){}
	point(int x,int y):x(x),y(y){}
	int x,y;
}A[2005];
int N;

typedef pair<int,int> ii;
map <ii,int> M;

int main(){
	// freopen("in","r",stdin);
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		A[i] = point(a,b);
	}

	long long all = (long long)N * (long long)(N-1) * (long long)(N-2) / 6LL;
	double v_all = all;
	for(int i=1;i<=N;i++){
		M.clear();
		for(int j=1;j<=N;j++){
			if(i == j) continue;
			int dy = A[j].y - A[i].y;
			int dx = A[j].x - A[i].x;

			int gg = gcd(dy,dx);
			dy /= gg;
			dx /= gg;
			if(dy < 0) dy *= -1, dx *= -1;

			assert(dy >= 0);
			M[ii(dy,dx)]++;
		}

		for(map<ii,int>::iterator it=M.begin();it!=M.end();it++){
			long long x = it->second;
			long long y = (x+1) * (x) * (x-1) / 6LL;
			double yyy = (double)y / (double)(x+1);
			v_all -= yyy;
		}
	}
	printf("%.0lf\n",fabs(v_all));
	return 0;
}