/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        634.cc
#  Description:     UVa Online Judge - 634
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

namespace polygon {

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
void __print(point2d x) { cerr << "(" << x.x << "," << x.y << ")"; }

ftype dot(point2d a, point2d b) { return a.x * b.x + a.y * b.y; }
ftype norm(point2d a) { return dot(a, a); }
double abs(point2d a) { return sqrt(norm(a)); }
double proj(point2d a, point2d b) { return dot(a, b) / abs(b); }
double angle(point2d a, point2d b) { return acos(dot(a, b) / abs(a) / abs(b)); }
ftype cross(point2d a, point2d b) { return a.x * b.y - a.y * b.x; }

point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2) {
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}

point2d line_intersetct_segment(point2d p, point2d q, point2d A, point2d B) {
    // segment p-q nd line A-B
    double a = B.y - A.y, b = A.x - B.x, c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point2d((p.x * v + q.x * u) / (u + v),
                   (p.y * v + q.y * u) / (u + v));
}

struct polygon2d {
    vector<point2d> points;
    polygon2d() {}
    polygon2d(vector<point2d> x, const double EPS = 1e-9) : points(x) {
        if (not points.empty()) {
            if (abs(points.back() - points.front()) > EPS)
                points.push_back(points[0]);
        }
    }

    double perimeter() {
        double ans = 0.0;
        for (int i = 1; i < static_cast<int>(points.size()); ++i)
            ans += abs(points[i] - points[i - 1]);
        return ans;
    }

    double area() {
        double ans = 0.0;
        for (int i = 1; i < static_cast<int>(points.size()); ++i)
            ans += cross(points[i - 1], points[i]);
        return fabs(ans) / 2.0;
    }

    bool is_convex(const double EPS = 1e-9) {
        int N = static_cast<int>(points.size());
        if (N <= 3) return false;  // point or line
        bool first_turn =
            (cross(points[1] - points[0], points[2] - points[0]) > EPS);
        for (int i = 1; i < N - 1; ++i) {
            if ((cross(points[i + 1] - points[i],
                       points[(i + 2) == N ? 1 : i + 2] - points[i]) > EPS) !=
                first_turn)
                return false;
        }
        return true;
    }

    int inside_polygon(const point2d& p, const double EPS = 1e-9) {
        // 1 inside
        // 0 on polygon
        // -1 outside
        int N = static_cast<int>(points.size());
        if (N <= 3) return -1;

        bool on_polygon = false;
        for (int i = 0; i < N - 1; ++i) {
            if (fabs(abs(p - points[i]) + abs(p - points[i + 1]) -
                     abs(points[i] - points[i + 1])) < EPS) {
                on_polygon = true;
                break;
            }
        }
        if (on_polygon) return 0;

        double sum = 0.0;
        for (int i = 0; i < N - 1; ++i) {
            if (cross(points[i] - p, points[i + 1] - p) > EPS) {
                sum += angle(points[i] - p, points[i + 1] - p);
            } else {
                sum -= angle(points[i] - p, points[i + 1] - p);
            }
        }
        return fabs(sum) > M_PI ? 1 : -1;
    }

    polygon2d cut_polygon(const point2d& A, const point2d& B,
                          const double EPS = 1e-9) {
        polygon2d new_polygon;
        for (int i = 0; i < static_cast<int>(points.size()); ++i) {
            double left1 = cross(B - A, points[i] - A);
            double left2 = 0.0;
            if (i != static_cast<int>(points.size()) - 1)
                left2 = cross(B - A, points[i + 1] - A);
            if (left1 > -EPS)
                new_polygon.points.push_back(
                    points[i]);  // points[i] is on the left
            if (left1 * left2 < -EPS)
                new_polygon.points.push_back(line_intersetct_segment(
                    points[i], points[i + 1], A, B));  // crosses line AB
        }
        if ((not new_polygon.points.empty()) and
            (abs(new_polygon.points.back() - new_polygon.points.front()) >
             EPS)) {
            new_polygon.points.push_back(new_polygon.points.front());
        }
        return new_polygon;
    }

    polygon2d convex_hull_graham(const double EPS = 1e-9) {
        polygon2d hull;
        vector<point2d> P(points);
        int N = static_cast<int>(P.size());
        if (N <= 3) {
            if (abs(P[0] - P[N - 1]) > EPS) P.push_back(P[0]);
            for (auto& p : P) hull.points.push_back(p);
            return hull;
        }

        // find lower corner
        int P0 = min_element(P.begin(), P.end(),
                             [&](point2d a, point2d b) {
                                 if (fabs(a.y - b.y) > EPS) return a.y < b.y;
                                 return a.x < b.x;
                             }) -
                 P.begin();
        swap(P[0], P[P0]);

        // sort by pivot point
        sort(++P.begin(), P.end(), [&](point2d a, point2d b) {
            return cross(a - P[0], b - P[0]) > EPS;
        });

        // build hull
        hull.points.push_back(P[N - 1]);
        hull.points.push_back(P[0]);
        hull.points.push_back(P[1]);
        int i = 2;
        while (i < N) {
            int j = static_cast<int>(hull.points.size()) - 1;
            if (cross(hull.points[j] - hull.points[j - 1],
                      P[i] - hull.points[j - 1]) > EPS)
                hull.points.push_back(P[i++]);
            else
                hull.points.pop_back();
        }
        return hull;
    }

    polygon2d convex_hull_andrew(const double EPS = 1e-9) {
        vector<point2d> curr_points = points;

        int N = static_cast<int>(curr_points.size());
        int k = 0;
        polygon2d hull;
        hull.points.reserve(2 * N);

        sort(curr_points.begin(), curr_points.end(), [&](point2d a, point2d b) {
            if (fabs(a.y - b.y) > EPS) return a.y < b.y;
            return a.x < b.x;
        });

        // lower hull
        for (int i = 0; i < N; ++i) {
            while ((k >= 2) and
                   (cross(hull.points[k - 1] - hull.points[k - 2],
                          curr_points[i] - hull.points[k - 2]) < EPS))
                --k;
            hull.points[k++] = curr_points[i];
        }

        // upper hull
        for (int i = N - 2, t = k + 1; i >= 0; --i) {
            while ((k >= t) and
                   (cross(hull.points[k - 1] - hull.points[k - 2],
                          curr_points[i] - hull.points[k - 2]) < EPS))
                --k;
            hull.points[k++] = curr_points[i];
        }

        hull.points.resize(k);
        return hull;
    }

    polygon2d convex_hull(const double EPS = 1e-9) {
        return convex_hull_andrew(EPS);
    }

    polygon2d translate(const point2d& vec) {
        for (auto& p : points) {
            p += vec;
        }
        return *this;
    }

    polygon2d translate(double theta) {
        double rad = DEG_to_RAD(theta);
        for (auto& p : points) {
            double x = p.x;
            double y = p.y;
            p = point2d(x * cos(rad) - y * sin(rad),
                        x * sin(rad) + y * cos(rad));
        }
        return *this;
    }
};

};  // namespace polygon

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
int N;

void solve() {
    polygon::polygon2d poly;
    polygon::point2d P;

    for (int i = 1; i <= N; ++i) {
        double x, y;
        cin >> x >> y;
        poly.points.emplace_back(x, y);
    }
    poly.points.push_back(poly.points.front());

    double x, y;
    cin >> x >> y;
    P = polygon::point2d(x, y);

    if (poly.inside_polygon(P) > 0)
        cout << "T" << endl;
    else
        cout << "F" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N) {
        if (N == 0) break;
        solve();
    }

    return 0;
}