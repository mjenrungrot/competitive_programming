#include <iostream>
using namespace std;

const int INF = 1e9+7;
int N, K, A[10005];
int difficulty;

void f(int L, int R, int curr_diff){
    if(L > R){
        difficulty = curr_diff < difficulty ? curr_diff : difficulty;
        return;
    }
    if(curr_diff > K) return;

    if(A[L] == A[R]){
        f(L+1, R-1, curr_diff);
        return; 
    }

    f(L+1, R, curr_diff+1);
    f(L, R-1, curr_diff+1);
}

void run(){
    cin >> N >> K;
    for(int i=1;i<=N;i++) cin >> A[i];

    difficulty = INF;

    f(1, N, 0);

    if(difficulty == INF) cout << "Too difficult" << endl;
    else if(difficulty == 0)  cout << "Too easy" << endl;
    else cout << difficulty << endl;
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