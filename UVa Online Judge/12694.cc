#include <bits/stdc++.h>
using namespace std;

int N;
int S[30], F[30];

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        N = 0;
        while(true){
            cin >> S[N] >> F[N];
            if(S[N] == 0 and F[N] == 0) break;
            N++;
        }

        int ans = 0;
        for(int i=0;i<(1<<N);i++){
            int nbits = 0, curr = i;
            int cap[20];
            memset(cap, 0, sizeof(cap));

            bool failed = false;
            while(curr){
                int id = __builtin_ctz(curr);
                for(int j=S[id];j<F[id];j++){
                    if(cap[j]){
                        failed = true;
                        break;
                    }
                    cap[j] = true;
                }
                if(failed) break;
                nbits++;
                curr -= (curr & -curr);
            }
            if(not failed) ans = max(ans, nbits);
        }
        cout << ans << endl;
    }

    return 0;
}