#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, n_case = 0;
    while(cin >> N){
        if(N == 0) break;

        vector <ii> A(N);
        for(int i=0;i<N;i++){
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            A[i] = ii(tmp1, tmp2);
        }

        sort(A.begin(), A.end(), [](ii x, ii y){
            return x.second > y.second;
        });

        int ans = 0;
        int end_x = 0, end_y = 0;
        for(auto x: A){
            end_x += x.first;
            end_y = end_x + x.second;
            if(end_y > ans){
                ans = end_y;
            }

        }
        cout << "Case " << ++n_case << ": " << ans << endl;
    } 

 
    return 0;
}