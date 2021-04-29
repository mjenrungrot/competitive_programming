/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        782.cc
#  Description:     UVa Online Judge - 782
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<dd> vdd;

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;

const int MAXN = 100;
int dfs_state[MAXN][MAXN];
int R, C;
vector<string> A;

void floodfill(int r, int c) {
    if (dfs_state[r][c]) return;
    dfs_state[r][c] = 1;

    // check if 'x' is neighbor
    bool to_paint = false;
    for (int dr : {-1, 0, 1}) {
        for (int dc : {-1, 0, 1}) {
            if (abs(dr) + abs(dc) != 1) continue;
            if (r + dr < 0 or r + dr >= A.size()) continue;
            if (c + dc < 0 or c + dc >= A[r + dr].length()) continue;
            if (A[r + dr][c + dc] != ' ' and A[r + dr][c + dc] != '#')
                to_paint = true;
            if (A[r + dr][c + dc] != ' ') continue;
            floodfill(r + dr, c + dc);
        }
    }

    if (to_paint) A[r][c] = '#';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);
    int T = stoi(line);

    while (T--) {
        A.clear();
        while (true) {
            getline(cin, line);
            if (line[0] == '_') break;
            A.push_back(line);
        }
        R = A.size();
        C = -1;
        for (int i = 0; i < R; i++) C = max(C, (int)A[i].length());
        C++;
        for (int i = 0; i < R; i++) {
            A[i] = A[i] + string(C - A[i].length(), ' ');
        }

        memset(dfs_state, 0, sizeof(dfs_state));
        bool done = false;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].length(); j++) {
                if (dfs_state[i][j]) continue;
                if (A[i][j] == '*') {
                    A[i][j] = ' ';
                    floodfill(i, j);
                }
            }
        }

        for (int i = 0; i < A.size(); i++) {
            string tmp = A[i];
            while (not tmp.empty() and tmp.back() == ' ') tmp.pop_back();
            cout << tmp << endl;
        }
        cout << line << endl;
    }

    return 0;
}