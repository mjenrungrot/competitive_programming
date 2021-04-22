/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        654.cc
#  Description:     UVa Online Judge - 654
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

class frac {
   public:
    inline bool operator<(frac y) { return this->a * y.b < y.a * this->b; }

    inline bool operator<=(frac y) { return !(y < *this); }

    inline bool operator==(frac y) { return this->a * y.b == y.a * this->b; }

    frac operator-(const frac y) {
        //  a/b  - y.a/y.b ===> a * y.b - y.a * b / b * y.b
        return frac(a * y.b - y.a * b, b * y.b);
    }

    frac absolute() { return frac(abs(a), abs(b)); }

    frac reduce() { return frac(a, b); }

    long long a, b;

    frac(long long a, long long b) : a(a), b(b) {
        long long gg = __gcd(a, b);
        a /= gg;
        b /= gg;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long x, y;
    bool newline = false;
    while (cin >> x >> y) {
        if (newline) {
            cout << endl;
        }
        newline = true;

        frac target(x, y);
        frac best_dist(1e9, 1);
        for (int denom = 1; denom <= y; denom++) {
            frac curr_r(x * denom / y + 1, denom);
            frac curr_l(x * denom / y, denom);
            frac dist_r = (curr_r - target).absolute();
            frac dist_l = (curr_l - target).absolute();

            if (dist_r <= dist_l and dist_r < best_dist) {
                best_dist = dist_r;
                cout << curr_r.a << "/" << curr_r.b << endl;
            } else if (dist_l <= dist_r and dist_l < best_dist) {
                best_dist = dist_l;
                cout << curr_l.a << "/" << curr_l.b << endl;
            }
        }
    }
    return 0;
}