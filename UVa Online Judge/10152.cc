#include <iostream>
#include <vector>
#include <string>
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
        string tmp; 
        cin >> N;
        getline(cin, tmp);

        vector <string> current;
        vector <string> target;
        map <string, int> pos;
        for(int i=0;i<N;i++){
            getline(cin, tmp);
            current.push_back(tmp);
        }
        for(int i=0;i<N;i++){
            getline(cin, tmp);
            target.push_back(tmp);
            pos[tmp] = i;
        }

        int counter = 0;
        vector <int> ans;
        for(int i=N-1;i>=0;i--){
            int dist = pos[current[i]] - i;
            if(dist == counter){
                continue;
            }else{
                counter++;
                ans.push_back(pos[current[i]]);
            }
        }
        sort(ans.begin(), ans.end(), greater<int>());
        for(auto x: ans) cout << target[x] << endl;
        cout << endl;
    }
    return 0;
}