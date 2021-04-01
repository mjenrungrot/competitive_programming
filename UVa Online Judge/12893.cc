#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        long long N;
        cin >> N;
        cout << __builtin_popcountll(N) << endl;
    }
    return 0;
}