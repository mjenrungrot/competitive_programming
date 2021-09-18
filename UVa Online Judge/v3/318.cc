/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        318.cc
#  Description:     UVa Online Judge - 318
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
const int MAXN = 1005;

int N, M;
vii V[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N >> M) {
        if (N == 0 and M == 0) break;

        for (int i = 0; i < MAXN; i++) V[i].clear();

        for (int i = 1; i <= M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            V[u].push_back(ii(v, w));
            V[v].push_back(ii(u, w));
        }

        vi dist(MAXN, 1e9);
        vi parent(MAXN, -1);
        dist[1] = 0;
        priority_queue<ii, vii, greater<ii>> pq;
        pq.push({0, 1});

        while (not pq.empty()) {
            ii top = pq.top();
            pq.pop();
            int d = top.first;
            int u = top.second;
            if (d > dist[u]) continue;

            for (auto& pair : V[u]) {
                if (dist[u] + pair.second >= dist[pair.first]) continue;
                dist[pair.first] = dist[u] + pair.second;
                parent[pair.first] = u;
                pq.push({dist[pair.first], pair.first});
            }
        }

        double type1 = -1, type2 = -1;
        int type1_idx, type2_idx1, type2_idx2;

        // type1: at the node
        for (int i = 1; i <= N; i++) {
            if (dist[i] > type1) {
                type1 = dist[i];
                type1_idx = i;
            }
        }

        // type2: between nodes
        for (int u = 1; u <= N; u++) {
            for (auto& pair : V[u]) {
                int v = pair.first;

                if (parent[u] == v or parent[v] == u) continue;

                double extra = abs(dist[u] - dist[v]);
                double rem = (double)pair.second - extra;
                if (rem <= 0.0) continue;
                double val = (double)max(dist[u], dist[v]) + rem / 2.0;

                if (val > type2) {
                    type2 = val;
                    type2_idx1 = min(u, v);
                    type2_idx2 = max(u, v);
                }
            }
        }

        cout << "System #" << ++n_test << endl;
        if (fabs(type2 + 1) < 1e-6) {
            cout << "The last domino falls after " << fixed << setprecision(1)
                 << type1 << " seconds, ";
            cout << "at key domino " << type1_idx << "." << endl;
        } else {
            cout << "The last domino falls after " << fixed << setprecision(1)
                 << type2 << " seconds, ";
            cout << "between key dominoes " << type2_idx1 << " and "
                 << type2_idx2 << "." << endl;
        }
        cout << endl;
    }
    return 0;
}