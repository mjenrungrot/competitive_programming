/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10475.cc
#  Description:     UVa Online Judge - 10475
=============================================================================*/
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int N, P, S;
vector<string> names;
map<string, int> name_to_idx;
bool restrictions[20][20];
vector<int> curr;

void f(int curr_length) {
    if (curr_length == S) {
        for (int i = 0; i < (int)curr.size(); i++) {
            if (i) cout << " ";
            cout << names[curr[i]];
        }
        cout << endl;
        return;
    }

    int start = 0;
    if (not curr.empty()) start = curr[curr.size() - 1] + 1;
    for (int i = start; i < N; i++) {
        bool pass = true;
        for (int j = 0; j < curr.size(); j++) {
            int idx1, idx2;
            idx1 = curr[j];
            idx2 = i;
            if (restrictions[idx1][idx2]) {
                pass = false;
                break;
            }
        }
        if (not pass) continue;
        curr.push_back(i);
        f(curr_length + 1);
        curr.pop_back();
    }
}

void run() {
    cin >> N >> P >> S;
    names.clear();
    name_to_idx.clear();
    memset(restrictions, 0, sizeof(restrictions));
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < tmp.length(); j++) tmp[j] = toupper(tmp[j]);
        names.push_back(tmp);
    }
    sort(names.begin(), names.end(), [](string a, string b) {
        if (a.length() != b.length()) return a.length() > b.length();
        return a < b;
    });
    for (int i = 0; i < (int)names.size(); i++) {
        name_to_idx[names[i]] = i;
        restrictions[i][i] = 1;
    }
    for (int i = 1; i <= P; i++) {
        string tmp1, tmp2;
        int idx1, idx2;
        cin >> tmp1 >> tmp2;
        for (int j = 0; j < tmp1.length(); j++) tmp1[j] = toupper(tmp1[j]);
        for (int j = 0; j < tmp2.length(); j++) tmp2[j] = toupper(tmp2[j]);
        idx1 = name_to_idx[tmp1];
        idx2 = name_to_idx[tmp2];
        restrictions[idx1][idx2] = restrictions[idx2][idx1] = 1;
    }

    curr.clear();
    f(0);
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Set " << i << ":" << endl;
        run();
    }
    return 0;
}