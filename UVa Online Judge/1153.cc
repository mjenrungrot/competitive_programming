#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N;
        vector <ii> A;

        cin >> N;
        for(int i=0;i<N;i++){
            int tmp_q, tmp_d;
            cin >> tmp_q >> tmp_d;
            A.push_back(ii(tmp_q, tmp_d));
        }
        sort(A.begin(), A.end(), [](ii x, ii y){
            return x.second < y.second;
        });

        auto cmp = [](int x, int y){
            return x < y;
        };
        priority_queue <int, vector<int>, decltype(cmp)> pq(cmp); // max-heap

        int curr_time = 0;
        for(int i=0;i<N;i++){
            curr_time += A[i].first;
            pq.push(A[i].first);

            if(curr_time > A[i].second){
                curr_time -= pq.top();
                pq.pop();
            }
        }
        cout << pq.size() << endl;
        if(T) cout << endl;
    }
    return 0;
}