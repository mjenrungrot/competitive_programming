/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10776.cc
#  Description:     UVa Online Judge - 10776
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

string S;
int N, length;
set<string> answers;

void f(int idx, string answer) {
    if (answer.length() > N) return;
    if (idx == length) {
        if (answer.length() != N) return;
        answers.insert(answer);
        return;
    }
    int next_idx = idx + 1;
    while (next_idx < length and S[next_idx] == S[idx]) next_idx++;
    f(next_idx, answer);
    for (int i = 1; i <= next_idx - idx; i++) {
        f(next_idx, answer + string(i, S[idx]));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    while (cin >> S >> N) {
        length = S.length();
        sort(S.begin(), S.end());
        answers.clear();
        f(0, "");
        for (auto answer : answers) {
            cout << answer << endl;
        }
    }
    return 0;
}