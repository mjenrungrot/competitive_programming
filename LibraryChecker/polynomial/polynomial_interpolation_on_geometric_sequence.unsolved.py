# Title: Polynomial Interpolation (Geometric Sequence)
# URL: https://judge.yosupo.jp/problem/polynomial_interpolation_on_geometric_sequence
# Category: Polynomial

"""
Title: Polynomial Interpolation (Geometric Sequence)

Link: https://judge.yosupo.jp/problem/polynomial_interpolation_on_geometric_sequence

Category: Polynomial


Statement:
Given integers $N, a, r$ and integer sequence $y_0, y_1, ..., y_{N - 1}$.
It is guaranteed that $ar^i\not\equiv ar^j\pmod{998244353}$ for $0\leq i < j \leq N-1$. 

Calculate a polynomial $f(x) = \sum_{i = 0}^{N - 1} c_i x^i\in \mathbb{Z}[x]$ s.t. $f(ar^i) \equiv y_i \pmod{998244353}$ is satisfied for each $i$.

Also, $0 \leq c_i < 998244353$ must be satisfied.


Constraints:
- $0 \leq N \leq 524288$
- $0 \leq a < 998244353$
- $0 \leq r < 998244353$
- $0 \leq y_i < 998244353$
- $ar^i\not\equiv ar^j \pmod{998244353}$ $(0\leq i < j \leq N-1)$


Input:
```
$N$ $a$ $r$
$y_0$ $y_1$ ... $y_{N-1}$
```


Output:
```
$c_0$ $c_1$ ... $c_{N -1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'polynomial_interpolation_on_geometric_sequence'
    pass


if __name__ == "__main__":
    solve()