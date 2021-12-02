/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        670.cc
#  Description:     UVa Online Judge - 670
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

vs split(string line) {
    vs output;
    istringstream iss(line);
    string tmp;
    while (iss >> tmp) {
        output.push_back(tmp);
    }
    return output;
}

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

int N, M;
vector<ii> points1, points2;
vvi Vleft;
vi visited, matchL, matchR;

double dist(ii x, ii y) {
    double dx = x.first - y.first;
    double dy = x.second - y.second;
    return sqrt(dx * dx + dy * dy);
}

int MCBM(int L) {
    if (visited[L]) return 0;
    visited[L] = 1;

    for (auto& R : Vleft[L]) {
        if (matchR[R] == -1 or MCBM(matchR[R])) {
            matchR[R] = L;
            matchL[L] = R;
            return 1;
        }
    }

    return 0;
}

void solve() {
    points1.clear();
    points2.clear();

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points1.emplace_back(x, y);
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        points2.emplace_back(x, y);
    }

    Vleft.clear();
    Vleft.assign(N - 1, vi());
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < M; j++) {
            double d1 = dist(points1[i], points1[i + 1]);
            double d2 =
                dist(points1[i], points2[j]) + dist(points2[j], points1[i + 1]);

            if (d2 <= 2 * d1) {
                Vleft[i].push_back(j);
            }
        }

    matchR.assign(M, -1);
    matchL.assign(N - 1, -1);
    int n_pairs = 0;
    for (int i = 0; i < N - 1; i++) {
        visited.assign(N - 1, 0);
        n_pairs += MCBM(i);
    }

    cout << N + n_pairs << endl;

    for (int i = 0; i < N - 1; i++) {
        cout << points1[i].first << " " << points1[i].second << " ";
        if (matchL[i] != -1)
            cout << points2[matchL[i]].first << " " << points2[matchL[i]].second
                 << " ";
    }
    cout << points1.back().first << " " << points1.back().second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
        if (T) cout << endl;
    }

    return 0;
}