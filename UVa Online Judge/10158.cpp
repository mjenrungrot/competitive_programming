/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10158.cpp
#  Description:     UVa Online Judge - 10158
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

const int OFFSET = 30000;

class unionTree {
   private:
    int P[30005], R[30005];

   public:
    void init(int nn) {
        for (int i = 0; i < 30005; i++) P[i] = i, R[i] = 1;
    }
    int root(int x) {
        if (P[x] == x) return x;
        return P[x] = root(P[x]);
    }
    void link(int u, int v) {
        int pu = root(u);
        int pv = root(v);
        if (pu == pv) return;
        if (R[pu] < R[pv])
            P[pu] = pv;
        else if (R[pu] > R[pv])
            P[pv] = pu;
        else {
            P[pu] = pv;
            R[pv]++;
        }
    }
} unionTree;

int N;
bool isFriend(int u, int v) { return unionTree.root(u) == unionTree.root(v); }
bool isEnemy(int u, int v) {
    return unionTree.root(u) == unionTree.root(OFFSET - v);
}

int main() {
    // freopen("in","r",stdin);
    scanf("%d", &N);
    unionTree.init(N);

    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) == 3) {
        if (a == 0) break;
        if (a == 1) {
            if (isEnemy(b, c)) {
                printf("-1\n");
                continue;
            }
            unionTree.link(b, c);
            unionTree.link(OFFSET - b, OFFSET - c);
        } else if (a == 2) {
            if (isFriend(b, c)) {
                printf("-1\n");
                continue;
            }
            unionTree.link(b, OFFSET - c);
            unionTree.link(OFFSET - b, c);
        } else if (a == 3) {
            printf("%d\n", isFriend(b, c));
        } else if (a == 4) {
            printf("%d\n", isEnemy(b, c));
        }
    }
    return 0;
}