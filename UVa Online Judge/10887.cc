#include <bits/stdc++.h>
using namespace std;

int M, N;
string tmp, names1[1505], names2[1505];
set <string> S;

int main(){
    int T; 
    getline(cin, tmp);
    sscanf(tmp.c_str(), "%d", &T);
    for(int _i=1;_i<=T;_i++){
        printf("Case %d: ", _i);

        getline(cin, tmp);
        sscanf(tmp.c_str(), "%d %d", &M, &N);

        for(int i=1;i<=M;i++) getline(cin, names1[i]);
        for(int i=1;i<=N;i++) getline(cin, names2[i]);
        
        S.clear();
        for(int i=1;i<=M;i++) for(int j=1;j<=N;j++) S.insert(names1[i] + names2[j]);
        printf("%d\n", S.size());
    }
    return 0;
}