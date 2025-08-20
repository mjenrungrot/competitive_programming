# Title: Stirling Number of the Second Kind (Small p, Large n)
# URL: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_small_p_large_n
# Category: Enumerative Combinatorics

"""
Title: Stirling Number of the Second Kind (Small p, Large n)

Link: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_small_p_large_n

Category: Enumerative Combinatorics


Statement:
The Stirling numbers of the second kind $S(n, k)$ are defined as the coefficients in the identity
$$x^n = \sum_{k=0}^n S(n, k) x (x - 1) \cdots (x - (k - 1)).$$

Given $n,k$ and $p$, where $p$ is a prime. Calculate $S(n, k) \bmod p$.

Each test consists of $T$ cases, and $p$ is fixed in all cases.


Constraints:
- $1 \leq T \leq 200000$
- $2 \leq p \leq 5000$
- $p$ is a prime.
- $0 \leq k \leq n \leq 1000000000000000000$


Input:
```
$T\ p$
$n_0\ k_0$
$n_1\ k_1$
$\vdots$
$n_{T-1}\ k_{T-1}$
```


Output:
For each line, print $S(n,k) \bmod p$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'stirling_number_of_the_second_kind_small_p_large_n'
    pass


if __name__ == "__main__":
    solve()