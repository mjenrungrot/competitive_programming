#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

const int MAXN = 2000005;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
int lucky[MAXN], memo[MAXN];
int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    oset nums;
    for(int i=1;i<=MAXN;i+=2) nums.insert(i);
    for(oset::iterator it=++nums.begin();it!=nums.end();it++){
        int nth_remove = *it;
        for(int j=nth_remove-1;j<nums.size();j+=nth_remove-1){
            nums.erase(nums.find_by_order(j));
        }
    }
    for(oset::iterator it=nums.begin();it!=nums.end();it++) lucky[*it] = 1;

    while(cin >> N){
        if(N & 1) cout << N << " is not the sum of two luckies!\n";
        else{
            if(memo[N] == 0){
                memo[N] = -1;
                for(int i=N/2;i>=1;i--) if(lucky[i] and lucky[N-i]){
                    memo[N] = i;
                    break;
                }
            }

            if(memo[N] == -1) cout << N << " is not the sum of two luckies!\n";
            else cout << N << " is the sum of " << memo[N] << " and " << N - memo[N] << ".\n";
        }
    }
    return 0;
}