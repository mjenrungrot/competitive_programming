#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_CHAR = 128;

string input, query;
vector <int> pos[MAX_CHAR];
int Q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> input;
    for(int i=0;i<input.length();i++){
        pos[input[i]].push_back(i);
    }

    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> query;

        bool done = false;
        int start, end;
        int curr_index = 0;
        for(int j=0;j<query.length();j++){
            int l = 0, r = pos[query[j]].size(), mid;
            while(l < r){
                mid = (l+r)>>1;
                if(pos[query[j]][mid] >= curr_index) r = mid;
                else l = mid+1;
            }
            if(l == pos[query[j]].size()){
                cout << "Not matched" << endl;
                done = true;
                break;
            }

            if(j == 0) start = pos[query[j]][l]; 
            if(j == query.length() - 1) end = pos[query[j]][l];
            curr_index = pos[query[j]][l]+1;
        }
        if(not done){
            cout << "Matched " << start << " " << end << endl;
        }
    }
    return 0;
}