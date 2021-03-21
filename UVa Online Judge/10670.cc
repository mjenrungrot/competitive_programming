
#include <bits/stdc++.h>
using namespace std;

int memo[100005];

void run(){
    int N, M, L, cost1, cost2, total_cost;
    string line, name, token;
    cin >> N >> M >> L;
    cin.get();

    vector< tuple<int,string> > ans;
    for(int i=1;i<=L;i++){
        getline(cin, line);
        stringstream ss(line);

        getline(ss, name, ':');
        getline(ss, token, ',');
        cost1 = atoi(token.c_str());
        getline(ss, token, '\n');
        cost2 = atoi(token.c_str());

        for(int j=N;j>=M;j--) memo[j] = 1e9+7;
        memo[N] = 0;
        for(int j=N;j>=M;j--){
            memo[j/2] = min(memo[j/2], memo[j] + cost2);
            memo[j-1] = min(memo[j-1], memo[j] + cost1);
        }

        total_cost = memo[M];
        ans.push_back(make_tuple(total_cost, name));
    }
    sort(ans.begin(), ans.end(), [](tuple<int,string> a, tuple<int,string> b){
        if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) < get<1>(b);
    });

    for(int i=0;i<ans.size();i++){
        cout << get<1>(ans[i]) << " " << get<0>(ans[i]) << endl;
    }
}

int main(){
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case " << i << endl;
        run();
    }
    return 0;
}