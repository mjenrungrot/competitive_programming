# Title: $q$-Binomial Coefficient (Prime Mod)
# URL: https://judge.yosupo.jp/problem/q_binomial_coefficient_prime_mod
# Category: Enumerative Combinatorics

"""
Title: $q$-Binomial Coefficient (Prime Mod)

Link: https://judge.yosupo.jp/problem/q_binomial_coefficient_prime_mod

Category: Enumerative Combinatorics


Statement:
Given integers $n,k,q$ and a prime $m$, print $\binom{n}{k}_q \bmod m$.

Here, $\binom{n}{k}_q$ denotes the $q$-binomial coefficient. 
For the definition of $q$-binomial coefficient, see the [Gaussian binomial coefficient](https://en.wikipedia.org/wiki/Gaussian_binomial_coefficient).

Each test consists of $T$ cases, and $q$ and $m$ are fixed in all cases.


Constraints:
- $1 \leq T \leq 1000000$
- $1 \leq m \leq 1073741824$
- $m$ is a prime
- $0\leq q \lt m$
- $0 \leq n, k \lt \min(m, 10000000)$


Input:
```
$T\ m\ q$
$n_0\ k_0$
$n_1\ k_1$
$\vdots$
$n_{T-1}\ k_{T-1}$
```


Output:
For each line, print $\binom{n}{k}_q \bmod m$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'q_binomial_coefficient_prime_mod'
    pass


if __name__ == "__main__":
    solve()