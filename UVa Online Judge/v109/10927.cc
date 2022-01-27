/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10927.cc
#  Description:     UVa Online Judge - 10927
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

typedef int ftype;

struct point2d {
    ftype x, y;
    point2d() {}
    point2d(ftype x, ftype y) : x(x), y(y) {}
    point2d& operator+=(const point2d& t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d& t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(ftype t) {
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(ftype t) {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d& t) const { return point2d(*this) += t; }
    point2d operator-(const point2d& t) const { return point2d(*this) -= t; }
    point2d operator*(ftype t) const { return point2d(*this) *= t; }
    point2d operator/(ftype t) const { return point2d(*this) /= t; }
};
point2d operator*(ftype a, point2d b) { return b * a; }

struct point3d {
    ftype x, y, z;
    point3d() {}
    point3d(ftype x, ftype y, ftype z) : x(x), y(y), z(z) {}
    point3d& operator+=(const point3d& t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator-=(const point3d& t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d& operator*=(ftype t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d& operator/=(ftype t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3d operator+(const point3d& t) const { return point3d(*this) += t; }
    point3d operator-(const point3d& t) const { return point3d(*this) -= t; }
    point3d operator*(ftype t) const { return point3d(*this) *= t; }
    point3d operator/(ftype t) const { return point3d(*this) /= t; }
};
point3d operator*(ftype a, point3d b) { return b * a; }

ftype dot(point2d a, point2d b) { return a.x * b.x + a.y * b.y; }
ftype dot(point3d a, point3d b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
ftype norm(point2d a) { return dot(a, a); }
double abs(point2d a) { return sqrt(norm(a)); }
double proj(point2d a, point2d b) { return dot(a, b) / abs(b); }
double angle(point2d a, point2d b) { return acos(dot(a, b) / abs(a) / abs(b)); }
point3d cross(point3d a, point3d b) {
    return point3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}
ftype triple(point3d a, point3d b, point3d c) { return dot(a, cross(b, c)); }
ftype cross(point2d a, point2d b) { return a.x * b.y - a.y * b.x; }

point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2) {
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}
point3d intersect(point3d a1, point3d n1, point3d a2, point3d n2, point3d a3,
                  point3d n3) {
    point3d x(n1.x, n2.x, n3.x);
    point3d y(n1.y, n2.y, n3.y);
    point3d z(n1.z, n2.z, n3.z);
    point3d d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
    return point3d(triple(d, y, z), triple(x, d, z), triple(x, y, d)) /
           triple(n1, n2, n3);
}

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
int N;
vector<point3d> points;
map<ii, int> tallest;  // (x,y) => height

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

void solve() {
    tallest.clear();
    points.clear();
    for (int i = 1; i <= N; i++) {
        int x, y, h;
        cin >> x >> y >> h;
        points.emplace_back(x, y, h);
    }

    sort(points.begin(), points.end(), [](const point3d& x, const point3d& y) {
        long long x1 = x.x;
        long long y1 = x.y;
        long long x2 = y.x;
        long long y2 = y.y;
        return (x1 * x1) + (y1 * y1) < (x2 * x2) + (y2 * y2);
    });

    vector<point2d> ans;
    for (auto& p : points) {
        int g = abs(gcd(p.x, p.y));
        int canonical_x = p.x / g;
        int canonical_y = p.y / g;

        if (not tallest.count({canonical_x, canonical_y}))
            tallest[{canonical_x, canonical_y}] = -INF_INT;

        if (p.z <= tallest[{canonical_x, canonical_y}]) {
            ans.emplace_back(p.x, p.y);
        }

        tallest[{canonical_x, canonical_y}] =
            max(tallest[{canonical_x, canonical_y}], p.z);
    }

    sort(ans.begin(), ans.end(), [](const point2d& x, const point2d& y) {
        if (x.x != y.x) return x.x < y.x;
        return x.y < y.y;
    });
    if (ans.empty()) {
        cout << "All the lights are visible." << endl;
    } else {
        cout << "Some lights are not visible:" << endl;
        for (int i = 0; i < ans.size(); i++) {
            auto p = ans[i];
            cout << "x = " << p.x << ", y = " << p.y;
            if (i == ans.size() - 1)
                cout << "." << endl;
            else
                cout << ";" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        if (N == 0) break;
        cout << "Data set " << ++n_test << ":" << endl;
        solve();
    }

    return 0;
}