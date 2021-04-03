#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int B, S, n_case = 0;
    while(cin >> B >> S){
        if(B == 0 and S == 0) break;

        vector <int> bachelors, spinsters, used;
        for(int i=0;i<B;i++){
            int tmp;
            cin >> tmp;
            bachelors.push_back(tmp);
        }
        for(int i=0;i<S;i++){
            int tmp;
            cin >> tmp;
            spinsters.push_back(tmp);
            used.push_back(0);
        }

        sort(bachelors.begin(), bachelors.end());

        if(B <= S) cout << "Case " << ++n_case << ": 0" << endl;
        else cout << "Case " << ++n_case << ": " << B-S << " " << bachelors[0] << endl;
    }
    return 0;
}