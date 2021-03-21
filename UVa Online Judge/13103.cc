#include <bits/stdc++.h>
using namespace std;

long long n, best_n, candidate;
int k;
int digits[30];

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    while(cin >> n){
        cin >> k;
        for(int i=0;i<k;i++) cin >> digits[i];

        best_n = 0;
        for(int i=0;i<(1<<k);i++){
            int n0 = 0, n1 = 0, curr = i;
            while(curr){
                int id = digits[__builtin_ctz(curr)];
                if((1 << id) & n) n1++;
                else n0++;
                curr -= (curr & -curr);
            }
            candidate = n;
            curr = i;
            for(int j=1;j<=n0;j++){
                int id = digits[__builtin_ctz(curr)];
                candidate &= ~(1 << id);
                curr -= (curr & -curr);
            }
            for(int j=1;j<=n1;j++){
                int id = digits[__builtin_ctz(curr)];
                candidate |= (1 << id);
                curr -= (curr & -curr);
            }
            cout << i << " " << candidate << " [" << n0 << "/" << n1 << "]" << endl;
            if(candidate % 7 == 0)   best_n = max(best_n, candidate);
        }
        cout << best_n << endl;
    }

    return 0;
}