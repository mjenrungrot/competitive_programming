#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; 
    cin >> T;
    while(T--){
        int N;
        cin >> N;

        vector <int> V;
        for(int i=1;i<=N;i++){
            int tmp;
            cin >> tmp;
            V.push_back(tmp);
        }

        int sum = 1;
        int ans = N > 1 ? 2 : 1;
        for(int i=1;i<N;i++){
            if(sum + V[i] < V[i+1]){
                sum += V[i];
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}