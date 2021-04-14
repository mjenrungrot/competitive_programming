#include <bits/stdc++.h>
using namespace std;

const int MAXLENGTH = 10005;
typedef pair<int,int> ii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int L;
        cin >> L;
        L *= 100;

        vector <bool> reachable(MAXLENGTH);
        vector <int> parent(MAXLENGTH, -1);
        reachable[0] = true;
        parent[0] = 0;

        vector <int> weights, candidates;
        int total_sum = 0, ans = 0;
        vector <int> best_assignments;

        bool possible = true;
        while(true){
            int weight;
            cin >> weight;
            if(weight == 0) break;
            if(not possible) continue;

            weights.push_back(weight);
            total_sum += weight;

            // Update DP
            for(int i=MAXLENGTH-1;i>=0;i--){
                if(not reachable[i]) continue;
                if(i + weight <= L){
                    if(reachable[i+weight]) continue;
                    reachable[i+weight] = true;
                    parent[i+weight] = weights.size()-1;
                    candidates.push_back(i+weight);
                }
            }

            bool check = false;
            for(auto candidate: candidates){
                vector <int> ship1; 
                int curr = candidate;
                while(curr > 0){
                    ship1.push_back(parent[curr]);
                    curr -= weights[parent[curr]];
                }

                int total_sum_ship1 = 0;
                for(auto x: ship1) total_sum_ship1 += weights[x];
                
                int total_sum_ship2 = total_sum - total_sum_ship1;
                
                if(total_sum_ship2 <= L){
                    ans = max(ans, (int)weights.size());
                    best_assignments.resize(ans);
                    fill(best_assignments.begin(), best_assignments.end(), 2);
                    for(auto x: ship1) best_assignments[x] = 1;
                    check = true;
                    break;
                }
            }
            if(not check) possible = false;
        }

        cout << ans << endl;
        for(int i=0;i<best_assignments.size();i++){
            if(best_assignments[i] == 1) cout << "starboard" << endl;
            else cout << "port" << endl;
        }

        if(T) cout << endl;
    }
    return 0;
}