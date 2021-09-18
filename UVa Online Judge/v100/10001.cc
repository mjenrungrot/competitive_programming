/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10001.cc
#  Description:     UVa Online Judge - 10001
=============================================================================*/
#include <iostream>
#include <set>
#include <string>
using namespace std;

int identifier, N, state;
int reachable;

int conv(int id, int left, int curr, int right) {
    return (id & (1 << (left * 4 + curr * 2 + right))) != 0;
}

int get(int state, int pos) { return (state & (1 << pos)) != 0; }

void f(int idx, int curr_state) {
    if (reachable) return;
    if (idx >= 3) {
        if (conv(identifier, get(curr_state, idx - 3), get(curr_state, idx - 2),
                 get(curr_state, idx - 1)) != get(state, idx - 2)) {
            return;
        }
    }
    if (idx == N) {
        // check head
        if (conv(identifier, get(curr_state, N - 1), get(curr_state, 0),
                 get(curr_state, 1)) != get(state, 0))
            return;

        // check tail
        if (conv(identifier, get(curr_state, N - 2), get(curr_state, N - 1),
                 get(curr_state, 0)) != get(state, N - 1))
            return;

        reachable = true;
        return;
    }
    f(idx + 1, curr_state);
    f(idx + 1, curr_state | (1 << idx));
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    while (cin >> identifier >> N) {
        string tmp;
        cin >> tmp;

        state = 0;
        int one_state = 0;
        for (int i = 0; i < N; i++) {
            state |= ((tmp[i] == '1') << i);
            one_state |= (1 << i);
        }

        if (state != 0 and identifier == 0) {
            reachable = false;
        } else if (state != one_state and identifier == 255) {
            reachable = false;
        } else {
            reachable = false;
            f(0, 0);
        }
        if (reachable)
            cout << "REACHABLE" << endl;
        else
            cout << "GARDEN OF EDEN" << endl;
    }
    return 0;
}