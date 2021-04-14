#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        
        vector<int> A(N), qs(N);
        for(int i=1;i<N;i++){
            cin >> A[i];
            qs[i] = qs[i-1] + A[i];
        }

        int best = -1e9;
        int best_left, best_right;
        
        int min_sum = 0, min_idx = 0;
        for(int i=1;i<N;i++){
            if((qs[i] - min_sum > best) or \
               (qs[i] - min_sum == best and i - min_idx > best_right - best_left) or \
               (qs[i] - min_sum == best and i - min_idx == best_right - best_left and i < best_right)){
                best = qs[i] - min_sum;
                best_right = i+1;
                best_left = min_idx+1;
            }

            if(qs[i] < min_sum){
                min_sum = qs[i];
                min_idx = i;
            }
        }
        if(best < 0) cout << "Route " << ++n_test << " has no nice parts" << endl;
        else{
            cout << "The nicest part of route " << ++n_test << " is between stops ";
            cout << best_left << " and " << best_right << endl;
        }
    }
    return 0;
}