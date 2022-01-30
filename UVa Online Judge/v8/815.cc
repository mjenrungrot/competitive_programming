/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        815.cc
#  Description:     UVa Online Judge - 815
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

const double EPS = 1e-12;
const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int MAXM = 35;
const int MAXN = 35;
int M, N;
double elev[MAXM][MAXN];
double V;

void solve() {
    double left = -1e6, right = 1e6, mid;
    while (fabs(left - right) > EPS) {
        mid = (left + right) * 0.5;

        double h = mid;
        double total_water = 0.0;
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                if (elev[i][j] < h)
                    total_water += (h - elev[i][j]) * 10.0 * 10.0;

        if (total_water < V)
            left = mid + EPS;
        else
            right = mid;
    }
    double ans = left;

    int n_under_water = 0;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++) {
            if (elev[i][j] < ans) n_under_water++;
        }

    cout << "Water level is " << fixed << setprecision(2) << ans << " meters."
         << endl;

    double percent_under =
        static_cast<double>(n_under_water) / static_cast<double>(N * M) * 100.0;
    cout << fixed << setprecision(2) << percent_under
         << " percent of the region is under water." << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> M >> N) {
        if (M == 0 and N == 0) break;
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++) cin >> elev[i][j];
        cin >> V;

        cout << "Region " << ++n_test << endl;
        solve();
        cout << endl;
    }

    return 0;
}