/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11108.cpp
#  Description:     UVa Online Judge - 11108
=============================================================================*/
#include <cassert>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

char str[1000];

void print(stack<int> SS) {
    while (!SS.empty()) {
        printf("[%d]", SS.top());
        SS.pop();
    }
    printf("\n");
}

bool process(int bitmask) {
    int p = (bitmask & 1) > 0;
    int q = (bitmask & 2) > 0;
    int r = (bitmask & 4) > 0;
    int s = (bitmask & 8) > 0;
    int t = (bitmask & 16) > 0;

    stack<int> S;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] == 'K') {
            int top1 = S.top();
            S.pop();
            int top2 = S.top();
            S.pop();
            S.push(top2 and top1);
        } else if (str[i] == 'A') {
            int top1 = S.top();
            S.pop();
            int top2 = S.top();
            S.pop();
            S.push(top2 or top1);
        } else if (str[i] == 'N') {
            int top = S.top();
            S.pop();
            S.push(!top);
        } else if (str[i] == 'C') {
            int top1 = S.top();
            S.pop();
            int top2 = S.top();
            S.pop();
            S.push((!top1) or top2);
        } else if (str[i] == 'E') {
            int top1 = S.top();
            S.pop();
            int top2 = S.top();
            S.pop();
            S.push(top2 == top1);
        } else if (str[i] == 'p')
            S.push(p);
        else if (str[i] == 'q')
            S.push(q);
        else if (str[i] == 'r')
            S.push(r);
        else if (str[i] == 's')
            S.push(s);
        else if (str[i] == 't')
            S.push(t);
    }
    assert(S.size() >= 1);

    if (S.top() == true)
        return true;
    else
        return false;
}

int main() {
    // freopen("in","r",stdin);
    while (scanf("%s", str) == 1) {
        if (str[0] == '0') break;

        bool ans = true;
        for (int i = 0; i < 32; i++) ans &= process(i);
        if (ans)
            printf("tautology\n");
        else
            printf("not\n");
    }
    return 0;
}