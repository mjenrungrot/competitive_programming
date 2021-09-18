/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10107.cpp
#  Description:     UVa Online Judge - 10107
=============================================================================*/
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> V;
int X;

int main() {
    // freopen("in","r",stdin);
    while (scanf("%d", &X) == 1) {
        V.push_back(X);
        sort(V.begin(), V.end());
        if ((int)V.size() % 2 == 1)
            printf("%d\n", V[(int)V.size() / 2]);
        else
            printf("%d\n",
                   (V[(int)V.size() / 2] + V[(int)V.size() / 2 - 1]) / 2);
    }
    return 0;
}