#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N_CHARS_PER_GROUP = 4;
const int N_GROUPS_PER_LINE = 16;
const int MAX_LENGTH = 80;

int N, L, counter;
string curr, ans;

void f(int idx){
    if(idx > MAX_LENGTH+1) return; 
    if(counter >= N) return;
    
    counter++;
    if(counter == N){
        ans = curr;
        return;
    }

    for(int i=0;i<L;i++){
        curr.push_back('A' + i);
        
        // check validity 
        bool isvalid = true;
        for(int len=1;len<=curr.size()/2;len++){
            int start1 = curr.size() - len;
            int end1 = start1 + len - 1;
            int start2 = start1 - len;
            int end2 = start2 + len - 1;
            if(start2 < 0) continue;
            bool equal = true;
            for(int j1=start1,j2=start2;j1<=end1;j1++,j2++){
                if(curr[j1] == curr[j2]) continue;
                else{
                    equal = false;
                    break;
                }
            }
            if(equal){
                isvalid = false;
                break;
            }
        }

        if(not isvalid){
            curr.pop_back();
            continue;
        }
        f(idx+1);
        curr.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> N >> L){
        if(N == 0 and L == 0) break;

        curr = "";
        counter = -1;
        f(0);

        int n_lines = (ans.length() + N_GROUPS_PER_LINE*N_CHARS_PER_GROUP - 1) / (N_GROUPS_PER_LINE * N_CHARS_PER_GROUP);
        for(int i=0;i<n_lines;i++){
            if(i) cout << endl;
            int start = N_GROUPS_PER_LINE*N_CHARS_PER_GROUP*i;
            int end = min(start+N_GROUPS_PER_LINE*N_CHARS_PER_GROUP, (int)ans.length());
            int n_group_this_line = (end-start + N_CHARS_PER_GROUP-1) / N_CHARS_PER_GROUP;
            for(int group=0; group<n_group_this_line; group++){
                if(group) cout << " ";
                int start_group = start + N_CHARS_PER_GROUP * group;
                int end_group = min(start_group + N_CHARS_PER_GROUP, (int)ans.length());
                for(int j=start_group; j<end_group; j++) cout << ans[j];
            }
        }
        cout << endl;
        cout << ans.length() << endl;
    }

    return 0;
}