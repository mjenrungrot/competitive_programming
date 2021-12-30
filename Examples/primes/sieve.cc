#include <bits/stdc++.h>
using namespace std;

// O(n) sieve up to n
vector<int> sieve(int n) {
    vector<int> lp(n, 0);
    vector<int> primes;
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
    return primes;
}

int main() {
    auto primes = sieve(40);
    assert(primes == vector<int>({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}));

    return 0;
}