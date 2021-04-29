/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1103.cc
#  Description:     UVa Online Judge - 1103
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

const int MAXR = 205;
const int MAXC = 205;
const string mapping = "WAKJSD";

int R, C;
vector<string> A;
int dfs_state[MAXR][MAXC];
vector<int> n_comps;

void floodfill(int r, int c, char curr, int x, int &tmp) {
    if (dfs_state[r][c]) return;
    dfs_state[r][c] = x;

    for (int dr : {-1, 0, 1}) {
        for (int dc : {-1, 0, 1}) {
            if (dr == 0 and dc == 0) continue;
            if (abs(dr) + abs(dc) == 2) continue;
            if (r + dr < 0 or r + dr >= A.size()) {
                tmp = -INF_INT;
                continue;
            }
            if (c + dc < 0 or c + dc >= A[r].length()) {
                tmp = -INF_INT;
                continue;
            }
            if (A[r + dr][c + dc] == curr and dfs_state[r + dr][c + dc] == 0) {
                floodfill(r + dr, c + dc, curr, x, tmp);
            }

            if (tmp == -1) {
                if (A[r + dr][c + dc] == '1')
                    tmp = dfs_state[r + dr][c + dc] - 1;
            } else if (tmp >= 0) {
                if (A[r + dr][c + dc] == '1' and
                    dfs_state[r + dr][c + dc] - 1 != tmp) {
                    tmp = -INF_INT;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> R >> C) {
        if (R == 0 and C == 0) break;

        A.clear();
        for (int i = 0; i < R; i++) {
            string line;
            cin >> line;

            A.push_back("");
            for (int j = 0; j < C; j++) {
                int val = ('0' <= line[j] and line[j] <= '9')
                              ? line[j] - '0'
                              : line[j] - 'a' + 10;
                A.back() += (val & 8) ? '1' : '0';
                A.back() += (val & 4) ? '1' : '0';
                A.back() += (val & 2) ? '1' : '0';
                A.back() += (val & 1) ? '1' : '0';
            }
        }

        memset(dfs_state, 0, sizeof(dfs_state));

        n_comps.clear();
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].length(); j++) {
                if (dfs_state[i][j] == 0 and A[i][j] == '1') {
                    n_comps.push_back(0);
                    int tmp = 0;
                    floodfill(i, j, A[i][j], n_comps.size(), tmp);
                }
            }
        }

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].length(); j++) {
                if (dfs_state[i][j] == 0 and A[i][j] == '0') {
                    int curr_comp = -1;
                    floodfill(i, j, A[i][j], n_comps.size(), curr_comp);
                    if (curr_comp >= 0) n_comps[curr_comp]++;
                }
            }
        }

        cout << "Case " << ++n_test << ": ";
        sort(n_comps.begin(), n_comps.end(),
             [](int x, int y) { return mapping[x] < mapping[y]; });
        for (auto c : n_comps) cout << mapping[c];
        cout << endl;
    }

    return 0;
}