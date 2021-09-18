/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11841.cc
#  Description:     UVa Online Judge - 11841
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

const int MAXN = 25;

int N, M;
set<iii> S;
int dfs_state[MAXN][MAXN][MAXN];
int x_side, y_side, z_side;
int n_comp;

void dfs(iii u) {
    // special case: start from x-side
    if (u == iii(-1, -1, -1)) {
        for (int i = 0; i <= N; i++) {
            n_comp++;
            if (S.count(iii(0, i, N - i))) dfs(iii(0, i, N - i));
        }
        return;
    }

    int x = get<0>(u);
    int y = get<1>(u);
    int z = get<2>(u);

    if (dfs_state[x][y][z]) return;
    dfs_state[x][y][z] = n_comp;

    if (S.count(iii(x - 1, y + 1, z))) dfs(iii(x - 1, y + 1, z));
    if (S.count(iii(x - 1, y, z + 1))) dfs(iii(x - 1, y, z + 1));
    if (S.count(iii(x + 1, y - 1, z))) dfs(iii(x + 1, y - 1, z));
    if (S.count(iii(x + 1, y, z - 1))) dfs(iii(x + 1, y, z - 1));
    if (S.count(iii(x, y + 1, z - 1))) dfs(iii(x, y + 1, z - 1));
    if (S.count(iii(x, y - 1, z + 1))) dfs(iii(x, y - 1, z + 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        if (N == 0 and M == 0) break;

        memset(dfs_state, 0, sizeof(dfs_state));
        S.clear();

        for (int i = 1; i <= M; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            S.insert(iii(x, y, z));
        }

        dfs(iii(-1, -1, -1));

        vi masks(n_comp + 1);
        for (auto u : S) {
            int x = get<0>(u);
            int y = get<1>(u);
            int z = get<2>(u);
            if (x == 0) masks[dfs_state[x][y][z]] |= (1 << 2);
            if (y == 0) masks[dfs_state[x][y][z]] |= (1 << 1);
            if (z == 0) masks[dfs_state[x][y][z]] |= (1 << 0);
        }

        int ans = false;
        for (int i = 1; i <= n_comp; i++) {
            if (masks[i] == (1 << 3) - 1) {
                ans = true;
                break;
            }
        }

        if (ans)
            cout << "Benny" << endl;
        else
            cout << "Willy" << endl;
    }

    return 0;
}