#include <iostream>
#include <string>
using namespace std;

const int LENGTH = 5;
const int N_ROWS = 6;
int K, counter;
string config1[N_ROWS + 2], config2[N_ROWS + 2];
string curr, ans;

void f(int idx){
    if(idx == LENGTH){
        counter++;
        if(counter == K) ans = curr;
        return ;
    }

    bool check1, check2;
    for(int i=0;i<26;i++){
        check1 = check2 = false;
        for(int j=1;j<=N_ROWS;j++) if(config1[j][idx] == 'A'+i){
            check1 = true;
            break;
        }
        for(int j=1;j<=N_ROWS;j++) if(config2[j][idx] == 'A'+i){
            check2 = true;
            break;
        }

        if(check1 and check2){
            curr.push_back('A'+i);
            f(idx+1);
            curr.pop_back();
        }
    }
}

void run(){
    cin >> K;
    for(int i=1;i<=N_ROWS;i++) cin >> config1[i];
    for(int i=1;i<=N_ROWS;i++) cin >> config2[i];

    curr = "";
    counter = 0;
    f(0);

    if(counter < K) cout << "NO" << endl;
    else            cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        run();
    }
    return 0;
}