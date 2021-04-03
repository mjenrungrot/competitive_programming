#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int,int> ii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int L, G;
    while(cin >> L >> G){
        if(L == 0 and G == 0) break;

        vector <ii> intervals;
        for(int i=0;i<G;i++){
            int tmp_x, tmp_r;
            cin >> tmp_x >> tmp_r;
            intervals.push_back(ii(tmp_x - tmp_r, tmp_x + tmp_r));
        }

        sort(intervals.begin(), intervals.end(), [](ii x, ii y){
            if(x.first != y.first) return x.first < y.first;
            return x.second > y.second;
        });

        int n_used = 0;
        int curr_idx = 0;
        int curr_right = 0;
        bool possible = true;
        while(curr_idx < intervals.size()){
            if(intervals[curr_idx].second <= curr_right){ // fit in the last chosen interval
                curr_idx++;
                continue; 
            }

            if(intervals[curr_idx].first <= curr_right){ // can add this interval without making any space
                int best_val = intervals[curr_idx].second;
                int best_idx = curr_idx;
                int next_idx = curr_idx + 1;
                while(next_idx < intervals.size() and intervals[next_idx].first <= curr_right){
                    if(intervals[next_idx].second > best_val){
                        best_val = intervals[next_idx].second;
                        best_idx = next_idx;
                    }
                    next_idx++;
                }
                
                // choose best_idx
                n_used++;
                curr_right = best_val;
                if(curr_right >= L) break;

                curr_idx = next_idx;
            }else{
                possible = false;
                break;
            }
        }
        if(curr_right < L) possible = false;

        if(possible) cout << G - n_used << endl;
        else cout << -1 << endl;
    }
    return 0;
}