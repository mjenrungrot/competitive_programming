#include <bits/stdc++.h>
using namespace std;

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1) result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
};

bool MillerRabin(
    u64 n,
    int iter = 5) {  // returns true if n is probably prime, else returns false.
    if (n < 4) return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s)) return false;
    }
    return true;
}

bool MillerRabin_deterministic(
    u64 n) {  // returns true if n is prime, else returns false.
    if (n < 2) return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (check_composite(n, a, d, r)) return false;
    }
    return true;
}

int main() {
    assert(not MillerRabin(1312315LL, 10));
    assert(MillerRabin(1000000007LL, 10));
    assert(MillerRabin(2147483647LL, 10));  // 2^31 - 1 is prime
    assert(MillerRabin(4294967311LL, 10));

    assert(MillerRabin_deterministic(1000000007LL));
    assert(MillerRabin_deterministic(2147483647LL));  // 2^31 - 1 is prime
    assert(MillerRabin_deterministic(4294967311LL));
    return 0;
}