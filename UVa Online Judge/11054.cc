#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while(cin >> N){
        if(N == 0) break;

        vector <int> A(N);
        for(int i=0;i<N;i++){
            cin >> A[i];
        }

        long long ans = 0LL, curr = 0LL;
        for(int i=0;i<N;i++){
            curr += A[i];
            ans += abs(curr);
        }
        cout << ans << endl;
    }
    return 0;
}