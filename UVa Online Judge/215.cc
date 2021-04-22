/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        215.cc
#  Description:     UVa Online Judge - 215
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

const int MAXR = 30;
const int MAXC = 20;
const long long INF = 1e18;

int R, C;
string raw_values[MAXR][MAXC];
bool visited[MAXR][MAXC];
long long values[MAXR][MAXC];
bool impossible;

long long evaluate(int row, int col) {
    if (values[row][col] != INF) return values[row][col];

    if (visited[row][col]) {
        impossible = true;
        return INF;
    }
    visited[row][col] = true;

    long long ans = 0;
    bool negative = false;
    int curr = 0;
    while (curr < raw_values[row][col].length()) {
        if (raw_values[row][col][curr] == '-') {
            negative = true;
            curr++;
        } else if (raw_values[row][col][curr] == '+') {
            negative = false;
            curr++;
        } else if (raw_values[row][col][curr] >= 'A' and
                   raw_values[row][col][curr] <= 'Z') {
            int r = raw_values[row][col][curr] - 'A' + 1;
            int c = raw_values[row][col][curr + 1] - '0' + 1;
            long long val = evaluate(r, c);
            if (val == INF) {
                ans = INF;
                break;
            } else {
                ans += negative ? -val : val;
            }
            curr += 2;
        } else {
            // number
            long long curr_num = 0;
            while (curr < raw_values[row][col].length() and
                   raw_values[row][col][curr] >= '0' and
                   raw_values[row][col][curr] <= '9') {
                curr_num *= 10;
                curr_num += raw_values[row][col][curr++] - '0';
            }
            if (negative) {
                curr_num *= -1;
                negative = false;
            }
            ans += curr_num;
        }
    }
    return values[row][col] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> R >> C) {
        if (R == 0 and C == 0) break;

        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++) {
                cin >> raw_values[i][j];
                values[i][j] = INF;
                visited[i][j] = 0;
            }

        impossible = false;
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++) evaluate(i, j);

        if (impossible) {
            for (int i = 1; i <= R; i++)
                for (int j = 1; j <= C; j++) {
                    if (values[i][j] == INF) {
                        cout << (char)('A' + i - 1);
                        cout << (char)('0' + j - 1);
                        cout << ": " << raw_values[i][j] << endl;
                    }
                }
        } else {
            cout << " ";
            for (int j = 1; j <= C; j++) {
                cout << setw(6) << (char)('0' + j - 1);
            }
            cout << endl;
            for (int i = 1; i <= R; i++) {
                cout << (char)('A' + i - 1);
                for (int j = 1; j <= C; j++) {
                    cout << setw(6) << right << values[i][j];
                }
                cout << endl;
            }
        }
        cout << endl;
    }

    return 0;
}