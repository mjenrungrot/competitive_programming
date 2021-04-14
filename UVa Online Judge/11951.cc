#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n_case = 0;
    cin >> T;
    while(T--){
        int N, M;
        long long K;

        cin >> N >> M >> K;

        vector< vector<long long> > qs(N+1, vector<long long>(M+1));
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++){
            long long tmp;
            cin >> tmp;
            qs[i][j] = qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1] + tmp;
        }

        int best_area = 0;
        long long best_cost = 0;

        int best_possible_area;
        for(int sr=1;sr<=N;sr++){
            best_possible_area = (N-sr+1) * M;
            if(best_possible_area < best_area) continue;

            for(int sc=1;sc<=M;sc++){
                best_possible_area = (N-sr+1) * (M-sc+1);
                if(best_possible_area < best_area) continue;

                for(int er=sr;er<=N;er++){
                    best_possible_area = (er-sr+1) * (M-sc+1);
                    if(best_possible_area < best_area) continue;

                    int left=sc, right=M+1, mid;
                    while(left<right){
                        mid = (left+right)/2;
                        
                        bool check = qs[er][mid] - qs[er][sc-1] - qs[sr-1][mid] + qs[sr-1][sc-1] > K;
                        if(check) right = mid;
                        else left = mid+1;
                    }
                    if(left-1 < sc) continue;
                    left--;

                    int area = (left-sc+1) * (er-sr+1);
                    long long cost = qs[er][left] - qs[er][sc-1] - qs[sr-1][left] + qs[sr-1][sc-1];
                    
                    if((area > best_area) or \
                       (area == best_area and cost < best_cost)){
                        best_area = area;
                        best_cost = cost;
                    }
                }
            }
        }

        cout << "Case #" << ++n_case << ": " << best_area << " " << best_cost << endl;
    }
    return 0;
}