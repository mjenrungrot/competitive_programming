/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        872.cc
#  Description:     UVa Online Judge - 872
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

const int MAXN = 300;

vi nodes;
int G[MAXN][MAXN];
int dfs_state[MAXN];

vvi ans;

void toposort(int idx, vi &tmp) {
    if (idx == nodes.size()) {
        ans.push_back(tmp);
        return;
    }

    for (int i = 0; i < nodes.size(); i++) {
        if (dfs_state[nodes[i]]) continue;

        bool check = true;
        for (int j = 0; j < idx; j++) {
            if (G[nodes[i]][tmp[j]]) {
                check = false;
                break;
            }
        }

        if (check) {
            tmp.push_back(nodes[i]);
            dfs_state[nodes[i]] = true;
            toposort(idx + 1, tmp);
            tmp.pop_back();
            dfs_state[nodes[i]] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);
    int T = stoi(line);

    while (T--) {
        memset(G, 0, sizeof(G));
        memset(dfs_state, 0, sizeof(dfs_state));

        // empty line
        getline(cin, line);

        // parse vertices
        getline(cin, line);

        nodes.clear();
        regex re("\\s");
        sregex_token_iterator it(line.begin(), line.end(), re, -1), it_end;
        while (it != it_end) {
            nodes.push_back(it->str()[0]);
            it++;
        }
        sort(nodes.begin(), nodes.end());

        // parse edges
        getline(cin, line);

        regex re2("(\\s|<)");
        vi edges;
        sregex_token_iterator it2(line.begin(), line.end(), re2, -1);
        while (it2 != it_end) {
            edges.push_back(it2->str()[0]);
            it2++;
        }
        for (int i = 0; i + 1 < edges.size(); i += 2) {
            G[edges[i]][edges[i + 1]] = 1;
        }

        // generate topo order
        ans.clear();

        vi tmp;
        toposort(0, tmp);

        if (ans.size() == 0) {
            cout << "NO" << endl;
        } else {
            for (auto x : ans) {
                bool space = false;
                for (auto val : x) {
                    if (space) cout << " ";
                    space = true;
                    cout << (char)val;
                }
                cout << endl;
            }
        }

        if (T) cout << endl;
    }
    return 0;
}