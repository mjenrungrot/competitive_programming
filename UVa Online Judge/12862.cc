/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12862.cc
#  Description:     UVa Online Judge - 12862
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

const int MAXN = 100005;

int N, M;
int is_friend[MAXN];
vii V[MAXN];
int total, end_path;

// return the number of friends in the subtree
int f(int curr_node, int depth) {
    if (is_friend[curr_node]) end_path = max(end_path, depth);

    int total_friends = is_friend[curr_node];
    for (auto v : V[curr_node]) {
        int n_friends = f(v.first, depth + v.second);
        if (n_friends > 0) {
            total += v.second;
            total_friends += n_friends;
        }
    }
    return total_friends;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M) {
        for (int i = 1; i <= N; i++) {
            V[i].clear();
            is_friend[i] = 0;
        }

        for (int i = 0; i < N - 1; i++) {
            int u, v, cost;
            cin >> u >> v >> cost;
            V[u].push_back(ii(v, cost));
        }

        for (int i = 1; i <= M; i++) {
            int x;
            cin >> x;
            is_friend[x] = true;
        }

        total = end_path = 0;

        f(1, 0);

        cout << total - end_path << endl;
    }
    return 0;
}