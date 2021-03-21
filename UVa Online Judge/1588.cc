#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
string line1, line2;

int main(){
    while(cin >> line1 >> line2){
        // pos 0 of the first line is at index 0
        int length1 = line1.length();
        int length2 = line2.length();
        int ans = INF;
        for(int offset=-length2-1;offset<=length1;offset++){
            int total_length = max(length1-1, length2+offset-1) - min(0, offset) + 1;
            // line1: [0, length1) = [0, length1-1]
            // line2: [offset, offset+length2) = [offset, offset+length2-1]
            bool valid = true;
            int left = min(0, offset), right = max(length1-1, length2+offset-1);
            for(int i=left;i<=right;i++){
                if(0 <= i and i <= length1-1 and 0 <= i-offset and i-offset <= length2-1){
                    if((line1[i]-'0') + (line2[i-offset]-'0') <= 3) continue;
                    else valid = false;
                }
                if(not valid) break;
            }
            if(valid) ans = min(ans, total_length);
        }
        cout << ans << endl;
    }
    return 0;
}