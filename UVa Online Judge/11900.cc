#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_case = 0;
    cin >> T;
    while(T--){
        int N, P, Q;
        cin >> N >> P >> Q;

        int curr_sum = 0, curr_num = 0;
        for(int i=1;i<=N;i++){
            int tmp;
            cin >> tmp;
            if(curr_sum + tmp <= Q and curr_num + 1 <= P){
                curr_sum += tmp;
                curr_num += 1;
            }
        }
        cout << "Case " << ++n_case << ": " << curr_num << endl;
    } 

 
    return 0;
}