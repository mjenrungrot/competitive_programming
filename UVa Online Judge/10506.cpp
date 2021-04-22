/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10506.cpp
#  Description:     UVa Online Judge - 10506
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

bool found;
char str[100000];
int N, M, len;
long long shift;
set<long long> pass;

void f(int nn, long long val) {
    if (found) return;
    if (nn == len) {
        long long nextval = val;
        bool possible = true;
        vector<int> V;
        for (int i = nn; i < nn + M - 1; i++) {
            nextval = nextval - nextval / shift * shift;
            nextval = nextval * 10 + 0;
            // printf("\t\t\t\t\t[%d] [%02d]\n",i,nextval);
            if (pass.count(nextval)) {
                possible = false;
                break;
            }
            pass.insert(nextval);
            V.push_back(nextval);
        }
        if (not possible) {
            for (int i = 0; i < (int)V.size(); i++) pass.erase(V[i]);
            V.clear();
            return;
        }
        V.clear();

        str[nn] = 0;
        printf("%s\n", str);
        found = true;
        return;
    }

    for (int i = 0; i < N; i++) {
        str[nn] = i + '0';
        long long nextval = val - val / shift * shift;
        nextval = nextval * 10 + i;
        if (pass.count(nextval)) continue;
        // printf("[%d] [%02d] T\n",nn,nextval);
        pass.insert(nextval);
        f(nn + 1, nextval);
        // printf("\t[%d] [%02d] F\n",nn,nextval);
        pass.erase(nextval);
        if (found) return;
    }
}

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d %d", &M, &N) == 2) {
        memset(str, 0, sizeof str);
        pass.clear();

        len = 1;
        for (int i = 1; i <= M; i++) len *= N;
        found = false;

        shift = 1;
        for (int i = 1; i < M; i++) shift *= 10;

        for (int i = 0; i < M; i++) str[i] = '0';
        pass.insert(0);
        f(M, 0);
    }
    return 0;
}