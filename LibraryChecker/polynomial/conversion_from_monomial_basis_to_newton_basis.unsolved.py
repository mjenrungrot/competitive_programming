# Title: Conversion from Monomial Basis to Newton Basis
# URL: https://judge.yosupo.jp/problem/conversion_from_monomial_basis_to_newton_basis
# Category: Polynomial

"""
Title: Conversion from Monomial Basis to Newton Basis

Link: https://judge.yosupo.jp/problem/conversion_from_monomial_basis_to_newton_basis

Category: Polynomial


Statement:
You are given a polynomial $\displaystyle f(x) = \sum_{i=0}^{N-1} a_i x^i \in \mathbb{Z}[x]$ and integers $p_0, p_1, \ldots, p_{N-1}$.

Find $b_0, b_1, \ldots, b_{N-1}$ such that $\displaystyle f(x) = \sum_{i=0}^{N-1} b_i \prod_{j=0}^{i-1} (x-p_j)$ and print them modulo $998244353$.


Constraints:
- $0 \leq N \leq 131072$
- $0 \leq a_i, p_i \lt 998244353$


Input:
```
$N$
$a_0$ $a_1$ $\cdots$ $a_{N-1}$
$p_0$ $p_1$ $\cdots$ $p_{N-1}$
```


Output:
```
$b_0$ $b_1$ $\cdots$ $b_{N-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'conversion_from_monomial_basis_to_newton_basis'
    pass


if __name__ == "__main__":
    solve()