#include <cstdio>
#include <cmath>

const double EPS = 1e-12;
double v_total,v_0;

int main(){
	// freopen("in","r",stdin);
	while(scanf("%lf %lf",&v_total,&v_0) == 2){
		if(fabs(v_total) < EPS) break;

		bool unique = false;
		double maxval = 0.0;
		int maxidx = 0;
		for(int disc=1;disc<=60000;disc++){
			double v_each = v_total / (double)disc;
			if(v_each < v_0) break;
			if(fabs(v_each - v_0) < EPS) continue;

			double d = 0.3 * sqrt( v_each - v_0 ) * (double)disc;
			if(d-maxval > EPS){
				maxval = d;
				maxidx = disc;
				unique = false;
			}else if(fabs(d-maxval) < EPS){
				unique = true;
			}
		}
		if(not unique) printf("%d\n",maxidx);
		else printf("0\n");
	}
	return 0;
}

