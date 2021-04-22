/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10685.cpp
#  Description:     UVa Online Judge - 10685
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
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
map<string, int> toId;

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d %d", &N, &M) == 2) {
        if (N == 0 and M == 0) break;
        string S1, S2;
        int counter = 0;
        for (int i = 1; i <= N; i++) {
            cin >> S1;
            toId[S1] = ++counter;
        }

        int ans = 1;
        unionTree.init(N);
        for (int i = 1; i <= M; i++) {
            cin >> S1 >> S2;

            int a, b;
            a = toId[S1];
            b = toId[S2];
            unionTree.link(a, b);
            ans = max(ans, unionTree.findsize(a));
        }
        printf("%d\n", ans);
    }
    return 0;
}