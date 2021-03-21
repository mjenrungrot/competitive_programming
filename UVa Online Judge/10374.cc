#include <bits/stdc++.h>
using namespace std;

string line, name;
int T, N, M;
map <string, string> nameToParty;
map <string, int> counter;

int main(){
    getline(cin, line);
    T = atoi(line.c_str());
    getline(cin, line);
    while(T--){
        nameToParty.clear();
        counter.clear();

        getline(cin, line);
        N = atoi(line.c_str());
        for(int i=1;i<=N;i++){
            getline(cin, line);
            name = line;
            getline(cin, line);
            nameToParty[name] = line;
            counter[name] = 0;
        }

        getline(cin, line);
        M = atoi(line.c_str());
        int max_val = -1, val;
        bool tie = false;
        string best_person;
        for(int i=1;i<=M;i++){
            getline(cin, line);
            val = ++counter[line];
            if(val > max_val){
                best_person = line;
                max_val = val;
                tie = false;
            }else if(val == max_val){
                tie = true;
            }
        }
        if(not tie){
            printf("%s\n", nameToParty[best_person].c_str());
        }else{
            printf("tie\n");
        }
        if(T){
            printf("\n");
            getline(cin, line);
        }
    }
    return 0;
}