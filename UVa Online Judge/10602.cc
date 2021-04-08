#include <iostream>
#include <string>
#include <vector>
using namespace std;

int prefix(string x, string y){
    int ans = 0;
    for(int i=0;i<min(x.length(), y.length());i++){
        if(x[i] == y[i]){
            ans++;
            continue;
        }
        break;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;

        vector <string> S(N);
        vector <bool> used(N);
        for(int i=0;i<N;i++){
            cin >> S[i];
        }

        int cost = 0, prev_idx = 0;
        vector <string> ans;
        cost = S[0].length();
        used[0] = true;
        ans.push_back(S[0]);
        for(int i=1;i<N;i++){
            int best_val = -1;
            int best_idx = -1;
            for(int j=1;j<N;j++){
                if(used[j]) continue;
                int val = prefix(S[prev_idx], S[j]);
                if(val > best_val){
                    best_val = val;
                    best_idx = j;
                }
            }
            cost += S[best_idx].length() - best_val;
            prev_idx = best_idx;
            used[prev_idx] = true;
            ans.push_back(S[best_idx]);
        }
        cout << cost << endl;
        for(auto x: ans){
            cout << x << endl;
        }
    }
    return 0;
}
