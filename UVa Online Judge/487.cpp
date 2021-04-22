/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        487.cpp
#  Description:     UVa Online Judge - 487
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

string S;
char now[1000];

const int dify[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int difx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, pass[30][30];
char T[30][30];

vector<string> ans;
int cmp(string A, string B) {
    if ((int)A.length() != (int)B.length())
        return (int)A.length() < (int)B.length();
    return A < B;
}

void f(int r, int c, int len) {
    now[len] = T[r][c];
    if (len >= 2 and len < N * N) {
        now[len + 1] = 0;
        ans.push_back(S = now);
    }
    if (len == N * N) return;

    pass[r][c] = true;
    for (int k = 0; k < 8; k++) {
        if (r + dify[k] > N or r + dify[k] < 1 or c + difx[k] > N or
            c + difx[k] < 1)
            continue;
        if (pass[r + dify[k]][c + difx[k]]) continue;
        if (T[r + dify[k]][c + difx[k]] > T[r][c])
            f(r + dify[k], c + difx[k], len + 1);
    }
    pass[r][c] = false;
}

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int TT;
    scanf("%d", &TT);
    bool found = false;
    while (TT--) {
        scanf("%d", &N);
        ans.clear();
        for (int i = 1; i <= N; i++) scanf("%s", &T[i][1]);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                memset(pass, 0, sizeof pass);
                f(i, j, 0);
            }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        sort(ans.begin(), ans.end(), cmp);
        for (int i = 0; i < (int)ans.size(); i++)
            printf("%s\n", ans[i].c_str());

        if (!ans.empty()) found = true;
        if (not found) continue;
        if (TT) printf("\n");
    }
    return 0;
}