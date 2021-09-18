/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10199.cc
#  Description:     UVa Online Judge - 10199
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
const int MAXN = 105;

int N;
int dfs_counter;
vs names;
map<string, int> to_idx;
vi V[MAXN], dfs_low, dfs_num, ans;

void dfs(int u, int p) {
    dfs_num[u] = dfs_low[u] = dfs_counter++;

    int n_children = 0;
    for (auto v : V[u]) {
        if (dfs_num[v] == 0) {
            n_children++;
            dfs(v, u);

            if (p == -1 and n_children > 1) {
                ans.push_back(u);
            } else if (p != -1 and dfs_low[v] >= dfs_num[u]) {
                ans.push_back(u);
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != p) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        for (int i = 0; i < MAXN; i++) V[i].clear();
        dfs_low = vi(MAXN, 0);
        dfs_num = vi(MAXN, 0);
        ans.clear();
        to_idx.clear();
        dfs_counter = 1;
        names.clear();

        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            string name;
            cin >> name;
            names.push_back(name);
            to_idx[name] = i;
        }

        int M;
        cin >> M;
        while (M--) {
            string name1, name2;
            cin >> name1 >> name2;
            V[to_idx[name1]].push_back(to_idx[name2]);
            V[to_idx[name2]].push_back(to_idx[name1]);
        }

        for (int i = 0; i < N; i++)
            if (dfs_num[i] == 0) dfs(i, -1);

        sort(ans.begin(), ans.end(),
             [](int x, int y) { return names[x] < names[y]; });
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        if (n_test) cout << endl;

        cout << "City map #" << ++n_test << ": " << ans.size()
             << " camera(s) found" << endl;
        for (auto x : ans) {
            cout << names[x] << endl;
        }
    }

    return 0;
}