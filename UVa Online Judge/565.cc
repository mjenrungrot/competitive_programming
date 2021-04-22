/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        565.cc
#  Description:     UVa Online Judge - 565
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string tmp;
vector<string> constraints;
string curr = "";
bool done;

void f(int idx) {
    if (done) return;
    if (idx == constraints.size()) {
        done = true;
        string ans = "";
        for (int i = 1; i < curr.size(); i += 2) {
            if (curr[i - 1] == '+') ans.push_back(curr[i]);
        }
        sort(ans.begin(), ans.end());
        cout << "Toppings: " << ans << endl;
        return;
    }

    bool pass, exist;
    for (int i = 1; i < constraints[idx].size() - 1; i += 2) {
        if (constraints[idx][i - 1] == '+') {
            pass = true;
            exist = false;
            for (int j = 1; j < curr.size(); j += 2) {
                if (curr[j - 1] == '-' and curr[j] == constraints[idx][i]) {
                    pass = false;
                    break;
                } else if (curr[j - 1] == '+' and
                           curr[j] == constraints[idx][i]) {
                    exist = true;
                    break;
                }
            }
            if (not pass) continue;

            if (exist)
                f(idx + 1);
            else {
                curr.push_back('+');
                curr.push_back(constraints[idx][i]);
                f(idx + 1);
                curr.pop_back();
                curr.pop_back();
            }
        } else {
            pass = true;
            exist = false;
            for (int j = 1; j < curr.size(); j += 2) {
                if (curr[j - 1] == '+' and curr[j] == constraints[idx][i]) {
                    pass = false;
                    break;
                } else if (curr[j - 1] == '-' and
                           curr[j] == constraints[idx][i]) {
                    exist = true;
                    break;
                }
            }
            if (not pass) continue;

            if (exist)
                f(idx + 1);
            else {
                curr.push_back('-');
                curr.push_back(constraints[idx][i]);
                f(idx + 1);
                curr.pop_back();
                curr.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        bool pass = false;
        constraints.clear();
        while (cin >> tmp) {
            pass = true;
            if (tmp == ".") break;
            constraints.push_back(tmp);
        }
        if (not pass) break;

        done = false;
        f(0);
        if (not done) {
            cout << "No pizza can satisfy these requests." << endl;
        }
    }

    return 0;
}