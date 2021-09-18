/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10608.cpp
#  Description:     UVa Online Judge - 10608
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

class unionTree {
   private:
    int R[30005], P[30005], S[30005];

   public:
    void init(int nn) {
        for (int i = 1; i <= nn; i++) R[i] = 1, P[i] = i, S[i] = 1;
    }
    int root(int x) {
        if (x == P[x]) return x;
        return P[x] = root(P[x]);
    }
    void link(int u, int v) {
        int pu = root(u);
        int pv = root(v);
        if (pu == pv) return;
        if (R[pu] < R[pv])
            P[pu] = pv, S[pv] += S[pu];
        else if (R[pu] > R[pv])
            P[pv] = pu, S[pu] += S[pv];
        else {
            P[pu] = pv;
            R[pv]++;
            S[pv] += S[pu];
        }
    }
    int findsize(int u) {
        u = root(u);
        return S[u];
    }
} unionTree;

int N, M;

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);

        int ans = 1;
        unionTree.init(N);
        for (int i = 1; i <= M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            unionTree.link(a, b);
            ans = max(ans, unionTree.findsize(a));
        }
        printf("%d\n", ans);
    }
    return 0;
}