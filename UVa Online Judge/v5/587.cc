/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        587.cc
#  Description:     UVa Online Judge - 587
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef double ftype;
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
string line;

void solve() {
    istringstream iss(line);

    point2d curr(0.0, 0.0);
    const double F = sqrt(1.0 / 2.0);

    int num;
    while (iss >> num) {
        string dir = "";
        char ch;
        while (iss >> ch) {
            if (ch == '.' or ch == ',') break;
            dir += ch;
        }

        double d = num;
        if (dir == "N")
            curr += point2d(0.0, d);
        else if (dir == "S")
            curr += point2d(0.0, -d);
        else if (dir == "E")
            curr += point2d(d, 0.0);
        else if (dir == "W")
            curr += point2d(-d, 0.0);
        else if (dir == "NE")
            curr += point2d(d, d) * F;
        else if (dir == "NW")
            curr += point2d(-d, d) * F;
        else if (dir == "SE")
            curr += point2d(d, -d) * F;
        else if (dir == "SW")
            curr += point2d(-d, -d) * F;
    }

    cout << fixed << setprecision(3);
    cout << "The treasure is located at (" << curr.x << "," << curr.y << ")."
         << endl;
    cout << "The distance to the treasure is " << abs(curr) << "." << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> line) {
        if (line == "END") break;
        cout << "Map #" << ++n_test << endl;
        solve();
        cout << endl;
    }

    return 0;
}