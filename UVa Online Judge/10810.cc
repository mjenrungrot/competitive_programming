#include <bits/stdc++.h>
using namespace std;

int N;
long long ans;
vector <int> nums;
int tmp[500005];

void merge(int l1, int r1, int l2, int r2){
    int ll = l1, rr = r2;
    int curr = l1;
    while(l1 <= r1 and l2 <= r2){
        if(nums[l1] < nums[l2]){
            tmp[curr] = nums[l1];
            curr++;
            l1++;  
        }else{
            tmp[curr] = nums[l2];
            curr++;
            l2++;
            ans += (r1 - l1 + 1);
        }
    }
    while(l1 <= r1){
        tmp[curr] = nums[l1];
        l1++;
        curr++;
    }
    while(l2 <= r2){
        tmp[curr] = nums[l2];
        l2++;
        curr++;
    }
    for(int i=ll;i<=rr;i++) nums[i] = tmp[i];
}

void merge_sort(int l, int r){
    if(r - l < 1) return ;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m+1, r);
    merge(l, m, m+1, r);
}

int main(){
    int x;
    while(scanf("%d", &N) == 1){
        if(N == 0) break;
        nums.clear();
        nums.reserve(N);
        for(int i=1;i<=N;i++){
            scanf("%d", &x);
            nums.push_back(x);
        }

        ans = 0;
        merge_sort(0, N-1);
        printf("%lld\n", ans);
    }
    return 0;
}