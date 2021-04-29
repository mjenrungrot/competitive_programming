/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        776.cc
#  Description:     UVa Online Judge - 776
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

int R, C;
vector<string> A;
vvi dfs_state;

int floodfill(int r, int c, char ch, int new_state) {
    if (dfs_state[r][c]) return 0;
    dfs_state[r][c] = new_state;

    int ans = 1;
    for (int dr : {-1, 0, 1}) {
        for (int dc : {-1, 0, 1}) {
            if (abs(dr) + abs(dc) == 0) continue;
            if (r + dr < 0 or r + dr >= A.size()) continue;
            if (c + dc < 0 or c + dc >= A[r + dr].length()) continue;
            if (A[r + dr][c + dc] == ch) {
                ans += floodfill(r + dr, c + dc, ch, new_state);
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while (true) {
        if (cin.eof()) break;

        A.clear();
        set<char> chars;
        while (true) {
            getline(cin, line);
            if (cin.eof() or line == "%") break;

            regex re("\\s");
            sregex_token_iterator it(line.begin(), line.end(), re, -1), it_end;
            string token = "";
            while (it != it_end) {
                token += it->str();
                chars.insert(it->str()[0]);
                it++;
            }
            A.push_back(token);
        }

        dfs_state.clear();
        dfs_state.resize(A.size());
        for (int i = 0; i < dfs_state.size(); i++) {
            dfs_state[i].resize(A[i].size());
        }

        int counter = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].length(); j++) {
                if (dfs_state[i][j]) continue;
                int new_state = ++counter;
                floodfill(i, j, A[i][j], new_state);
            }
        }

        int n_cols = -1;
        for (int i = 0; i < A.size(); i++)
            n_cols = max(n_cols, (int)A[i].size());
        vi widths(n_cols);

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].length(); j++) {
                int length = (int)log10((double)dfs_state[i][j]) + 1;
                widths[j] = max(widths[j], length);
            }
        }

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].length(); j++) {
                if (j) cout << " ";
                cout << setw(widths[j]) << dfs_state[i][j];
            }
            cout << endl;
        }
        cout << "%" << endl;
    }
    return 0;
}