/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10422.cc
#  Description:     UVa Online Judge - 10422
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef tuple<long long, long long, long long> lll;
typedef tuple<double, double, double> ddd;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<dd> vdd;

// Debug Snippets

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V>& x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T& x) {
    int f = 0;
    cerr << '{';
    for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)

template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << " ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "[ " << p.first << ", " << p.second << "]";
}

// End Debug Snippets

vs split(string line, regex re) {
    vs output;
    sregex_token_iterator it(line.begin(), line.end(), re, -1), it_end;
    while (it != it_end) {
        output.push_back(it->str());
        it++;
    }
    return output;
}

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int N = 5;
const int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dx[] = {1, -1, 2, -2, 2, -2, 1, -1};

string lines[N];

struct state {
    int r, c;
    char A[N][N];
    state() {}

    state(string* lines) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                A[i][j] = lines[i][j];
                if (lines[i][j] == ' ') {
                    r = i;
                    c = j;
                }
            }
    }

    bool move(int k) {
        if (r + dy[k] < 0 or r + dy[k] >= N) return false;
        if (c + dx[k] < 0 or c + dx[k] >= N) return false;
        swap(A[r][c], A[r + dy[k]][c + dx[k]]);
        r += dy[k];
        c += dx[k];
        return true;
    }

    bool operator==(const struct state& x) {
        if (this->r != x.r) return false;
        if (this->c != x.c) return false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (this->A[i][j] != x.A[i][j]) return false;

        return true;
    }
};

void solve() {
    for (int i = 0; i < N; i++) getline(cin, lines[i]);

    state start(lines), target;
    target.r = target.c = 2;
    target.A[0][0] = '1';
    target.A[0][1] = '1';
    target.A[0][2] = '1';
    target.A[0][3] = '1';
    target.A[0][4] = '1';
    target.A[1][0] = '0';
    target.A[1][1] = '1';
    target.A[1][2] = '1';
    target.A[1][3] = '1';
    target.A[1][4] = '1';
    target.A[2][0] = '0';
    target.A[2][1] = '0';
    target.A[2][2] = ' ';
    target.A[2][3] = '1';
    target.A[2][4] = '1';
    target.A[3][0] = '0';
    target.A[3][1] = '0';
    target.A[3][2] = '0';
    target.A[3][3] = '0';
    target.A[3][4] = '1';
    target.A[4][0] = '0';
    target.A[4][1] = '0';
    target.A[4][2] = '0';
    target.A[4][3] = '0';
    target.A[4][4] = '0';

    queue<pair<int, state>> Q;
    Q.push({0, start});

    int ans = -INF_INT;
    while (not Q.empty()) {
        auto u = Q.front();
        Q.pop();

        if (u.second == target) {
            ans = u.first;
            break;
        }

        if (u.first == 10) {
            continue;
        }

        for (int k = 0; k < 8; k++) {
            state tmp = u.second;
            if (tmp.move(k)) {
                Q.push({u.first + 1, tmp});
            }
        }
    }

    if (ans == -INF_INT) {
        cout << "Unsolvable in less than 11 move(s)." << endl;
    } else {
        cout << "Solvable in " << ans << " move(s)." << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        solve();
    }

    return 0;
}