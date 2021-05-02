/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10505.cc
#  Description:     UVa Online Judge - 10505
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

const int MAXN = 205;
vi V[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < MAXN; i++) V[i].clear();

        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            int k;
            cin >> k;
            for (int j = 1; j <= k; j++) {
                int x;
                cin >> x;
                if (x > N) continue;
                V[i].push_back(x);
                V[x].push_back(i);
            }
        }

        int ans = 0;
        vi color(N + 1, INF_INT);
        for (int i = 1; i <= N; i++) {
            if (color[i] != INF_INT) continue;

            int not_bipartite = false;
            int count1 = 0, count2 = 0;
            vi curr_comp;

            queue<int> Q;
            curr_comp.push_back(i);
            color[i] = 0, count1++;
            Q.push(i);

            while (not Q.empty()) {
                int u = Q.front();
                Q.pop();
                for (auto v : V[u]) {
                    if (color[v] == INF_INT) {
                        color[v] = 1 - color[u];
                        curr_comp.push_back(v);
                        (color[v] ? count2 : count1)++;
                        Q.push(v);
                    } else if (color[v] == color[u]) {
                        not_bipartite = true;
                    }
                }
            }
            if (not_bipartite) {
                for (auto x : curr_comp) color[x] = -INF_INT;
                continue;
            }
            ans += max(count1, count2);
        }

        cout << ans << endl;
    }
    return 0;
}