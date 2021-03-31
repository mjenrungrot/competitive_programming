#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long X, Y;
    while(cin >> X >> Y){
        long long left=1LL, right=X*Y+1LL, mid;
        while(left < right){
            mid = (left+right)>>1LL;

            long long dist_X = X * mid;
            long long dist_Y = Y * mid;
            if(dist_Y - dist_X < Y) left = mid+1LL;
            else right = mid;;
        }
        cout << left << endl;
    }
    return 0;
}