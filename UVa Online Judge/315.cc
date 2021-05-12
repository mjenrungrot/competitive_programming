/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        315.cc
#  Description:     UVa Online Judge - 315
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
vi V[MAXN], dfs_low, dfs_num, articulation_point;

void dfs(int u, int p, int &n_children) {
    dfs_low[u] = dfs_num[u] = dfs_counter++;
    for (auto v : V[u]) {
        if (dfs_num[v] == 0) {
            if (p == -1) n_children++;
            dfs(v, u, n_children);

            if (dfs_low[v] >= dfs_num[u]) {  // back-edge to u or ancestors of u
                articulation_point[u] = 1;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);  // tree-edge
        } else if (v != p) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);  // back-edge
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;

    while (getline(cin, line)) {
        for (int i = 0; i < MAXN; i++) V[i].clear();
        dfs_low = vi(MAXN, 0);
        dfs_num = vi(MAXN, 0);
        articulation_point = vi(MAXN, 0);
        dfs_counter = 1;

        N = stoi(line);
        if (N == 0) break;

        while (true) {
            getline(cin, line);
            vs nums_str = split(line, regex("\\s"));
            vi nums;
            for (auto x : nums_str) nums.push_back(stoi(x));

            if (nums[0] == 0) break;
            for (int j = 1; j < nums.size(); j++) {
                V[nums[0]].push_back(nums[j]);
                V[nums[j]].push_back(nums[0]);
            }
        }

        for (int i = 1; i <= N; i++)
            if (dfs_num[i] == 0) {
                int root_children = 0;
                dfs(i, -1, root_children);
                articulation_point[i] = (root_children > 1);
            }

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += articulation_point[i];
        }
        cout << ans << endl;
    }

    return 0;
}