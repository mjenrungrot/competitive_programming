#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, bin_size, n_bins;
bool isValid;
vector <int> nums, used;

void f(int curr_sum, int n_finished_bins, int latest_used){
    if(isValid) return;
    if(n_finished_bins == n_bins){
        isValid = true;
        return ;
    }

    for(int i=latest_used+1; i<N; i++){
        if(used[i]) continue;
        if(nums[i] == nums[i-1] and !used[i-1]) continue;
        if(curr_sum + nums[i] > bin_size) continue;
        
        used[i] = 1;
        if(curr_sum + nums[i] == bin_size){
            f(0, n_finished_bins+1, 0);
        }else{
            f(curr_sum+nums[i], n_finished_bins, i);
        }
        used[i] = 0;

        if(curr_sum == 0) return ; // don't skip. pruning
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> N){
        if(!N) break;

        int sumval = 0;
        int maxval = -1;
        nums.clear();
        for(int i=0;i<N;i++){
            int tmp;
            cin >> tmp;
            sumval += tmp;
            nums.push_back(tmp);
            maxval = max(maxval, tmp);
            used.push_back(0);
        }
        sort(nums.begin(), nums.end(), [](int a, int b){
            return a > b;
        });

        int ans = -1;
        isValid = false;
        for(int i=1;i<=sumval;i++){
            if(sumval % i != 0) continue;
            
            fill(used.begin(), used.end(), 0);
            used[0] = 1;
            n_bins = sumval / i;
            bin_size = i;

            if(nums[0] == bin_size) f(0, 1, 0);
            else f(nums[0], 0, 0);

            if(isValid){
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}