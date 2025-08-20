# Title: Multipoint Evaluation (Geometric Sequence)
# URL: https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence
# Category: Polynomial

"""
Title: Multipoint Evaluation (Geometric Sequence)

Link: https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence

Category: Polynomial


Statement:
Given a polynomial $f(x) = \sum_{i = 0}^{N - 1} c_i x^i\in \mathbb{Z}[x]$ and integers $M, a, r$. 
Print $f(ar^i) \bmod 998244353$ for each $0\leq i < M$.


Constraints:
- $1 \leq N, M \leq 524288$
- $0 \leq a, r < 998244353$


Input:
```
$N$ $M$ $a$ $r$
$c_0$ $c_1$ ... $c_{N-1}$
```


Output:
```
$f(ar^0)$ $f(ar^1)$ ... $f(ar^{M-1})$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'multipoint_evaluation_on_geometric_sequence'
    pass


if __name__ == "__main__":
    solve()