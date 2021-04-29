/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11110.cc
#  Description:     UVa Online Judge - 11110
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

const int MAXN = 105;
int arr[MAXN][MAXN];
int dfs_state[MAXN][MAXN];
int N;

int floodfill(int r, int c, int val) {
    if (dfs_state[r][c]) return 0;
    dfs_state[r][c] = 1;

    int ans = 1;
    for (int dr : {-1, 0, 1}) {
        for (int dc : {-1, 0, 1}) {
            if (dr == 0 and dc == 0) continue;
            if (abs(dr) + abs(dc) == 2) continue;
            if (r + dr <= 0 or r + dr > N) continue;
            if (c + dc <= 0 or c + dc > N) continue;
            if (arr[r + dr][c + dc] != val) continue;
            ans += floodfill(r + dr, c + dc, val);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while (true) {
        memset(arr, -1, sizeof(arr));
        memset(dfs_state, 0, sizeof(dfs_state));

        getline(cin, line);
        N = stoi(line);
        if (N == 0) break;

        bool bad = false;
        for (int i = 1; i <= N - 1; i++) {
            getline(cin, line);

            regex re("\\s");
            sregex_token_iterator it(line.begin(), line.end(), re, -1), it_end;
            vi nums;
            while (it != it_end) {
                if (not it->str().empty()) nums.push_back(stoi(it->str()));
                it++;
            }

            if (nums.size() % 2 != 0) bad = true;

            for (int j = 0; j + 1 < nums.size(); j += 2) {
                arr[nums[j]][nums[j + 1]] = i;
            }
        }

        if (not bad) {
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++) {
                    if (dfs_state[i][j]) continue;
                    int val = floodfill(i, j, arr[i][j]);
                    if (val != N) bad = true;
                }
        }

        if (bad) {
            cout << "wrong" << endl;
        } else {
            cout << "good" << endl;
        }
    }

    return 0;
}