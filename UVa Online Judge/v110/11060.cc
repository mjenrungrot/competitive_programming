/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11060.cc
#  Description:     UVa Online Judge - 11060
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

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;

const int MAXN = 105;

int N, M;
vs names;
map<string, int> to_idx;
vi G[MAXN];
vi in_degrees;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        to_idx.clear();
        for (int i = 0; i < MAXN; i++) G[i].clear();

        names.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> names[i];
            to_idx[names[i]] = i;
        }

        cin >> M;

        in_degrees.resize(N, 0);
        for (int i = 0; i < M; i++) {
            string u, v;
            cin >> u >> v;
            G[to_idx[u]].push_back(to_idx[v]);
            in_degrees[to_idx[v]]++;
        }

        cout << "Case #" << ++n_test
             << ": Dilbert should drink beverages in this order:";

        // Initialization
        auto cmp = [](ii x, ii y) { return x.first > y.first; };
        priority_queue<ii, vector<ii>, decltype(cmp)> pq(
            cmp);  // stores (order, node). lower order comes first
        for (int i = 0; i < N; i++) {
            if (in_degrees[i] == 0) {
                int order = i;
                int node = i;
                pq.push(ii(order, node));
            }
        }

        vs ans;
        while (not pq.empty()) {
            ii u = pq.top();
            pq.pop();
            ans.push_back(names[u.second]);

            for (auto v : G[u.second]) {
                in_degrees[v]--;
                if (in_degrees[v] == 0) {
                    pq.push(ii(v, v));
                }
            }
        }

        for (auto x : ans) cout << " " << x;
        cout << "." << endl << endl;
    }

    return 0;
}