#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
string patterns[10];
vector <string> nums;
bool isValid;

void f(int curr_num, int idx, int mask){
    if(idx == N){
        isValid = true;
        return ;
    }
    if(curr_num < 0) return; 
    for(int i=0;i<nums[idx].length();i++){
        if((mask & (1<<i)) and (nums[idx][i] == 'Y')) return ;
        if(nums[idx][i] == patterns[curr_num][i]) continue;
        if(nums[idx][i] == 'N' and patterns[curr_num][i] == 'Y'){
            mask |= (1<<i);
            continue;
        }
        return ;
    }
    f(curr_num-1, idx+1, mask);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    patterns[0] = "YYYYYYN";
    patterns[1] = "NYYNNNN";
    patterns[2] = "YYNYYNY";
    patterns[3] = "YYYYNNY";
    patterns[4] = "NYYNNYY";
    patterns[5] = "YNYYNYY";
    patterns[6] = "YNYYYYY";
    patterns[7] = "YYYNNNN";
    patterns[8] = "YYYYYYY";
    patterns[9] = "YYYYNYY";


    string tmp;
    while(cin >> N){
        if(N == 0) break;
        nums.clear();
        for(int i=1;i<=N;i++){
            cin >> tmp;
            nums.push_back(tmp);
        }

        isValid = false;
        for(int start=9;start>=0;start--){
            f(start, 0, 0);
            if(isValid){
                break;
            }
        }

        if(isValid) cout << "MATCH" << endl;
        else cout << "MISMATCH" << endl;
    }
    return 0;
}