/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        296.cpp
#  Description:     UVa Online Judge - 296
=============================================================================*/
#include <cstdio>
#include <vector>
using namespace std;

struct data {
    data() {}
    data(int code, int a, int b) : code(code), a(a), b(b) {}
    int code, a, b;
};

int N;
vector<struct data> V;

bool test(int val) {
    for (int i = 0; i < (int)V.size(); i++) {
        int v1 = val % 10;
        int v2 = (val / 10) % 10;
        int v3 = (val / 100) % 10;
        int v4 = val / 1000;

        int w1 = V[i].code % 10;
        int w2 = (V[i].code / 10) % 10;
        int w3 = (V[i].code / 100) % 10;
        int w4 = V[i].code / 1000;

        int cc1 = 0, cc2 = 0, xx1 = 1, xx2 = 1, xx3 = 1, xx4 = 1;
        if (v1 == w1) cc1++, xx1 = 0;
        if (v2 == w2) cc1++, xx2 = 0;
        if (v3 == w3) cc1++, xx3 = 0;
        if (v4 == w4) cc1++, xx4 = 0;

        if ((v1 == w2 or v1 == w3 or v1 == w4) and (w1 != v1)) {
            if (xx2 and v1 == w2)
                cc2 += xx2, xx2 = 0;
            else if (xx3 and v1 == w3)
                cc2 += xx3, xx3 = 0;
            else if (xx4 and v1 == w4)
                cc2 += xx4, xx4 = 0;
        }
        if ((v2 == w1 or v2 == w3 or v2 == w4) and (w2 != v2)) {
            if (xx1 and v2 == w1)
                cc2 += xx1, xx1 = 0;
            else if (xx3 and v2 == w3)
                cc2 += xx3, xx3 = 0;
            else if (xx4 and v2 == w4)
                cc2 += xx4, xx4 = 0;
        }
        if ((v3 == w1 or v3 == w2 or v3 == w4) and (w3 != v3)) {
            if (xx1 and v3 == w1)
                cc2 += xx1, xx1 = 0;
            else if (xx2 and v3 == w2)
                cc2 += xx2, xx2 = 0;
            else if (xx4 and v3 == w4)
                cc2 += xx4, xx4 = 0;
        }
        if ((v4 == w1 or v4 == w2 or v4 == w3) and (w4 != v4)) {
            if (xx1 and v4 == w1)
                cc2 += xx1, xx1 = 0;
            else if (xx2 and v4 == w2)
                cc2 += xx2, xx2 = 0;
            else if (xx3 and v4 == w3)
                cc2 += xx3, xx3 = 0;
        }

        // printf("cc1 = %d cc2 = %d\n",cc1,cc2);
        if (cc1 != V[i].a) return false;
        if (cc2 != V[i].b) return false;
    }
    return true;
}

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        V.clear();
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            int a, b, c;
            scanf("%d %d/%d", &a, &b, &c);
            V.push_back(data(a, b, c));
        }

        int ans1, cc = 0;
        for (int i = 0; i < 10000; i++)
            if (test(i)) ans1 = i, cc++;
        if (!cc)
            printf("impossible\n");
        else if (cc > 1)
            printf("indeterminate\n");
        else
            printf("%04d\n", ans1);
    }
    return 0;
}