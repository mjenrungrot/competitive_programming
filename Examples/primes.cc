#include <bits/stdc++.h>
using namespace std;

namespace primes {

// info: O(n) sieve
// guide:
// [0]: Set n
int n;
vector<int> lp;
vector<int> primes;

// private
namespace {
uint64_t binpower(uint64_t base, uint64_t e, uint64_t mod) {
    uint64_t result = 1;
    base %= mod;
    while (e) {
        if (e & 1) result = (__uint128_t)result * base % mod;
        base = (__uint128_t)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(uint64_t n, uint64_t a, uint64_t d, int s) {
    uint64_t x = binpower(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = (__uint128_t)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
};

};  // namespace

void preprocess() {
    lp = vector<int>(n, 0);
    primes.clear();
}

void sieve() {
    // O(n) sieve up to n 
    for (int i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int)primes.size() and primes[j] <= lp[i] and
                        i * primes[j] <= n;
             ++j)
            lp[i * primes[j]] = primes[j];
    }
}

bool is_prime(int x) {
    // returns true if x is prime, else returns false.
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) return false;
    }
    return true;
}

bool is_prime_fast(uint64_t x) {
    // returns true if x is prime, else returns false.
    if (x < 2) return false;

    int r = 0;
    uint64_t d = x - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (x == a) return true;
        if (check_composite(x, a, d, r)) return false;
    }
    return true;
}

};  // namespace primes

int main() {
    primes::n = 40;
    primes::preprocess();
    primes::sieve();

    assert(primes::primes ==
           vector<int>({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}));

    assert(primes::is_prime(37));
    assert(not primes::is_prime(39));

    assert(primes::is_prime_fast(37));
    assert(not primes::is_prime_fast(39));

    assert(primes::is_prime_fast(1000000007LL));
    assert(primes::is_prime_fast(2147483647LL));  // 2^31 - 1 is prime
    assert(primes::is_prime_fast(4294967311LL));

    return 0;
}