/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1329.cc
#  Description:     UVa Online Judge - 1329
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20005;
int ranking[MAXN], parent[MAXN], total[MAXN];
int T, N, p, q;
char ch;

int abs(int x) { return x < 0 ? -x : x; }

int findRoot(int x) {
    if (x == parent[x]) return x;
    int p = findRoot(parent[x]);
    total[x] += total[parent[x]];
    return parent[x] = p;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        memset(parent, 0, sizeof(parent));
        memset(total, 0, sizeof(total));

        cin >> N;
        for (int i = 1; i <= N; i++) parent[i] = i;
        while (cin >> ch) {
            if (ch == 'O')
                break;
            else if (ch == 'E') {
                cin >> p;
                findRoot(p);
                printf("%d\n", total[p]);
            } else {
                cin >> p >> q;
                parent[p] = q;
                total[p] = abs(p - q) % 1000;
            }
        }
    }
    return 0;
}