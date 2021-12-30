#include <bits/stdc++.h>
using namespace std;

inline int64_t extgcd(int64_t const a, int64_t const b, int64_t &x,
                      int64_t &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int64_t x1, y1;
    int64_t g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

// Modular Multiplicative Inverse
//
// returns (a ** -1) mod m
//   where gcd(a,m) == 1
// returns -1 if gcd(a,m) != 1
//
// Complexity:
//   Time: O( log(min(a,b)) )
//   Space: O(1)
//
// Algorithm:
//   Extended Euclidean Algorithm
// a * x + m * y = 1
// (a * x + m * y = 1) mod m
// (a * x = 1) mod m
// (x = a ** -1) mod m
//
int64_t modinv(int64_t a, int64_t m) {
    int64_t x, y;
    auto g = extgcd(a, m, x, y);
    if (g != 1) {
        // There is no modular multiplicative inverse
        return -1;
    }
    return (x % m + m) % m;
}

int main() {
    int64_t a = 3;
    int64_t m = 1000000007;
    auto ans = modinv(a, m);
    cout << ans << endl;

    return 0;
}