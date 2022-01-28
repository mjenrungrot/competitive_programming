#include <bits/stdc++.h>
using namespace std;
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

int main() {
    vector<point2d> P;
    P.emplace_back(2, 2);
    P.push_back({4, 3});
    P.push_back({2, 4});
    P.push_back({6, 6});

    line2d L1 = points_to_line(P[0], P[1]);
    cout << L1.a << "x + " << L1.b << "y + " << L1.c << " = 0" << endl;
    assert(fabs(L1.a + 0.5) < 1e-6 and fabs(L1.b - 1) < 1e-6 and
           fabs(L1.c + 1) < 1e-6);

    line2d L2 = points_to_line(P[0], P[2]);
    cout << L2.a << "x + " << L2.b << "y + " << L2.c << " = 0" << endl;
    assert(fabs(L2.a - 1) < 1e-6 and fabs(L2.b) < 1e-6 and
           fabs(L2.c + 2) < 1e-6);

    // is parallel
    line2d L3 = points_to_line(P[2], P[3]);
    cout << "L1 & L2 are parallel? " << are_parallel(L1, L2) << endl;  // no
    cout << "L1 & L3 are parallel? " << are_parallel(L1, L3)
         << endl;  // yes, l1 (P[0]-P[1]) and l3 (P[2]-P[3]) are parallel
    assert(not are_parallel(L1, L2));
    assert(are_parallel(L1, L3));

    // intersection point
    point2d p12;
    bool res =
        are_intersect(L1, L2, p12);  // yes, l1 (P[0]-P[1]) and l2 (P[0]-P[2])
                                     // are intersect at (2.0, 2.0)
    cout << "L1 & L2 are intersect? " << res << ", at (" << p12.x << ","
         << p12.y << ")" << endl;
    assert(res and fabs(p12.x - 2.0) < 1e-6 and fabs(p12.y - 2.0) < 1e-6);

    // Dist to line
    point2d ans;
    double d = dist_to_line(P[0], P[2], P[3], ans);
    cout << "Closest point from P[0] to line (P[2]-P[3]): (" << ans.x << ","
         << ans.y << ") [d = " << d << "]" << endl;
    assert(fabs(d - 1.78885) < 1e-3);
    assert(fabs(ans.x - 1.2) < 1e-6 and fabs(ans.y - 3.6) < 1e-6);

    ans = closest_point(L3, P[0]);
    cout << "Closest point from P[0] to line (P[2]-P[3]): (" << ans.x << ","
         << ans.y << ") [d = " << d << "]" << endl;
    assert(fabs(d - 1.78885) < 1e-3);
    assert(fabs(ans.x - 1.2) < 1e-6 and fabs(ans.y - 3.6) < 1e-6);

    // Dist to line segment
    d = dist_to_line_segment(P[0], P[2], P[3], ans);
    cout << "Closest point from P[0] to line SEGMENT (P[2]-P[3]): (" << ans.x
         << "," << ans.y << ") [d = " << d << "]" << endl;
    assert(fabs(d - 2.0) < 1e-6);
    assert(fabs(ans.x - 2.0) < 1e-6 and fabs(ans.y - 4.0) < 1e-6);

    d = dist_to_line_segment(P[1], P[2], P[3], ans);
    cout << "Closest point from P[1] to line SEGMENT (P[2]-P[3]): (" << ans.x
         << "," << ans.y << ") [d = " << d << "]" << endl;
    assert(fabs(d - 1.78885) < 1e-3);
    assert(fabs(ans.x - 3.2) < 1e-6 and fabs(ans.y - 4.6) < 1e-6);

    return 0;
}