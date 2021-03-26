#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;
int T, N, M, loc[MAXN], A[MAXN];

struct fenwick{
    int data[MAXN];
    
    void init(){
        memset(data, 0, sizeof(data));
    }

    int query(int x){
        if(x == 0) return 0;
        int sum = 0;
        while(x > 0){
            sum += data[x];
            x -= x & -x;
        }
        return sum;
    }

    void add(int x, int val){
        while(x < MAXN){
            data[x] += val;
            x += x & -x;
        }
    }
};


int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    fenwick fw;
    cin >> T;
    while(T--){
        cin >> N >> M;

        fw.init();
        for(int i=1;i<=N;i++){
            loc[i] = M + i;
            fw.add(loc[i], 1);
        }

        for(int i=M;i>=1;i--){
            cin >> A[i];
            if(i < M) cout << " ";  

            int ans = fw.query(loc[A[i]]);
            fw.add(loc[A[i]], -1);
            loc[A[i]] = i;
            fw.add(loc[A[i]], 1);
            cout << ans-1;
        }
        cout << endl;
    }
    
    return 0;
}