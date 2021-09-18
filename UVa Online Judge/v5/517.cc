/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        517.cc
#  Description:     UVa Online Judge - 517
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = (1 << 16) + 10;

int N, S;
int conversion[10];
int curr = 0;
int memo[MAX_SIZE];
string line;

int convert(string in) {
    int curr = 0;
    for (int i = 0; i < in.length(); i++) {
        curr *= 2;
        curr += in[i] - 'a';
    }
    return curr;
}

string to_str(int tmp) {
    int smallest = tmp;
    for (int i = 0; i < N; i++) {
        tmp = (tmp >> 1) + ((tmp & 1) << (N - 1));
        smallest = min(smallest, tmp);
    }

    string ans = "";
    for (int i = N - 1; i >= 0; i--) {
        if (smallest & (1 << i))
            ans += 'b';
        else
            ans += 'a';
    }
    return ans;
}

int run() {
    int new_val = 0;
    // for(int i=0;i<N;i++) cout << "curr[" << i << "] = " << ((curr & (1 << (i
    // % N))) > 0) << endl;
    for (int i = 0; i < N; i++) {
        int prev2 = (curr & (1 << ((i + 2) % N))) > 0;
        int curr0 = (curr & (1 << (i % N))) > 0;
        int next1 = (curr & (1 << ((i + N - 1) % N))) > 0;
        int idx = (prev2 << 2) + (curr0 << 1) + (next1 << 0);
        // cout << "new_val[" << i << ":" << prev2 << curr0 << next1 << "] = "
        // << conversion[idx] << endl;
        new_val |= (conversion[idx] << i);
    }
    return new_val;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> N) {
        cin >> line;
        curr = convert(line);
        for (int i = 1; i <= 8; i++) {
            cin >> line;
            int x = convert(line);
            // cout << "conversion[" << (x>>1) << "] = " << (x&1) << endl;
            conversion[x >> 1] = x & 1;
        }
        cin >> S;

        memset(memo, -1, sizeof(memo));
        int step = 0;
        memo[curr] = step;
        while (step < S) {
            curr = run();
            step++;
            if (memo[curr] != -1) break;
        }

        if (step == S) {
            cout << to_str(curr) << endl;
            continue;
        }

        int before_cycle = memo[curr];
        int cycle_length = step - memo[curr];
        int remainder = (S - before_cycle) % cycle_length;

        step = 0;
        while (step < remainder) {
            curr = run();
            step++;
        }
        if (step == remainder) {
            cout << to_str(curr) << endl;
            continue;
        }
    }
    return 0;
}