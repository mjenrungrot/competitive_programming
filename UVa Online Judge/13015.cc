/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13015.cc
#  Description:     UVa Online Judge - 13015
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<dd> vdd;

template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << " ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "[ " << p.first << ", " << p.second << "]";
}

vs split(string line, regex re) {
    vs output;
    sregex_token_iterator it(line.begin(), line.end(), re, -1), it_end;
    while (it != it_end) {
        output.push_back(it->str());
        it++;
    }
    return output;
}

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int MAXN = 5005;

int A, B, E, P;
int dfs_counter, dfs_state[MAXN];
vi V[MAXN], inv_V[MAXN];

int dfs(int u, vi G[]) {  // count nodes in DAG starting at u
    if (dfs_state[u] == dfs_counter) return 0;
    dfs_state[u] = dfs_counter;
    int ans = 1;
    for (auto v : G[u]) ans += dfs(v, G);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> A >> B >> E >> P) {
        for (int i = 0; i < MAXN; i++) {
            V[i].clear();
            inv_V[i].clear();
        }
        memset(dfs_state, 0, sizeof(dfs_state));
        dfs_counter = 1;

        for (int i = 1; i <= P; i++) {
            int u, v;
            cin >> u >> v;
            V[u].push_back(v);
            inv_V[v].push_back(u);
        }

        int nA = 0, nB = 0, nC = 0;
        for (int i = 0; i < E; i++) {
            // Worst case: all nodes rooted at i are taken
            // Then, the number must be at least E - dfs(i, G) + 1
            dfs_counter++;
            int worst_case = E - dfs(i, V) + 1;

            // Best case: all earlier nodes must be taken
            dfs_counter++;
            int best_case = dfs(i, inv_V);

            if (worst_case <= A) nA++;
            if (worst_case <= B) nB++;
            if (best_case > B) nC++;
        }
        cout << nA << endl << nB << endl << nC << endl;
    }

    return 0;
}