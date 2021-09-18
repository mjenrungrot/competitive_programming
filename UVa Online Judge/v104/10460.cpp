/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10460.cpp
#  Description:     UVa Online Judge - 10460
=============================================================================*/
#include <cassert>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

deque<char> D;

const long long INF = 1e10;

int T, N;
char str[1000];
long long idx;

long long ff(int L, int R) {
    long long ans = 1LL;
    for (int i = L; i <= R; i++) {
        ans *= (long long)i;
        if (ans > INF) return ans;
    }
    return ans;
}

void f(int n) {
    if (n == N) {
        for (int i = 0; i < N; i++) printf("%c", D[i]);
        printf("\n");
        return;
    }

    long long ways = ff(n + 2, N);
    long long pos = ways;
    int ii = 0;
    while (pos < idx) pos += ways, ii++;
    // printf("[%d] pos = %lld idx = %lld ways = %lld\n",n,pos,idx,ways);
    // pos >= idx
    // pos-ways < idx
    idx -= (pos - ways);
    assert(idx > 0);

    D.insert(D.begin() + ii, str[n]);
    f(n + 1);
}

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);

    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        N = strlen(str);
        assert(N > 0);
        scanf("%lld", &idx);
        assert(idx > 0);
        assert(idx < (1LL << 32));
        D.clear();
        f(0);
    }
    return 0;
}
