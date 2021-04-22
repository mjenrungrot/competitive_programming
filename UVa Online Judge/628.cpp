/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        628.cpp
#  Description:     UVa Online Judge - 628
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

char str[500];

int N, M, len;
string A[200];

string ans;
void f(int now) {
    if (now == len) {
        printf("%s\n", ans.c_str());
        return;
    }

    if (str[now] == '#') {
        for (int i = 1; i <= N; i++) {
            string tmp = ans;
            ans += A[i];
            f(now + 1);
            ans = tmp;
        }
    } else if (str[now] == '0') {
        for (char i = '0'; i <= '9'; i++) {
            string tmp = ans;
            ans += i;
            f(now + 1);
            ans = tmp;
        }
    } else {
        string tmp = ans;
        ans += str[now];
        f(now + 1);
        ans = tmp;
    }
}

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d", &N) == 1) {
        printf("--\n");
        for (int i = 1; i <= N; i++) {
            scanf("%s", str);
            A[i] = str;
        }
        scanf("%d", &M);
        for (int i = 1; i <= M; i++) {
            scanf("%s", str);
            len = strlen(str);
            ans = "";
            f(0);
        }
    }
    return 0;
}