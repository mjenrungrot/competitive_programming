/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10950.cpp
#  Description:     UVa Online Judge - 10950
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int LIMIT = 100;
typedef pair<string, string> ss;
int N, test, cc, len;

vector<ss> str;
int val[105], L[105];
char A[105], B[105];
char ans[105];

void f(int n, int l) {
    if (cc == LIMIT) return;
    if (l == len and n > 0) {
        ans[n] = 0;
        cc++;
        printf("%s\n", ans);
        return;
    }

    for (int i = 0; i < N; i++) {
        bool possible = true;
        if (l + L[i] > len) continue;
        for (int j = l, k = 0; j < l + L[i]; j++, k++) {
            if (str[i].second.at(k) != A[j]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            ans[n] = str[i].first.at(0);
            ans[n + 1] = 0;
            f(n + 1, l + L[i]);
        }
    }
    if (A[l] == '0' and l < len - 1) f(n, l + 1);
}

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    while (scanf("%d", &N) == 1) {
        if (!N) break;

        str.clear();
        for (int i = 1; i <= N; i++) {
            scanf("%s %s", A, B);
            str.push_back(ss(A, B));
        }
        sort(str.begin(), str.end());
        for (int i = 0; i < N; i++) L[i] = str[i].second.length();

        scanf("%s", A);
        len = strlen(A);
        cc = 0;

        printf("Case #%d\n", ++test);
        f(0, 0);
        printf("\n");
    }
    return 0;
}
