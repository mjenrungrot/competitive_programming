/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11157.cc
#  Description:     UVa Online Judge - 11157
=============================================================================*/
#include <iostream>
#include <regex>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_case = 0;
    cin >> T;
    while (T--) {
        int N, D;
        cin >> N >> D;

        vector<tuple<char, int> > V;
        V.push_back(tuple<char, int>('B', 0));
        for (int i = 1; i <= N; i++) {
            string tmp;
            cin >> tmp;

            regex re("-");
            sregex_token_iterator it(tmp.begin(), tmp.end(), re, -1);
            vector<string> tokens(it, {});

            V.push_back(tuple<char, int>(tokens[0][0], stoi(tokens[1])));
        }
        V.push_back(tuple<char, int>('B', D));

        vector<int> drowned(V.size());
        int ans = 0;
        int curr = 0, curr_idx = 0;

        // Forward pass
        while (curr < D) {
            if (curr_idx + 1 < V.size() and get<0>(V[curr_idx + 1]) == 'B') {
                int dist = get<1>(V[curr_idx + 1]) - curr;
                ans = max(ans, dist);
                curr = get<1>(V[curr_idx + 1]);
                curr_idx++;
            } else {  // guarantee that the next one is small
                if (curr_idx + 2 < V.size() and
                    get<0>(V[curr_idx + 2]) == 'S') {
                    drowned[curr_idx + 2] = true;
                }
                int dist = get<1>(V[curr_idx + 2]) - curr;
                ans = max(ans, dist);
                curr = get<1>(V[curr_idx + 2]);
                curr_idx += 2;
            }
        }

        // Backward pass
        while (curr > 0) {
            for (int k = curr_idx - 1; k >= 0; k--) {
                if (drowned[k]) continue;
                int dist = curr - get<1>(V[k]);
                ans = max(ans, dist);
                curr = get<1>(V[k]);
                curr_idx = k;
                break;
            }
        }

        cout << "Case " << ++n_case << ": " << ans << endl;
    }
    return 0;
}
