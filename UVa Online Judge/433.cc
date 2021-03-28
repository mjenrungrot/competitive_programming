#include <iostream>
#include <string>
using namespace std;

int n_sols, n_digits, already_correct;
string rows[5], curr, ans;
string pattern[10];

char at(int r, int c){
    if(c >= rows[r].length()) return ' ';
    return rows[r][c];
}

string encode(int digit_i){
    string out = "";
    for(int i=1;i<=3;i++){
        for(int j=3*digit_i;j<=3*digit_i+2;j++){
            out.push_back(at(i, j));
        }
        out.push_back('\n');
    }
    return out;
}


void f(int digit_i, int fixed){
    if(already_correct) return;
    if(digit_i == n_digits){
        // check 
        int val = 0;
        for(int i=1,pos=curr.length()-1;pos>=0;pos--,i++){
            val += i * (curr[pos] - '0');
        }
        if(val % 11 == 0){
            // cout << curr << " " << fixed << " " << val << endl;
            if(not fixed) already_correct = true;
            ans = curr;
            n_sols++;
        }

        return ;
    }

    string encoded = encode(digit_i);
    
    for(int i=0;i<10;i++){
        bool pass = true;
        bool fixing = false;
        for(int j=0;j<encoded.length();j++){
            if(encoded[j] == pattern[i][j]) continue;
            else if(encoded[j] == ' '){
                if(fixed){
                    pass = false;
                    break;
                }
                fixing = true;
                continue;
            }else{
                pass = false;
                break;
            }
        }

        if(pass){
            curr.push_back('0' + i);
            f(digit_i+1, fixing | fixed);
            curr.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    pattern[0] = " _ \n| |\n|_|\n";
    pattern[1] = "   \n  |\n  |\n";
    pattern[2] = " _ \n _|\n|_ \n";
    pattern[3] = " _ \n _|\n _|\n";
    pattern[4] = "   \n|_|\n  |\n";
    pattern[5] = " _ \n|_ \n _|\n";
    pattern[6] = " _ \n|_ \n|_|\n";
    pattern[7] = " _ \n  |\n  |\n";
    pattern[8] = " _ \n|_|\n|_|\n";
    pattern[9] = " _ \n|_|\n _|\n";

    int T;
    string tmp;
    cin >> T;
    getline(cin, tmp);

    while(T--){
        for(int i=1;i<=3;i++) getline(cin, rows[i]);

        n_digits = 9;
        n_sols = 0;
        already_correct = false;
        curr = "";
        f(0, 0);

        if(n_sols > 1) cout << "ambiguous" << endl;
        else if(n_sols == 0) cout << "failure" << endl;
        else cout << ans << endl;
    }
    return 0;
}