#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int M;
        cin >> M;
        M--;

        vector< tuple<int,int> > A, ans;
        while(true){
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            if(tmp1 == 0 and tmp2 == 0) break;
            tmp2--;
            A.push_back(tuple<int,int>(tmp1, tmp2));
        }
        sort(A.begin(), A.end(), [](tuple<int,int> x, tuple<int,int> y){
            if(get<0>(x) != get<0>(y)) return get<0>(x) < get<0>(y);
            return get<1>(y) > get<1>(y);
        });


        int curr_idx = 0;
        int right = 0;
        while(curr_idx < A.size()){
            if(get<1>(A[curr_idx]) < 0){
                curr_idx++;
                continue;
            }

            // greedily find next_idx that can extend
            int next_idx = curr_idx;
            int best = -1e9;
            int best_idx = -1;
            while(next_idx < A.size() and get<0>(A[next_idx]) <= right){
                if(get<1>(A[next_idx]) > best){
                    best = get<1>(A[next_idx]);
                    best_idx = next_idx;
                }
                next_idx++;
            }

            if(best_idx == -1){
                ans.clear();
                break;
            }

            // update the coverage
            right = get<1>(A[best_idx])+1;
            ans.push_back(A[best_idx]);
            if(get<1>(ans.back()) >= M) break;

            curr_idx = next_idx;
        }

        if(ans.size() == 0 or get<0>(ans[0]) > 0 or get<1>(ans.back()) < M){
            cout << "0" << endl;
        }else{
            cout << ans.size() << endl;
            for(int i=0;i<ans.size();i++){
                cout << get<0>(ans[i]) << " " << get<1>(ans[i])+1 << endl;
            }
        }
        if(T) cout << endl;
    }
    return 0;
}