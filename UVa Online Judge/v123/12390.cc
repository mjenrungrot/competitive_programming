/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12390.cc
#  Description:     UVa Online Judge - 12390
=============================================================================*/
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

typedef tuple<int, int, int> T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, B;
    while (cin >> N >> B) {
        if (N == -1 and B == -1) break;

        vector<int> V;
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            V.push_back(tmp);
        }

        auto cmp = [](T x, T y) { return get<0>(x) < get<0>(y); };
        priority_queue<T, vector<T>, decltype(cmp)> pq(
            cmp);  // max get<0> comes first

        B -= N;
        for (int i = 0; i < N; i++) {
            pq.push(T(V[i], 1, V[i]));
        }

        for (int i = 1; i <= B; i++) {
            T u = pq.top();
            pq.pop();
            int count = get<1>(u);
            int base = get<2>(u);
            int new_val = (base + count) / (count + 1);  // ceiling div
            pq.push(T(new_val, count + 1, base));
        }
        cout << get<0>(pq.top()) << endl;
    }
    return 0;
}