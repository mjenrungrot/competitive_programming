/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        793.cpp
#  Description:     UVa Online Judge - 793
=============================================================================*/
#include <cstdio>

const int MAXN = 1e6 + 100;
char line[100];
int R[MAXN], H[MAXN];

int root(int x) {
    if (x == R[x]) return x;
    return R[x] = root(R[x]);
}
void link(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;

    if (H[rx] < H[ry])
        R[rx] = ry;
    else if (H[rx] > H[ry])
        R[ry] = rx;
    else {
        R[rx] = ry;
        H[ry]++;
    }
}

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d ", &T);
    while (T--) {
        int a = 0, b = 0, N;
        char str[5];

        scanf("%d ", &N);
        for (int i = 1; i <= N; i++) R[i] = i, H[i] = 1;

        int x, y;
        while (fgets(line, sizeof line, stdin)) {
            if (line[0] == '\n') break;

            sscanf(line, "%s %d %d", str, &x, &y);
            if (str[0] == 'c')
                link(x, y);
            else if (str[0] == 'q') {
                int ans = (root(x) == root(y));
                if (ans)
                    a++;
                else
                    b++;
            }
        }

        printf("%d,%d\n", a, b);
        if (T) printf("\n");
    }
    return 0;
}