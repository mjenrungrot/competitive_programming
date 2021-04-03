#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, D, R;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> N >> D >> R){
        if(N == 0 and D == 0 and R == 0) break;

        vector <int> mornings, evenings;
        for(int i=0;i<N;i++){
            int tmp;
            cin >> tmp;
            mornings.push_back(tmp);
        }
        for(int i=0;i<N;i++){
            int tmp;
            cin >> tmp;
            evenings.push_back(tmp);
        }

        sort(mornings.begin(), mornings.end());
        sort(evenings.begin(), evenings.end(), [](int a, int b){
            return a > b;
        });

        int ans = 0;
        for(int i=0;i<N;i++){
            if(mornings[i] + evenings[i] > D){
                ans += (mornings[i] + evenings[i] - D) * R;
            }
        }
        cout << ans << endl;
    }
    return 0;
}