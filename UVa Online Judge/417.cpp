/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        417.cpp
#  Description:     UVa Online Judge - 417
=============================================================================*/
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> M;

int counter;
void gen(string now, int level, int max_level) {
    if (level > max_level) return;
    int start = now.length() ? now[now.length() - 1] + 1 : 'a';
    if (level + 1 == max_level)
        for (int i = start; i <= 'z'; i++) M[now + (char)i] = ++counter;
    for (int i = start; i <= 'z'; i++) gen(now + (char)i, level + 1, max_level);
}

int main() {
    // freopen("in","r",stdin);
    gen("", 0, 1);
    gen("", 0, 2);
    gen("", 0, 3);
    gen("", 0, 4);
    gen("", 0, 5);
    string ss;
    while (cin >> ss) {
        if (M.count(ss))
            printf("%d\n", M[ss]);
        else
            printf("0\n");
    }
    return 0;
}