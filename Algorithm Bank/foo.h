#ifndef FOO_H
#define FOO_H

#include <algorithm>
#include <vector>
using namespace std;

// Algebra Algorithm

// Calculate Euler function
// Runtime: O(sqrt N)
template <class T>
T EulerPhi(T n);

// Compute gcd and solve diophantine equation
// xA + yB = gcd(A,B)
// Runtime: O(log N) amortized
template <class T>
T gcd(T A, T B);
template <class T>
T gcd(T A, T B, T &x, T &y);

// Find primes [Sieve of Eratosthenes]
// Runtime: O(N)
// Ref: http://e-maxx.ru/algo/prime_sieve_linear
vector <int> generatePrime(int n);

// Binary Exponential: compute a^n
// Runtime: O(log n)
template <class T>
T power(T a, T n);
template <class T>
T power(T a, T n, T mod);


#endif