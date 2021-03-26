#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> nums;

int abs(int x){ return x < 0? -x: x;}

int main(){
    int x;
    while(scanf("%d", &N) == 1){
        nums.clear();
        for(int i=1;i<=N;i++){
            scanf("%d", &x);
            nums.push_back(x);
        }

        sort(nums.begin(), nums.end());
        int ans1 = 0, ans2 = 0;
        for(int i=0, j=1;i<N;i+=2,j+=2){
            ans1 += min(abs(nums[i] - nums[i+1]), 24 - abs(nums[i] - nums[i+1]));
            ans2 += min(abs(nums[j] - nums[(j+1)%N]), 24 - abs(nums[j] - nums[(j+1)%N]));
        }
        printf("%d\n", min(ans1, ans2));
    }
    return 0;
}