/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13055.cc
#  Description:     UVa Online Judge - 13055
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int N;
string query;

int main() {
    scanf("%d\n", &N);
    stack<string> S;
    for (int i = 1; i <= N; i++) {
        getline(cin, query);

        vector<string> tokens;
        stringstream ss(query);
        string token;
        while (getline(ss, token, ' ')) tokens.push_back(token);

        if (tokens[0] == "Sleep") {
            S.push(tokens[1]);
        } else if (tokens[0] == "Test") {
            if (S.size() > 0)
                printf("%s\n", S.top().c_str());
            else
                printf("Not in a dream\n");
        } else if (tokens[0] == "Kick") {
            if (S.size() > 0) S.pop();
        }
    }
}