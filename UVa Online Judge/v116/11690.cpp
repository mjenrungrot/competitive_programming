/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11690.cpp
#  Description:     UVa Online Judge - 11690
=============================================================================*/
#include <algorithm>
#include <cstdio>
using namespace std;

class unionTree {
   private:
    int R[50005], P[50005], S[50005];

   public:
    void setsize(int id, int val) { S[id] = val; }
    void init(int nn) {
        for (int i = 0; i < nn; i++) R[i] = 1, P[i] = i, S[i] = 1;
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
        unionTree.init(N);
        for (int i = 0; i < N; i++) {
            int xx;
            scanf("%d", &xx);
            unionTree.setsize(i, xx);
        }

        for (int i = 1; i <= M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            unionTree.link(a, b);
        }

        bool ans = true;
        for (int i = 0; i < N; i++)
            if (unionTree.findsize(i) != 0) ans = false;
        if (ans)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}