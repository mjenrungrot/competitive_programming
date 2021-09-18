/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12124.cc
#  Description:     UVa Online Judge - 12124
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, budget;
        cin >> N >> budget;

        map<string, vector<ii> > M;  // type -> vec(price, quality)
        for (int i = 0; i < N; i++) {
            string type, name;
            int price, quality;

            cin >> type >> name >> price >> quality;
            M[type].push_back(ii(price, quality));
        }

        vector<string> types;
        vector<int> assignments;
        int curr_cost = 0;
        auto cmp = [](ii x, ii y) {    // (quality, type_idx)
            return x.first > y.first;  // high quality comes later
        };
        priority_queue<ii, vector<ii>, decltype(cmp)> pq(cmp);

        for (auto kv : M) {
            vector<ii> tmp = kv.second;
            sort(tmp.begin(), tmp.end(), [](ii x, ii y) {
                if (x.first != y.first)
                    return x.first < y.first;  // sort by price
                return x.second < y.second;    // break ties with lowest quality
            });
            M[kv.first] = tmp;

            types.push_back(kv.first);
            assignments.push_back(0);
            curr_cost += tmp[0].first;
            pq.push(ii(tmp[0].second, types.size() - 1));
        }

        int ans = -1;
        while (not pq.empty()) {
            auto u = pq.top();
            ans = max(ans, u.first);
            pq.pop();

            int type_idx = u.second;
            string type = types[type_idx];

            // no more upgrade for this type, so this is the bottleneck
            if (assignments[type_idx] + 1 >= M[type].size()) {
                break;
            }

            auto curr_item = M[type][assignments[type_idx]];
            auto curr_item_price = curr_item.first;
            auto curr_item_quality = curr_item.second;

            auto next_item = M[type][assignments[type_idx] + 1];
            auto next_item_price = next_item.first;
            auto next_item_quality = next_item.second;

            if (curr_cost - curr_item_price + next_item_price <= budget) {
                pq.push(ii(next_item_quality, type_idx));
                assignments[type_idx]++;
                curr_cost = curr_cost - curr_item_price + next_item_price;
            } else {
                break;  // can't upgrade the lowest quality
            }
        }

        cout << ans << endl;
    }

    return 0;
}