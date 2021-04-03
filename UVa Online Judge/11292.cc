#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_heads, n_knights;
    while(cin >> n_heads >> n_knights){
        if(n_heads == 0 and n_knights == 0) break;

        vector<int> heads, knights;
        for(int i=1;i<=n_heads;i++){
            int tmp;
            cin >> tmp;
            heads.push_back(tmp);
        }
        for(int i=1;i<=n_knights;i++){
            int tmp;
            cin >> tmp;
            knights.push_back(tmp);
        }
        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());

        int ans = 0;
        int curr_head = 0;
        int curr_knight = 0;
        bool possible = true;
        while(curr_head < heads.size()){
            while(curr_knight < knights.size() and knights[curr_knight] < heads[curr_head]){
                curr_knight++;
            }

            if(curr_knight < knights.size()){
                ans += knights[curr_knight];
                curr_head++;
                curr_knight++;
            }else{
                possible = false;
                break;
            }
        }
        if(possible) cout << ans << endl;
        else cout << "Loowater is doomed!" << endl;
    }
    return 0;
}