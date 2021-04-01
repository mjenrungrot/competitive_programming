#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

typedef pair<double, double> dd;

const double EPS = 1e-6;

double ff(double r, double k, vector <dd> &A){
    double best = 1e9;
    for(int i=0;i<A.size()-1;i++){
        best = min(best, r/A[i].first + k/A[i].second);
    }

    double our  = r/A.back().first + k/A.back().second;
    return (best - our) * 3600;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string tmp;
    istringstream iss;
    double total;
    int N;
    vector <dd> A;
    while(true){
        getline(cin, tmp);
        if(tmp == "") getline(cin, tmp);
        if(cin.eof()) break;
    
        iss.clear();
        iss.str(tmp);
        iss >> total;

        getline(cin, tmp);
        iss.clear();
        iss.str(tmp);
        iss >> N;

        A.clear();        
        for(int i=1;i<=N;i++){
            getline(cin, tmp);
            iss.clear();
            iss.str(tmp);

            double tmp1, tmp2;
            iss >> tmp1 >> tmp2;
            A.push_back(dd(tmp1, tmp2));
        }

        double left=0.0, right=total, mid1, mid2, diff;
        while(fabs(left-right) > EPS){
            diff = (right - left)/3.0;
            mid1 = left + diff;
            mid2 = left + 2.0 * diff;
            if(ff(mid1, total-mid1, A) > ff(mid2, total-mid2, A)) right = mid2;
            else left = mid1;
        }
        double ans_r = left, ans_k = total-left;
        int ans = round(ff(ans_r, ans_k, A));

        if(ans < 0){
            cout << "The cheater cannot win." << endl;
        }else{
            cout << "The cheater can win by " << ans << " seconds with r = " << \
            fixed << setprecision(2) << ans_r << "km and k = "  << \
            fixed << setprecision(2) << ans_k << "km." << endl;
        }
    }
    return 0;
}