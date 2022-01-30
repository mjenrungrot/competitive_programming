/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        209.cc
#  Description:     UVa Online Judge - 209
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
string line;

ii f(int num) {
    // num = 1 + 2 + ... + k + x        s.t. x < k+1

    // find earliest k that 1 + 2 + ... + k >= num
    int left = 1, right = 300, mid;
    while (left < right) {
        mid = (left + right) >> 1;

        if (mid * (mid + 1) / 2 >= num)
            right = mid;
        else
            left = mid + 1;
    }

    int r = left - 1;
    int c = num - r * (r + 1) / 2;
    return {r, c};
}

void solve() {
    istringstream iss(line);
    vi nums;

    int x;
    while (iss >> x) nums.emplace_back(x);
    sort(nums.begin(), nums.end());

    if (nums.size() == 3) {
        ii p1 = f(nums[0]);
        ii p2 = f(nums[1]);
        ii p3 = f(nums[2]);

        if (p1.first == p2.first) {
            int d = p2.second - p1.second;
            if (p3 == ii(p2.first + d, p2.second)) {
                cout << line << " are the vertices of a triangle" << endl;
                return;
            }
        }
        if (p1.second == p2.second) {
            int d = p2.first - p1.first;
            if (p3 == ii(p2.first, p2.second + d)) {
                cout << line << " are the vertices of a triangle" << endl;
                return;
            }
        }
    } else if (nums.size() == 4) {
        ii p1 = f(nums[0]);
        ii p2 = f(nums[1]);
        ii p3 = f(nums[2]);
        ii p4 = f(nums[3]);

        if (p1.first == p2.first) {
            int d = p2.second - p1.second;
            if (p3 == ii(p1.first + d, p1.second) and
                p4 == ii(p2.first + d, p2.second)) {
                cout << line << " are the vertices of a parallelogram" << endl;
                return;
            }
            if (p3 == ii(p1.first + d, p1.second + d) and
                p4 == ii(p2.first + d, p2.second + d)) {
                cout << line << " are the vertices of a parallelogram" << endl;
                return;
            }
        }
        if (p1.second == p2.second) {
            int d = p2.first - p1.first;
            if (p3 == ii(p1.first + d, p1.second + d) and
                p4 == ii(p2.first + d, p2.second + d)) {
                cout << line << " are the vertices of a parallelogram" << endl;
                return;
            }
        }
    } else if (nums.size() == 6) {
        ii p1 = f(nums[0]);
        ii p2 = f(nums[1]);
        ii p3 = f(nums[2]);
        ii p4 = f(nums[3]);
        ii p5 = f(nums[4]);
        ii p6 = f(nums[5]);

        if (p1.first == p2.first) {
            int d = p2.second - p1.second;
            if (p3 == ii(p1.first + d, p1.second) and
                p4 == ii(p2.first + d, p2.second + d) and
                p5 == ii(p3.first + d, p3.second + d) and
                p6 == ii(p4.first + d, p4.second)) {
                cout << line << " are the vertices of a hexagon" << endl;
                return;
            }
        }
    }
    cout << line << " are not the vertices of an acceptable figure" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (getline(cin, line)) solve();

    return 0;
}