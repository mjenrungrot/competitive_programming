/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        840.cc
#  Description:     UVa Online Judge - 840
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

const int MAXN = 300;
enum STATE { UNVISITED, IN_PROGRESS, DONE };
vi V[MAXN];
int dfs_state[MAXN];
vvi ans;

void save(vi &cycle) {
    // find canonical position
    int best_val = INF_INT;
    int best_pos = -1;
    for (int i = 0; i < cycle.size(); i++) {
        if (cycle[i] < best_val) {
            best_val = cycle[i];
            best_pos = i;
        }
    }

    vi tmp;
    for (int i = 0; i < cycle.size(); i++)
        tmp.push_back(cycle[(best_pos + i) % cycle.size()]);
    tmp.push_back(cycle[best_pos]);
    ans.push_back(tmp);
}

void dfs(int start, int node, vi &cycle) {
    dfs_state[node] = IN_PROGRESS;
    cycle.push_back(node);
    for (auto v : V[node]) {
        if (v == start) save(cycle);
        if (dfs_state[v] == UNVISITED) dfs(start, v, cycle);
    }
    cycle.pop_back();
    dfs_state[node] = UNVISITED;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        // init
        for (int i = 0; i < MAXN; i++) V[i].clear();
        memset(dfs_state, UNVISITED, sizeof(dfs_state));

        int N, M, E;
        cin >> N >> M >> E;

        for (int i = 0; i < E; i++) {
            string line;
            cin >> line;
            V[line[0]].push_back(line[2]);
        }

        for (int i = 0; i < MAXN; i++) sort(V[i].begin(), V[i].end());

        vi cycle;
        ans.clear();
        for (int i = 0; i < MAXN; i++) dfs(i, i, cycle);

        if (ans.size() == 0)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            sort(ans.begin(), ans.end(), [](vi x, vi y) {
                if (x.size() != y.size()) return x.size() < y.size();
                for (int i = 0; i < x.size(); i++) {
                    if (x[i] != y[i]) return x[i] < y[i];
                }
                return false;
            });

            ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

            for (auto sequence : ans) {
                bool delim = false;
                for (auto token : sequence) {
                    if (delim) cout << "-";
                    delim = true;
                    cout << (char)token;
                }
                cout << endl;
            }
        }

        if (T) cout << endl;
    }
    return 0;
}