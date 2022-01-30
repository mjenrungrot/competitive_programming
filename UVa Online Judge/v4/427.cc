/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        427.cc
#  Description:     UVa Online Judge - 427
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

struct point2d {
    double x, y;
    point2d() { x = y = 0.0; }
    point2d(double x, double y) : x(x), y(y) {}
};

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const double EPS = 1e-9;
string line;

/*
    __________________________
    |
    |     /\
    |    /  \                Y
    |   /    \
    |  /     /theta
    | /     /________________
    |/     / |
    |\    /  |
    | \  /   |
    |  \/    |

    |--- X ---|

    Suppose the piano's length = L
            the piano's width = W

    Total horizontal amount = L cos\theta + W sin \theta
    Extra horizontal amount = s = L cos\theta + W sin \theta - X

    Vertical amount for Y = h = s tan\theta + W cos \theta

    Condition for passing:

        (1) X >= W and Y >= W
        (2.a) s <= 0
        (2.b) s > 0 and h must not exceed Y at any theta in (0, 90)
*/

void solve() {
    istringstream iss(line);
    string token;

    vector<point2d> P;
    while (iss >> token) {
        vs vals = split(token, regex(","));
        P.emplace_back(stod(vals[0]), stod(vals[1]));
    }

    // P[0] = (width, length)
    if (P[0].x > P[0].y) swap(P[0].x, P[0].y);
    double W = P[0].x;
    double L = P[0].y;

    for (int i = 1; i < P.size(); i++) {
        if (P[i].x < W or P[i].y < W) {
            cout << 'N';
            continue;
        }

        bool found = false;
        for (double theta = 0.1 / 180.0 * M_PI; theta < M_PI / 2.0;
             theta += 0.1 / 180.0 * M_PI) {
            double s = L * cos(theta) + W * sin(theta) - P[i].x;
            if (s > 0.0) {
                double h = s * tan(theta) + W * cos(theta);
                if (h > P[i].y) {
                    found = true;
                    break;
                }
            }
        }

        if (found)
            cout << 'N';
        else
            cout << 'Y';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (getline(cin, line)) solve();

    return 0;
}