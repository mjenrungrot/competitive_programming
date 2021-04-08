#include <iostream>
#include <bitset>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int P, Q;
        cin >> P >> Q;

        long long ans = 0LL;
        int curr = 0, countP = 0, countQ = 0;
        if(countP+1 <= P){ // ending 1
            ans = 1;
            curr++;
            countP++;
        } 

        if(countQ+1 <= Q){ // ending 01
            countQ++;
            curr++;
        }

        while(countP+2 <= P and countQ+1 <= Q){ // adding [011]01
            ans |= (1LL<<(curr));
            ans |= (1LL<<(curr+1));
            countP+=2;
            countQ++;
            curr += 3;
        }

        if(countP+1 <= P){ // adding starting 1 ==> 1[011]*01
            ans |= (1LL<<curr);
            countP++;
        }

        while(countP+1 <= P){ // suffix 1 ==> 1[011]*011*
            ans <<= 1L;
            ans += 1;
            countP++;
        }

        cout << ans << endl;
    }
    return 0;
}