#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

typedef pair<int,int> ii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;

        vector <ii> A(N);
        for(int i=0;i<N;i++){
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            A[i] = ii(tmp1, tmp2);
        }

        sort(A.begin(), A.end(), [](ii x, ii y){
            if(x.first != y.first) return x.first > y.first;
            return x.second < y.second;
        });

        int ans = 0;
        vector <int> lis;
        lis.push_back(INF);
        for(auto u: A){
            int now = u.second;
            int idx = lower_bound(lis.begin(), lis.end(), now+1) - lis.begin();
            if(idx == lis.size() - 1){
                ans++;
                lis.push_back(INF);
            }
            lis[idx] = now;
        }

        cout << ans << endl;
    }
    return 0;
}