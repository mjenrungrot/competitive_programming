/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11147.cc
#  Description:     UVa Online Judge - 11147
=============================================================================*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int find_sum(int start, int end, vector<int> &qs) {
    if (start > end) return 0;
    if (start == 0) return qs[end];
    return qs[end] - qs[start - 1];
}

int compute(int start, int mid, int end, vector<int> &qs) {
    return abs(find_sum(start, mid - 1, qs) - find_sum(mid + 1, end, qs));
}

void f(int start, int end, vector<int> &qs, int level) {
    if (start == end) {
        cout << find_sum(start, start, qs);
        return;
    }

    int left = start, right = end, opt, val_opt, curr_val;
    opt = -1;
    val_opt = 1e9;
    for (int i = left; i <= right; i++) {
        while (i + 1 <= end and
               find_sum(i, i, qs) == find_sum(i + 1, i + 1, qs))
            i++;
        curr_val = compute(start, i, end, qs);
        if (curr_val < val_opt) {
            val_opt = curr_val;
            opt = i;
        }
    }

    cout << find_sum(opt, opt, qs) << "(";
    if (start <= opt - 1) f(start, opt - 1, qs, level + 1);
    if (start <= opt - 1 and opt + 1 <= end) cout << ",";
    if (opt + 1 <= end) f(opt + 1, end, qs, level + 1);
    cout << ")";
}

void run() {
    int N;
    vector<int> A, qs;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
        if (i == 0)
            qs.push_back(A[0]);
        else
            qs.push_back(qs.back() + A[i]);
    }

    f(0, A.size() - 1, qs, 0);
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        run();
    }
    return 0;
}