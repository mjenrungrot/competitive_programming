#include <bits/stdc++.h>
using namespace std;

const int MAXROW = 1005;
const int MAXCOL = 18300;

string raw_values[MAXROW][MAXCOL];
long long values[MAXROW][MAXCOL];
int R, C;

pair<int, int> parse(string token) {
    int row = 0;
    int col = 0;
    for (int i = 0; i < token.length(); i++) {
        if (token[i] >= 'A' and token[i] <= 'Z') {
            col *= 26;
            col += token[i] - 'A' + 1;
        } else {
            row *= 10;
            row += token[i] - '0';
        }
    }
    return pair<int, int>(row, col);
}

long long process(int r, int c) {
    if (values[r][c] != -1) return values[r][c];

    long long ans = 0LL;
    if (raw_values[r][c][0] == '=') {
        istringstream iss(raw_values[r][c]);
        iss.seekg(1, ios::beg);  // skip 1 character

        string token;
        while (getline(iss, token, '+')) {
            pair<int, int> p = parse(token);
            ans += process(p.first, p.second);
        }
    } else {
        ans = stoll(raw_values[r][c]);
    }
    return values[r][c] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> C >> R;
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++) {
                cin >> raw_values[i][j];
                values[i][j] = -1;
            }

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (j > 1) cout << " ";
                cout << process(i, j);
            }
            cout << endl;
        }
    }
    return 0;
}