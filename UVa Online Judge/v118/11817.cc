/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11817.cc
#  Description:     UVa Online Judge - 11817
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

tuple<double, double, double> convert(double lat, double lon,
                                      double R = 6371009.0) {
    lat = lat / 180.0 * M_PI;
    lon = lon / 180.0 * M_PI;
    auto z = R * sin(lat);
    auto y = R * cos(lat) * sin(lon);
    auto x = R * cos(lat) * cos(lon);
    return tuple<double, double, double>(x, y, z);
}

void solve(double R = 6371009.0) {
    double lat1, lat2, lon1, lon2;
    cin >> lat1 >> lon1 >> lat2 >> lon2;

    auto p1 = convert(lat1, lon1, R);
    auto p2 = convert(lat2, lon2, R);

    auto dx = get<0>(p1) - get<0>(p2);
    auto dy = get<1>(p1) - get<1>(p2);
    auto dz = get<2>(p1) - get<2>(p2);
    auto d = sqrt(dx * dx + dy * dy + dz * dz);

    // cos(2x) = cos^2 x - sin^2 x = 2cos^2 x - 1
    // cos(alpha) = 2cos^2(alpha/2) - 1
    auto h = sqrt(R * R - (d / 2.0) * (d / 2.0));
    auto half_alpha = acos(h / R);
    auto alpha = half_alpha * 2.0;

    auto dist_earth = R * alpha;
    auto ans = dist_earth - d;
    cout << fixed << setprecision(0) << round(ans) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}