#include <bits/stdc++.h>
using namespace std;

const int MAXVAL = 505;
const int INF = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int requirement;
        cin >> requirement;
        requirement /= 10;

        int N;
        cin >> N;
    
        vector <bool> possible(MAXVAL);
        possible[0] = true;

        int ans = INF;
        for(int i=0;i<N;i++){
            int weight;
            cin >> weight;
            weight /= 10;

            for(int j=MAXVAL-1;j>=0;j--){
                if(not possible[j]) continue;
                if(j+weight < MAXVAL){
                    possible[j+weight] = true;
                    if(j+weight >= requirement){
                        ans = min(ans, j+weight);
                    }
                }
            }
        }

        if(ans == INF) cout << "NO SOLUTION" << endl;
        else cout << ans * 10 << endl;
    }

    return 0;
}