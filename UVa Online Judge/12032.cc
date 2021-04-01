#include <iostream>
#include <vector>
using namespace std;

vector <int> A;

bool simulate(int k){
    int curr_k = k;
    for(int i=1;i<A.size();i++){
        if(A[i] - A[i-1] > curr_k) return false;
        else if(A[i] - A[i-1] == curr_k) curr_k = max(curr_k-1, 0);
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        A.clear();

        int N;
        cin >> N;
        A.push_back(0);
        for(int i=1;i<=N;i++){
            int tmp;
            cin >> tmp;
            A.push_back(tmp);
        }

        int left=1, right=10000005, mid;
        while(left<right){
            mid = (left+right)>>1;
            if(simulate(mid)) right=mid;
            else left=mid+1;
        }
        cout << "Case " << t << ": " << left << endl;
    }
    return 0;
}