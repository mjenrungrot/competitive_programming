#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int H, W;
string TABLE[30];
string S1, S2;

string get_string(){
    int N, R, C;
    char c;
    string out = "";

    cin >> N >> R >> C;
    R--; C--;
    out.push_back(TABLE[R][C]);
    for(int i=1;i<=N;i++){
        cin >> c;
        if(c == 'N') R--;
        else if(c == 'S') R++;
        else if(c == 'E') C++;
        else C--;
        out.push_back(TABLE[R][C]);
    }
    return out;
}

int solve(string A, string B){
    // convert to LIS
    vector <int> tmp[128];
    for(int i=0;i<A.length();i++) tmp[A[i]].push_back(i);

    vector <int> lis;
    lis.push_back(-1);
    for(int i=0;i<B.length();i++){
        int now = B[i];
        for(int i=tmp[now].size()-1;i>=0;i--){
            if(tmp[now][i] > lis.back()){
                lis.push_back(tmp[now][i]);
            }else{
                *lower_bound(lis.begin(), lis.end(), tmp[now][i]) = tmp[now][i];
            }
        }
    }
    return lis.size() - 1;
}

void run(){
    cin >> H >> W;
    for(int i=0;i<H;i++) cin >> TABLE[i];

    S1 = get_string();
    S2 = get_string();

    int dist = S1.length() > S2.length() ? solve(S1, S2) : solve(S2, S1); // optimization
    cout << S1.length() - dist << " " << S2.length() - dist << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case " << i << ": ";
        run();
    }

    return 0;
}