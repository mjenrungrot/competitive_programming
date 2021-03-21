#include <bits/stdc++.h>
using namespace std;

int N, canada_idx;
string countries[30];
int medals[30][5];

int main(){
    ios::sync_with_stdio(false);
    while(cin >> N){
        if(N == 0) break;

        // input
        canada_idx = -1;
        for(int i=1;i<=N;i++){
            cin >> countries[i];
            if(countries[i] == "Canada") canada_idx = i;
            for(int j=1;j<=3;j++) cin >> medals[i][j];
        }

        // log score = -G j log n - S k log n - B l log n
        //           = (-log n)(G j + S k + B l)
        //           \propto (G j + S k + B l)
        int max_index, max_score, score, pass = false;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                for(int k=1;k<=N;k++){
                    max_index = -1;
                    max_score = -1;
                    for(int id=1;id<=N;id++){
                        score = i * medals[id][1] + j * medals[id][2] + k * medals[id][3];
                        if(score > max_score){
                            max_score = score;
                            max_index = id;
                        }
                    }
                    if(max_index == canada_idx){
                        pass = true;
                        break;
                    }
                }
                if(pass) break;
            }
            if(pass) break;
        }
        if(not pass) cout << "Canada cannot win." << endl;
        else cout << "Canada wins!" << endl;
    }
    return 0;
}