/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10282.cpp
#  Description:     UVa Online Judge - 10282
=============================================================================*/
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

map<string, string> M;
string S1, S2;
char str1[30], str2[30], str[200];

int main() {
    // freopen("in","r",stdin);
    while (fgets(str, sizeof(str), stdin)) {
        if (str[0] == '\n') break;
        sscanf(str, "%s %s", str1, str2);
        S1 = str1;
        S2 = str2;
        M[S2] = S1;
    }
    while (fgets(str, sizeof(str), stdin)) {
        if (str[0] == '\n') break;
        char *p = strtok(str, "\n");
        S1 = p;
        if (M.count(S1))
            printf("%s\n", M[S1].c_str());
        else
            printf("eh\n");
    }
    return 0;
}