/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        347.cpp
#  Description:     UVa Online Judge - 347
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int A[20];
set<int> S;

int check(int val) {
    int vv = 0, bitbit = 0;
    while (val) {
        A[++vv] = val % 10;
        if (A[vv] == 0) return false;
        if ((1 << A[vv]) & bitbit) return false;
        bitbit |= 1 << A[vv];
        val /= 10;
    }

    int now = 1, len = vv;
    for (int i = 1; i < vv; i++, vv--) swap(A[i], A[vv]);

    int bitmask = 0;
    for (int i = 1; i <= len; i++) {
        int xx = A[now];
        xx %= len;
        if (bitmask & (1 << now)) return false;
        bitmask |= (1 << now);

        if (now + xx <= len)
            now += xx;
        else if (now + xx > len) {
            xx -= (len - now + 1);
            now = 1;
            if (xx) now += xx;
        }
    }
    if (bitmask != ((1 << (len + 1)) - 2)) return false;
    if (now == 1) return true;
    return false;
}

void gen() {
    for (int i = 10; i <= 1e7; i++)
        if (check(i)) S.insert(i);
}

int main() {
    // freopen("in","r",stdin);
    gen();
    int N, test = 0;
    while (scanf("%d", &N) == 1) {
        if (!N) break;
        printf("Case %d: %d\n", ++test, *S.lower_bound(N));
    }
    return 0;
}