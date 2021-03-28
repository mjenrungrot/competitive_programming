#include <bits/stdc++.h>
using namespace std;

int N, M;
int info[1000][2];
int reliable[30];

int main(){
    ios::sync_with_stdio(false);

    while(cin >> N >> M){
        if(N == 0 and M == 0) break;

        for(int i=1;i<=M;i++){
            cin >> info[i][0] >> info[i][1];
        }

        int ans = 0, curr, counter, curr_idx;
        for(int i=0;i<(1<<N);i++){
            memset(reliable, false, sizeof(reliable));

            curr = i;
            counter = 0;

            while(curr){
                curr_idx = __builtin_ctz(curr);
                reliable[curr_idx] = true;
                curr -= (1 << curr_idx);
                counter++;
            }

            bool check = true;
            for(int j=1;j<=M;j++){
                if(not reliable[info[j][0]-1]) continue;
                if(reliable[info[j][0]-1] and info[j][1] > 0 and reliable[info[j][1]-1]) continue;
                if(reliable[info[j][0]-1] and info[j][1] < 0 and (not reliable[-info[j][1]-1])) continue;
                check = false;
                break;
            }
            if(check) ans = max(ans, counter);
        }
        cout << ans << endl;
    }
    return 0;
}