/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10625.cc
#  Description:     UVa Online Judge - 10625
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 128;
int R, Q, n;
string tmp;
unsigned long long freq[LIMIT];
map<char, string> rules;
vector<pair<char, unsigned long long> > updates;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &R);
        rules.clear();
        for (int i = 1; i <= R; i++) {
            cin >> tmp;
            rules[tmp[0]] = tmp.substr(3);
        }
        scanf("%d", &Q);
        for (int i = 1; i <= Q; i++) {
            memset(freq, 0, sizeof(freq));
            cin >> tmp;
            int length = tmp.length();
            for (int j = 0; j < length; j++) freq[tmp[j]]++;

            cin >> tmp;
            scanf("%d", &n);
            while (n--) {
                updates.clear();
                for (int i = 0; i < 128; i++)
                    if (freq[i] > 0) {
                        if (rules.count(i)) {
                            updates.push_back(make_pair(i, freq[i]));
                            freq[i] = 0;
                        }
                    }

                for (int i = 0; i < updates.size(); i++) {
                    for (int j = 0, sz2 = rules[updates[i].first].size();
                         j < sz2; j++) {
                        freq[rules[updates[i].first][j]] += updates[i].second;
                    }
                }
            }
            printf("%llu\n", freq[tmp[0]]);
        }
    }
    return 0;
}