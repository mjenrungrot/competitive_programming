#include <bits/stdc++.h>
using namespace std;

namespace lca {
// info: lca using binary lifting
// guide:
// [0]: Set n, and adj (start with 0-idx)
// [1]: call preprocess with root
// [2]: call lca(u, v)

// need to set the following
int n;
vector<vector<int>> adj;

// this will be updated
int l, timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int u, int p) {
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i <= l; i++) up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }

    tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; i--) {
        if (not is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

}  // namespace lca

int main() {
    // 0->1,
    // 1->2, 1->3
    // 2
    // 3->4
    // 4
    lca::n = 5;
    lca::adj = {{1}, {2, 3}, {}, {4}, {}};
    lca::preprocess(0);
    assert(lca::lca(2, 4) == 1);
    assert(lca::lca(4, 2) == 1);

    return 0;
}