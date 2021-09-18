/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12697.cc
#  Description:     UVa Online Judge - 12697
=============================================================================*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
const int INF = 1e9;

int N;
long long X;
vector<long long> A, qs;

void run() {
    cin >> N >> X;

    A.clear();
    qs.clear();
    bool done = false;
    for (int i = 0; i < N; i++) {
        long long tmp;
        cin >> tmp;
        A.push_back(tmp);

        long long prev_sum = (i > 0) ? qs[qs.size() - 1] : 0LL;
        qs.push_back(prev_sum + tmp);
    }
    /*
    qs[i] = A[0] + ... A[i]

    for R in [0, N-1]
        find L s.t.
        (1) L<R
        (2) L=argmax(qs[R] - qs[L] >= X)
        ==> we'll store (qs[k],k) in the max priority queue (pq)
        ==> L = pq.top().second
            s.t. qs[R] - pq.top().first >= X and
                 qs.top().second < R
    */
    int ans = INF;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, -1));  // initial position (qs[-1] = 0)
    for (int i = 0; i < N; i++) {
        while (!pq.empty() and qs[i] - pq.top().first >= X) {
            ans = min(ans, i - pq.top().second);
            pq.pop();
        }
        pq.push(ii(qs[i], i));
    }
    if (ans != INF)
        cout << ans << endl;
    else
        cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) run();
    return 0;
}