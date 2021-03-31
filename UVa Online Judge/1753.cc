#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

double EPS = 1e-9;

int N;
double T;
vector <double> D, S;

double compute_total_time(double c){
    double total_time = 0.0;
    for(int i=0;i<N;i++){
        double true_speed = S[i] + c;
        if(true_speed == 0.0) true_speed += EPS;
        total_time += D[i] / true_speed;
    }
    return total_time; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> N >> T){
        D.clear();
        S.clear();

        double minval = 1e9;
        for(int i=1;i<=N;i++){
            double tmp_d, tmp_s;
            cin >> tmp_d >> tmp_s;
            D.push_back(tmp_d);
            S.push_back(tmp_s);
            minval = min(minval, tmp_s);
        }

        double left=-minval, right=2000001.0, mid;
        while(fabs(right-left) > EPS){
            mid = (left+right)/2.0;
            if(compute_total_time(mid) < T) right = mid;
            else left = mid;
        }

        cout << setprecision(10) << left << endl;
    }
    return 0;
}