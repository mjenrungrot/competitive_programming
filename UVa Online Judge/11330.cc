#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;

        vector <int> original(2*N);
        for(int i=0;i<2*N;i++) cin >> original[i];

        vector <int> tmp(original);
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        
        map<int,int> M;
        for(int i=0;i<tmp.size();i++){
            M[tmp[i]] = i;
        }

        vector <int> A(N);
        for(int i=0;i<2*N;i+=2){
            A[M[original[i]]] = M[original[i+1]];
        }
        
        int ans = 0;
        while(true){
            bool sorted = true;
            int pos = -1;
            for(int i=0;i<N;i++){
                if(A[i] != i){
                    sorted = false;
                    pos = i;
                    break;
                }
            }

            if(sorted) break;

            int tmp_pos1, tmp_val1, tmp_pos2, tmp_val2;
            while(A[pos] != pos){ // swap A[pos] and A[A[pos]]
                tmp_pos1 = pos;
                tmp_val1 = A[pos];
                tmp_pos2 = A[pos];
                tmp_val2 = A[tmp_pos2];
                A[tmp_pos1] = tmp_val2;
                A[tmp_pos2] = tmp_val1;
                pos = tmp_pos2;
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}