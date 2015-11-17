#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;
const double SNACK = 2.0;

double dist,cap,rate,cost;
int n_city;

double A[100],price[100];

double f(int to,double gas){
	if(to == n_city + 2) return 0.0;

	double vv = A[to] - A[to-1];
	double amount_to_be_used = vv/rate;
	if(gas < amount_to_be_used){
		double to_be_filled = (cap-gas);
		double pp = to_be_filled * price[to-1] / 100.0 + SNACK;
		return pp + f(to+1, cap - amount_to_be_used);		
	}
	if(gas > cap/2.0) return f(to+1, gas - amount_to_be_used);

	double to_be_filled = (cap-gas);
	double pp = to_be_filled * price[to-1] / 100.0 + SNACK;
	return min(pp + f(to+1,cap - amount_to_be_used), f(to+1,gas - amount_to_be_used));
}

int main(){
	// freopen("in","r",stdin);
	int test = 0;
	while(scanf("%lf",&dist) == 1){
		if(dist < 0) break;
		scanf("%lf %lf %lf %d",&cap,&rate,&cost,&n_city);
		A[0] = 0.0;
		for(int i=1;i<=n_city;i++) scanf("%lf %lf",&A[i],&price[i]);
		A[n_city+1] = dist;

		double ans = f(1,cap) + cost;
		printf("Data Set #%d\n",++test);
		printf("minimum cost = $%.2lf\n",ans);
	}
	return 0;
}