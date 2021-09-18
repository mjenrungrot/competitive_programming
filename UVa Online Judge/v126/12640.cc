/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12640.cc
#  Description:     UVa Online Judge - 12640
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (not cin.eof()) {
        getline(cin, line);
        if (line == "") break;

        istringstream iss(line);
        string token;

        vector<int> xs, qs;
        xs.push_back(0);
        qs.push_back(0);

        while (getline(iss, token, ' ')) {
            int curr = stoi(token);
            xs.push_back(curr);
            qs.push_back(qs.back() + curr);
        }

        int ans = 0;
        int best_qs = 1e9;
        for (int i = 0; i < xs.size(); i++) {
            best_qs = min(best_qs, qs[i]);
            ans = max(ans, qs[i] - best_qs);
        }
        cout << ans << endl;
    }
    return 0;
}