#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

double simulate(double L, double K, double T1, double T2, double rainfall_speed){
    double rainfall_amount, time_to_leak, leak_amount, final_amount;
    rainfall_amount = rainfall_speed * T1;
    time_to_leak = L / rainfall_speed;
    leak_amount = max(min((T1 - time_to_leak + T2) * K, rainfall_amount - L), 0.0);
    final_amount = rainfall_amount - leak_amount;
    return final_amount;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        double L, K, T1, T2, H;
        cin >> L >> K >> T1 >> T2 >> H;

        double F1, F2;
        double left=0.001, right=1000000.01, mid, amount;
        while(fabs(left-right) > EPS){
            mid = (left+right)/2.0;
            amount = simulate(L, K, T1, T2, mid);
            if(amount < H) left = mid;
            else           right = mid;
        }
        F1 = left * T1;

        left=0.001, right=1000000.01;
        while(fabs(left-right) > EPS){
            mid = (left+right)/2.0;
            amount = simulate(L, K, T1, T2, mid);
            if(amount <= H) left = mid;
            else            right = mid;
        }
        F2 = left * T1;

        cout << setprecision(8) << F1 << " " << F2 << endl;
    }
    return 0;
}