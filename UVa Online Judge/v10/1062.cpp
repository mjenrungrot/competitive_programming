/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1062.cpp
#  Description:     UVa Online Judge - 1062
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char str[1005];
int N;
vector<int> V;

bool f(int id) {
    for (int i = 0; i < (int)V.size(); i++)
        if (str[id] <= V[i]) {
            V[i] = str[id];
            return false;
        }
    V.push_back(str[id]);
    return true;
}

int main() {
    // freopen("in","r",stdin);
    int test = 0;
    while (scanf("%s", str) == 1) {
        N = strlen(str);
        if (N == 3 and strcmp(str, "end") == 0) break;

        V.clear();
        int ans = 0;
        for (int i = 0; str[i]; i++) ans += f(i);
        printf("Case %d: %d\n", ++test, ans);
    }
    return 0;
}