/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        939.cpp
#  Description:     UVa Online Judge - 939
=============================================================================*/
#include <cassert>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef pair<string, string> ss;
typedef pair<ss, string> sss;

map<string, int> M1;
map<string, string> M2;
map<string, string> answer;

deque<sss> D;

int main() {
    // freopen("in","r",stdin);
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        string S1, S2;
        cin >> S1 >> S2;
        if (S2 == "dominant") {
            M1[S1] = 1;
            answer[S1] = "dominant";
        } else if (S2 == "recessive") {
            M1[S1] = 2;
            answer[S1] = "recessive";
        } else if (S2 == "non-existent") {
            M1[S1] = 3;
            answer[S1] = "non-existent";
        } else {
            if (!M2.count(S2)) {
                M2[S2] = S1;
            } else {
                string p1 = M2[S2];
                string p2 = S1;
                D.push_back(sss(ss(p1, p2), S2));
            }
        }

        while (true) {
            bool possible = false;
            int idx = 0;
            string p1, p2;
            for (int i = 0; i < D.size(); i++) {
                if (M1.count(D[i].first.first) and
                    M1.count(D[i].first.second)) {
                    possible = true;
                    p1 = D[i].first.first;
                    p2 = D[i].first.second;
                    S2 = D[i].second;
                    idx = i;
                    break;
                }
            }
            if (possible)
                D.erase(D.begin() + idx);
            else
                break;

            int v1 = M1[p1];
            int v2 = M1[p2];

            bool have;
            if (v1 != 3 and v2 != 3)
                have = true;
            else if (v1 == 1 or v2 == 1)
                have = true;
            else
                have = false;

            bool dominant;
            if (v1 == 1 and v2 == 1)
                dominant = true;
            else if (v1 == 1 and v2 == 2)
                dominant = true;
            else if (v1 == 2 and v2 == 1)
                dominant = true;
            else
                dominant = false;

            if (not have)
                answer[S2] = "non-existent", M1[S2] = 3;
            else if (dominant)
                answer[S2] = "dominant", M1[S2] = 1;
            else
                answer[S2] = "recessive", M1[S2] = 2;
        }
    }
    for (map<string, string>::iterator it = answer.begin(); it != answer.end();
         it++) {
        printf("%s %s\n", (it->first).c_str(), (it->second).c_str());
    }
    return 0;
}