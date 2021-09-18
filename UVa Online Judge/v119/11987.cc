/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11987.cc
#  Description:     UVa Online Judge - 11987
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int N, M;
int parent[2 * MAXN], ranking[2 * MAXN], sum[2 * MAXN], size[2 * MAXN];
int op, p, q;

int findRoot(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findRoot(parent[x]);
}

void Union(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);
    if (x == y) return;
    if (ranking[x] > ranking[y]) swap(x, y);
    parent[x] = y;
    sum[y] += sum[x];
    size[y] += size[x];
    if (ranking[x] == ranking[y]) ++ranking[y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N >> M) {
        memset(parent, 0, sizeof(parent));
        memset(ranking, 0, sizeof(ranking));
        memset(sum, 0, sizeof(sum));
        memset(size, 0, sizeof(size));
        for (int i = 1; i <= N; i++) {
            parent[i] = i + N;
            parent[i + N] = i + N;
            sum[i + N] = i;
            size[i + N] = 1;
        }
        for (int i = 1; i <= M; i++) {
            cin >> op;
            if (op == 1) {
                cin >> p >> q;
                Union(p, q);
            } else if (op == 2) {
                cin >> p >> q;
                int root_p = findRoot(p);
                int root_q = findRoot(q);
                if (root_p == root_q) continue;
                parent[p] = root_q;
                sum[root_p] -= p;
                sum[root_q] += p;
                size[root_p]--;
                size[root_q]++;
            } else {
                cin >> p;
                p = findRoot(p);
                printf("%d %d\n", size[p], sum[p]);
            }
        }
        if (cin.eof()) break;
    }
    return 0;
}