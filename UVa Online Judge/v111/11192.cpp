/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11192.cpp
#  Description:     UVa Online Judge - 11192
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

stack<char> S;
char str[105];

int main() {
    // freopen("in","r",stdin);
    int x, n;
    while (scanf("%d", &x) == 1) {
        if (x == 0) break;
        scanf("%s", str);
        int len = strlen(str);
        bool type = false;
        for (int i = 0; str[i]; i++) {
            if (i % (len / x) == 0) {
                while (!S.empty()) {
                    printf("%c", S.top());
                    S.pop();
                }
            }
            S.push(str[i]);
        }
        while (!S.empty()) {
            printf("%c", S.top());
            S.pop();
        }
        printf("\n");
    }
    return 0;
}