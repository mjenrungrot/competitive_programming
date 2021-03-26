#include <bits/stdc++.h>
using namespace std;

vector <string> names;
string name;
int N;

int main(){
    while(scanf("%d", &N) == 1){
        if(N == 0) break;
        names.clear();
        names.reserve(N);

        for(int i=1;i<=N;i++){
            cin >> name;
            names.push_back(name);
        }
        sort(names.begin(), names.end());

        assert(N % 2 == 0);
        int n_median = N / 2 - 1; // (n_median-1, n_median)

        int length1 = names[n_median].size(); 
        int length2 = names[n_median+1].size();
        string ans = names[n_median];
        for(int i=0; i<length1; i++){
            if(i < length2 and names[n_median][i] == names[n_median+1][i]){
                continue;
            }else if(names[n_median][i] == 'Z'){
                continue;
            }else if(i == length2 - 1 and i < length2 and names[n_median][i] + 1 == names[n_median+1][i]){
                continue;
            }else if(i < length1 - 1){
                ans[i] += 1;
                ans = ans.substr(0, i+1);
                break;
            }
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}