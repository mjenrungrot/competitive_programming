#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<double,double> dd;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int W, v_h;
        int N;
        cin >> W >> v_h >> N;

        vector<dd> pos;
        for(int i=1;i<=N;i++){
            double tmp_x, tmp_y;
            cin >> tmp_x >> tmp_y;
            pos.push_back(dd(tmp_x, tmp_y));
        }

        int S;
        cin >> S;
        
        vector<int> speeds;
        for(int i=1;i<=S;i++){
            int tmp;
            cin >> tmp;
            speeds.push_back(tmp);
        }
        sort(speeds.begin(), speeds.end());

        int left=speeds[0], right=speeds[S-1]+1, mid;
        while(left<right){
            mid = (left+right)/2;

            bool check = true;
            double leftmost = pos[0].first;
            double rightmost = pos[0].first + W;
            for(int i=1;i<N;i++){
                double tt = (double)(pos[i].second - pos[i-1].second) * 1.0 / mid;
                leftmost  -= tt * (double)v_h;
                rightmost += tt * (double)v_h;

                if(leftmost > pos[i].first + W){
                    check = false;
                    break;
                }
                if(rightmost < pos[i].first){
                    check = false;
                    break;
                }

                leftmost = max(leftmost, pos[i].first);
                rightmost = min(rightmost, pos[i].first+W);
            }

            if(check) left = mid+1;
            else      right = mid;
        }
        int valid = left-1;

        int best = -1;
        for(int i=0;i<S;i++){
            if(speeds[i] <= valid){
                best = max(best, speeds[i]);
            }
        }
        if(best == -1) cout << "IMPOSSIBLE" << endl;
        else  cout << best << endl;
    }
    return 0;
}