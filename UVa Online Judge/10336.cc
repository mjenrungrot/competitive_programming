/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10336.cc
#  Description:     UVa Online Judge - 10336
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

int N, M;
int dfs_state[MAXN][MAXN];
string A[MAXN];
vi cc;

void dfs(int r, int c, char ch) {
    if (dfs_state[r][c]) return;
    dfs_state[r][c] = cc.size();

    for (int dy : {-1, 0, 1}) {
        for (int dx : {-1, 0, 1}) {
            if (dy == 0 and dx == 0) continue;
            if (abs(dy) + abs(dx) == 2) continue;
            if (r + dy < 0 or r + dy >= N) continue;
            if (c + dx < 0 or c + dx >= M) continue;
            if (A[r + dy][c + dx] != ch) continue;
            if (dfs_state[r + dy][c + dx]) continue;
            dfs(r + dy, c + dx, ch);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        memset(dfs_state, 0, sizeof(dfs_state));
        for (int i = 0; i < N; i++) cin >> A[i];

        cc.clear();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (not dfs_state[i][j]) {
                    cc.push_back(A[i][j]);
                    dfs(i, j, A[i][j]);
                }
            }

        map<char, int> counter;
        for (auto x : cc) {
            if (not counter.count(x)) counter[x] = 0;
            counter[x] += 1;
        }

        vii ans;
        for (auto x : counter) ans.push_back(ii(x.first, x.second));
        sort(ans.begin(), ans.end(), [](ii x, ii y) {
            if (x.second != y.second) return x.second > y.second;
            return x.first < y.first;
        });

        cout << "World #" << ++n_test << endl;
        for (auto x : ans) {
            cout << (char)x.first << ": " << x.second << endl;
        }
    }

    return 0;
}