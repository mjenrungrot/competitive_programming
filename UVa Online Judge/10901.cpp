/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10901.cpp
#  Description:     UVa Online Judge - 10901
=============================================================================*/
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
map<ii, int> answer;
vector<ii> question;

int main() {
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        int N, T, M, x;
        char str[20];
        scanf("%d %d %d", &N, &T, &M);

        queue<int> Q1, Q2;
        question.clear();
        answer.clear();
        for (int i = 1; i <= M; i++) {
            scanf("%d %s", &x, str);
            if (str[0] == 'l')
                Q1.push(x), question.push_back(ii(x, 0));
            else
                Q2.push(x), question.push_back(ii(x, 1));
        }

        int now = 0, cap = 0, tt = 0;
        while (!Q1.empty() or !Q2.empty()) {
            // printf("[%d] %d\n",tt,now);
            if (now == 0) {
                int v1 = 0, v2 = 0;
                bool already = (!Q1.empty() and Q1.front() <= tt);
                if (not already) {
                    if (!Q2.empty() and Q2.front() <= tt) {
                        tt += T;
                        now = 1;
                        continue;
                    }

                    if (!Q1.empty() and Q1.front() > tt) v1 = Q1.front();
                    if (!Q2.empty() and Q2.front() > tt) v2 = Q2.front();
                    if (v1 and v2) {
                        if (v1 < v2)
                            tt = v1;
                        else if (v1 == v2)
                            tt = v1;
                        else {
                            tt = v2 + T, now = 1;
                            continue;
                        }
                    } else if (v1)
                        tt = v1;
                    else if (v2) {
                        tt = v2 + T, now = 1;
                        continue;
                    }
                }

                while (!Q1.empty() and Q1.front() <= tt and cap + 1 <= N) {
                    cap++;
                    answer[ii(Q1.front(), 0)] = tt + T;
                    Q1.pop();
                }
                now = 1;
                cap = 0;
            } else {
                int v1 = 0, v2 = 0;
                bool already = (!Q2.empty() and Q2.front() <= tt);
                if (not already) {
                    if (!Q1.empty() and Q1.front() <= tt) {
                        tt += T;
                        now = 0;
                        continue;
                    }

                    if (!Q1.empty() and Q1.front() > tt) v1 = Q1.front();
                    if (!Q2.empty() and Q2.front() > tt) v2 = Q2.front();
                    if (v1 and v2) {
                        if (v1 < v2) {
                            tt = v1 + T, now = 0;
                            continue;
                        } else if (v1 == v2)
                            tt = v2;
                        else
                            tt = v2;
                    } else if (v1) {
                        tt = v1 + T, now = 0;
                        continue;
                    } else if (v2)
                        tt = v2;
                }

                while (!Q2.empty() and Q2.front() <= tt and cap + 1 <= N) {
                    cap++;
                    answer[ii(Q2.front(), 1)] = tt + T;
                    Q2.pop();
                }
                now = 0;
                cap = 0;
            }
            tt += T;
        }

        for (int i = 0; i < (int)question.size(); i++) {
            printf("%d\n", answer[question[i]]);
        }

        if (TT) printf("\n");
    }
    return 0;
}