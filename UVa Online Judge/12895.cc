#include <bits/stdc++.h>
using namespace std;

int T;
string line;
long long N, val, curr;

int main(){
    cin >> T;
    while(T--){
        cin >> line;
        int len = line.length();

        val = 0;
        N = 0;
        for(int i=0;i<len;i++){
            N *= 10;
            N += (line[i] - '0');

            curr = (line[i] - '0');
            for(int j=2;j<=len;j++) curr *= (line[i] - '0');
            val += curr;
        }
        printf("%s\n", (val == N) ? "Armstrong" : "Not Armstrong");
    }
    return 0;
}