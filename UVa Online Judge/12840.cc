/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12840.cc
#  Description:     UVa Online Judge - 12840
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int T, N, target;
int A[100];
vector<int> answer;

bool check_before(vector<int> x, vector<int> y) {
    for (int i = 0; i < x.size(); i++) {
        if (x[i] > y[i])
            return true;
        else if (x[i] < y[i])
            return false;
    }
    return false;
}

void f(int idx, int curr, vector<int> curr_answer) {
    if (curr > target) return;
    if ((not answer.empty()) and curr_answer.size() > answer.size()) return;
    if (idx > N) {
        if (curr != target) return;
        if (answer.size() == 0 or curr_answer.size() < answer.size() or
            curr_answer.size() == answer.size() and
                check_before(curr_answer, answer)) {
            answer = curr_answer;
        }
        return;
    }

    int n_possible = (target - curr) / A[idx];
    for (int i = 1; i <= n_possible; i++) curr_answer.push_back(A[idx]);
    for (int i = n_possible; i >= 0; i--) {
        f(idx + 1, curr + i * A[idx], curr_answer);
        if (i > 0) curr_answer.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> T;
    for (int _i = 1; _i <= T; _i++) {
        cout << "Case " << _i << ": ";

        cin >> N >> target;
        for (int i = 1; i <= N; i++) cin >> A[i];
        sort(A + 1, A + N + 1, [](int x, int y) { return x > y; });

        vector<int> curr_answer;
        answer.clear();
        f(1, 0, curr_answer);

        if (answer.empty()) {
            cout << "impossible" << endl;
            continue;
        }
        cout << "[" << answer.size() << "]";
        for (auto it : answer) cout << " " << it;
        cout << endl;
    }
    return 0;
}