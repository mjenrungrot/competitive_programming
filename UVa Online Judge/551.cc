/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        551.cc
#  Description:     UVa Online Judge - 551
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

string ex;

int main() {
    while (getline(cin, ex)) {
        stack<string> S;

        int curr = 0;
        int length = ex.length();
        bool pass = true;
        for (int i = 0; i < length; i++) {
            curr++;
            if (ex[i] == '[')
                S.push("[");
            else if (ex[i] == '{')
                S.push("{");
            else if (ex[i] == '<')
                S.push("<");
            else if (ex[i] == '(') {
                if (i + 1 < length and ex[i + 1] == '*')
                    S.push("(*"), i++;
                else
                    S.push("(");
            } else if (ex[i] == ']') {
                if ((not S.empty()) and S.top() == "[")
                    S.pop();
                else {
                    pass = false;
                    printf("NO %d\n", curr);
                    break;
                }
            } else if (ex[i] == '>') {
                if ((not S.empty()) and S.top() == "<")
                    S.pop();
                else {
                    pass = false;
                    printf("NO %d\n", curr);
                    break;
                }
            } else if (ex[i] == '}') {
                if ((not S.empty()) and S.top() == "{")
                    S.pop();
                else {
                    pass = false;
                    printf("NO %d\n", curr);
                    break;
                }
            } else if (ex[i] == ')') {
                if ((not S.empty()) and S.top() == "(")
                    S.pop();
                else {
                    pass = false;
                    printf("NO %d\n", curr);
                    break;
                }
            } else if (i + 1 < length and ex[i] == '*' and ex[i + 1] == ')') {
                if ((not S.empty()) and S.top() == "(*")
                    S.pop(), i++;
                else {
                    pass = false;
                    printf("NO %d\n", curr);
                    break;
                }
            } else
                continue;
            // stack<string> tmp = S;
            // while(tmp.size() > 0){
            //     printf(" %s ", tmp.top().c_str());
            //     tmp.pop();
            // }
            // printf("\n");
        }
        curr++;
        if (pass and S.size() == 0)
            printf("YES\n");
        else if (pass)
            printf("NO %d\n", curr);
    }
    return 0;
}