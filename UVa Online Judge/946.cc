#include <bits/stdc++.h>
#include <tuple>
using namespace std;

int N;
int base[1000], height[1000];

int main(){
    int x, curr_height;
    while(scanf("%d", &N) != EOF){
        int ans = 0;
        for(int i=1; i<=N; i++){
            scanf("%d", &x);

            curr_height = 0;
            bool check;
            while(true){
                check = true;
                for(int j=1; j<i; j++){
                    if(base[j] < curr_height) continue;
                    if(x < height[j]) continue;
                    curr_height = max(curr_height, base[j] + height[j]);
                }
                for(int k=1; k<i; k++){
                    if(curr_height >= base[k] + height[k]) continue;
                    if(x >= height[k]) continue;
                    if(curr_height + x > base[k] + height[k]){
                        check = false;
                        curr_height = max(curr_height, base[k] + height[k]);
                        break;
                    }
                }
                if(check) break;
            }

            ans = max(ans, x + curr_height);
            base[i] = curr_height;
            height[i] = x;
        }
        printf("%d\n", ans);
    }
    return 0;
}