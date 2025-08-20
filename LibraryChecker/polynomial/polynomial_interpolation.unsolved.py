# Title: Polynomial Interpolation
# URL: https://judge.yosupo.jp/problem/polynomial_interpolation
# Category: Polynomial

"""
Title: Polynomial Interpolation

Link: https://judge.yosupo.jp/problem/polynomial_interpolation

Category: Polynomial


Statement:
Given integer sequences $x_0, x_1, ..., x_{N - 1}$ and $y_0, y_1, ..., y_{N - 1}$.

Calculate a polynomial $f(x) = \sum_{i = 0}^{N - 1} c_i x^i \in \mathbb{Z}[x]$ s.t. $f(x_i) \equiv y_i (\bmod 998244353)$ is satisfied for each $i$.

Also, $0 \leq c_i < 998244353$ must be satisfied.


Constraints:
- $1 \leq N \leq 2^{17}(=131072)$
- $0 \leq x_i, y_i < 998244353$
- $x_i \neq x_j (i \neq j)$


Input:
```
$N$
$x_0$ $x_1$ ... $x_{N-1}$
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
    # TODO: implement solution for 'polynomial_interpolation'
    pass


if __name__ == "__main__":
    solve()