#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const int MAXN = 10005;
int N, arr[MAXN], best_length, best_arr[MAXN];

void f(int idx){
    // if(best_length < 1e9) return;
    if(idx >= best_length) return ;

    if(idx <= 1){
        arr[idx] = (idx == 0) ? 1 : 2;
        f(idx + 1);
    } else {
        if(arr[idx-1] > N) return;
        if(arr[idx-1] == N){
            best_length = idx;
            for(int i=0;i<idx;i++) best_arr[i] = arr[i];
            return;
        }
        int estimate = idx + (int)ceil(log2((double) N / (double) arr[idx-1]));
        if(estimate >= best_length) return;

        for(int i=idx-1;i>=0;i--){
            for(int j=idx-1;j>=0;j--){
                arr[idx] = arr[i] + arr[j];
                if(arr[idx] > N) continue;
                if(arr[idx] <= arr[idx-1]) break;
                f(idx+1);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);

    while(cin >> N){
        if(!N) break;
        best_length = 1e9;
        f(0);

        for(int i=0;i<best_length;i++){
            if(i) cout << " ";
            cout << best_arr[i];
        }
        cout << endl;
    }
    return 0;
}