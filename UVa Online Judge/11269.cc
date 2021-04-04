#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while(cin >> N){
        vector <ii> A(N);
        for(int i=0;i<N;i++){
            int tmp;
            cin >> tmp;
            A[i] = ii(tmp, 0);
        }
        for(int i=0;i<N;i++){
            int tmp;
            cin >> tmp;
            A[i] = ii(A[i].first, tmp);
        }

        sort(A.begin(), A.end(), [](ii x, ii y){
            int cost_x_first = x.first + max(x.second, y.first) + y.second;
            int cost_y_first = y.first + max(y.second, x.first) + x.second;
            return cost_x_first < cost_y_first;
        });

        int ans = 0;
        int end_x = 0, end_y = 0;
        for(auto x: A){
            end_x += x.first;
            if(end_y <= end_x) end_y = end_x + x.second; // there's a gap
            else end_y += x.second;            
        }
        cout << end_y << endl;
    } 

    return 0;
}