/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        127.cpp
#  Description:     UVa Online Judge - 127
=============================================================================*/
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

vector<stack<int> > V;
char str[10];
int v(int num) { return num % 13; }
int s(int num) { return num / 13; }
int f(char *str) {
    int ans = 0;
    if (str[1] == 'C')
        ans = 0;
    else if (str[1] == 'D')
        ans = 13;
    else if (str[1] == 'H')
        ans = 26;
    else if (str[1] == 'S')
        ans = 39;
    if (str[0] == 'A')
        ans += 0;
    else if (str[0] >= '2' and str[0] <= '9')
        ans += str[0] - '1';
    else if (str[0] == 'T')
        ans += 9;
    else if (str[0] == 'J')
        ans += 10;
    else if (str[0] == 'Q')
        ans += 11;
    else if (str[0] == 'K')
        ans += 12;
    return ans;
}

void print() {
    printf("%d pile%s remaining:", (int)V.size(), (V.size() > 1 ? "s" : ""));
    for (int i = 0; i < (int)V.size(); i++) printf(" %d", (int)V[i].size());
    printf("\n");
}

int main() {
    while (true) {
        V.clear();
        for (int i = 1; i <= 52; i++) {
            scanf("%s", str);
            if (str[0] == '#') return 0;
            int now = f(str);
            stack<int> ss;
            ss.push(f(str));
            V.push_back(ss);
        }

        for (int i = 0; i < (int)V.size(); i++) {
            if (i - 3 >= 0 and (s(V[i].top()) == s(V[i - 3].top()) or
                                v(V[i].top()) == v(V[i - 3].top()))) {
                V[i - 3].push(V[i].top());
                V[i].pop();
                if (V[i].empty()) V.erase(V.begin() + i);
                i -= 4;
            } else if (i - 1 >= 0 and (s(V[i].top()) == s(V[i - 1].top()) or
                                       v(V[i].top()) == v(V[i - 1].top()))) {
                V[i - 1].push(V[i].top());
                V[i].pop();
                if (V[i].empty()) V.erase(V.begin() + i);
                i -= 2;
            }
        }
        print();
    }
    return 0;
}