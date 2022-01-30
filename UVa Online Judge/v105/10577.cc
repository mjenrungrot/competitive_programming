/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10577.cc
#  Description:     UVa Online Judge - 10577
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

typedef double ftype;

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

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

    point2d rotate(double theta) const {
        double rad = DEG_to_RAD(theta);
        return point2d(x * cos(rad) - y * sin(rad),
                       x * sin(rad) + y * cos(rad));
    }
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

struct line2d {
    double a, b, c;

    line2d() {}
    line2d(double a, double b, double c) : a(a), b(b), c(c) {}
};

line2d points_to_line(const point2d& p1, const point2d& p2,
                      const double EPS = 1e-9) {
    if (fabs(p1.x - p2.x) < EPS)
        return line2d(1.0, 0.0, -p1.x);
    else {
        double a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        return line2d(a, 1.0, -(double)(a * p1.x) - p1.y);
    }
}

inline bool are_parallel(const line2d& l1, const line2d& l2,
                         const double EPS = 1e-9) {
    return (fabs(l1.a - l2.a) < EPS) and (fabs(l1.b - l2.b) < EPS);
}
inline bool are_same(const line2d& l1, const line2d& l2,
                     const double EPS = 1e-9) {
    return are_parallel(l1, l2, EPS) && (fabs(l1.c - l2.c) < EPS);
}
// returns true (+ intersection point p) if two lines are intersect
bool are_intersect(const line2d& l1, const line2d& l2, point2d& p,
                   const double EPS = 1e-9) {
    if (are_parallel(l1, l2, EPS)) return false;  // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true;
}
line2d point_slope_to_line(const point2d& p, double m) {
    return line2d(-m, 1.0, -((-m * p.x) + (1.0 * p.y)));
}
point2d closest_point(const line2d& l, const point2d& p,
                      const double EPS = 1e-9) {
    // vertical
    if (fabs(l.b) < EPS) return point2d(-l.c, p.y);
    // horizontal
    if (fabs(l.a) < EPS) return point2d(p.x, -l.c);

    line2d perpendicular = point_slope_to_line(p, 1.0 / l.a);
    point2d ans;
    are_intersect(l, perpendicular, ans);
    return ans;
}
double dist_to_line(const point2d& p, const point2d& a, const point2d& b,
                    point2d& closest) {
    point2d vec_ap = p - a;
    point2d vec_ab = b - a;
    double u = dot(vec_ap, vec_ab) / norm(vec_ab);
    closest = a + (vec_ab * u);
    return abs(closest - p);
}
double dist_to_line_segment(const point2d& p, const point2d& a,
                            const point2d& b, point2d& closest) {
    point2d vec_ap = p - a;
    point2d vec_ab = b - a;
    double u = dot(vec_ap, vec_ab) / norm(vec_ab);
    if (u < 0.0) {
        closest.x = a.x;
        closest.y = a.y;
        return abs(closest - p);
    }
    if (u > 1.0) {
        closest.x = b.x;
        closest.y = b.y;
        return abs(closest - p);
    }
    return dist_to_line(p, a, b, closest);
}

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const double EPS = 1e-6;
int N;
vector<point2d> P;

void solve() {
    P.clear();

    for (int i = 1; i <= 3; i++) {
        double x, y;
        cin >> x >> y;
        P.emplace_back(x, y);
    }

    /*
          A {P[0]}
          /\
         /  \
        /    \
        ------
       B      C
    */

    // find center
    point2d middle_BC = (P[1] + P[2]) / 2.0;
    point2d perp_BC = (P[2] - P[1]).rotate(90);
    line2d L1 = points_to_line(middle_BC, middle_BC + perp_BC);

    point2d middle_AC = (P[0] + P[2]) / 2.0;
    point2d perp_AC = (P[2] - P[0]).rotate(90);
    line2d L2 = points_to_line(middle_AC, middle_AC + perp_AC);

    point2d center;
    bool res = are_intersect(L1, L2, center);
    assert(res);

    double r = abs(center - P[0]);

    // assume P[0] is the first point
    point2d center_p0_vec = P[0] - center;

    double min_x = P[0].x, max_x = P[0].x, min_y = P[0].y, max_y = P[0].y;
    for (int i = 1; i <= N - 1; i++) {
        double i_ang = 360.0 * static_cast<double>(i) / static_cast<double>(N);
        point2d i_vec = center_p0_vec.rotate(i_ang);
        point2d generated_i = center + i_vec / abs(i_vec) * r;

        min_x = min(min_x, generated_i.x);
        max_x = max(max_x, generated_i.x);
        min_y = min(min_y, generated_i.y);
        max_y = max(max_y, generated_i.y);
    }

    double ans = (max_x - min_x) * (max_y - min_y);
    cout << fixed << setprecision(3) << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (cin >> N) {
        if (N == 0) break;
        cout << "Polygon " << ++n_test << ": ";
        solve();
    }

    return 0;
}