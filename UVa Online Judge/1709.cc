#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double p, a, b, c, d;
int n;

int main(){
    while(scanf("%lf %lf %lf %lf %lf %d", &p, &a, &b, &c, &d, &n) == 6){
        double ans = 0.00;
        double min_val = -1e9;
        double max_val = -1e9;
        double val;

        min_val = max_val = p * (sin(a + b) + cos(c + d) + 2.0);
        for(int i=2;i<=n;i++){
            val = p * (sin(a*(double)i + b) + cos(c*(double)i + d) + 2.0);
            if(val > max_val) max_val = val;
            else if(val < min_val){
                min_val = val;
                ans = max_val - min_val;
            }else{
                ans = max(ans, max_val - val);
            }
        }
        printf("%lf\n", ans);
    }
    return 0;
}