#include <bits/stdc++.h>
using namespace std;

int T, N, Q;
int nums[100005], answer[300];

int main(){
    int x;
    scanf("%d", &T);
    while(T--){
        memset(answer, -1, sizeof(answer));
        scanf("%d %d", &N, &Q);
        for(int i=1;i<=N;i++) scanf("%d", &nums[i]);
        for(int i=1;i<=Q;i++){
            scanf("%d", &x);
            if(answer[x] == -1){
                int maxval = -1e9;
                for(int j=1;j<=N;j++) maxval = max(maxval, x & nums[j]);
                answer[x] = maxval;
            }
            printf("%d\n", answer[x]);
        }
    }
    return 0;
}