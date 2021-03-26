#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+100;
vector <int> divisors[MAXN];

void precompute(){
    for(int i=1;i<MAXN;i++){
        for(int j=i;j<MAXN;j+=i) divisors[j].push_back(i);
    }
}

int main(){
    int T, N, K;

    ios::sync_with_stdio(false);

    precompute();
    cin >> T;
    while(T--){
        cin >> N >> K;

        long long ans = 0;
        for(int j=0;j<divisors[N].size();j++){
            if(divisors[N][j] % K != 0) ans += divisors[N][j];
        }
        cout << ans << endl;
    }
    return 0;
}