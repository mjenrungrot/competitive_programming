#include <bits/stdc++.h>
using namespace std;

int N, M;
int counter[450];

int main(){
    bool split = false;
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    while(cin >> N >> M){
        if(split) cout << endl;
        split = true;

        memset(counter, 0, sizeof(counter));
        int best = 0;
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++){
            counter[i+j]++;
            best = max(best, counter[i+j]);
        }

        for(int i=1;i<=N+M;i++) if(counter[i] == best){
            cout << i << endl;
        }
    }
    return 0;
}