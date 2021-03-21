#include <bits/stdc++.h>
using namespace std;

int N, M;
int calls[10005][5];
int start, duration;

int main(){
    ios::sync_with_stdio(false);
    while(cin >> N >> M){
        if(N == 0 and M == 0) break;

        for(int i=1;i<=N;i++) for(int j=0;j<4;j++) cin >> calls[i][j];
        for(int i=1;i<=M;i++){
            cin >> start >> duration;
            int ans = 0;
            for(int j=1;j<=N;j++){
                int ll = min(start, calls[j][2]);
                int rr = max(start + duration - 1, calls[j][2] + calls[j][3] - 1);

                if(duration + calls[j][3] > rr - ll + 1){
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}