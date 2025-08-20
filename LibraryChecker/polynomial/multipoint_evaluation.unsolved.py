# Title: Multipoint Evaluation
# URL: https://judge.yosupo.jp/problem/multipoint_evaluation
# Category: Polynomial

"""
Title: Multipoint Evaluation

Link: https://judge.yosupo.jp/problem/multipoint_evaluation

Category: Polynomial


Statement:
Given a polynomial $f(x) = \sum_{i = 0}^{N - 1} c_i x^i \in \mathbb{Z}[x]$ and integer sequence $p_0, p_1, ..., p_{M - 1}$.
Print $f(p_i) \bmod 998244353$ for each $p_i$.


Constraints:
- $1 \leq N, M \leq 2^{17}(=131072)$
- $0 \leq c_i, p_i < 998244353$
- $c_{N - 1} \neq 0$


Input:
```
$N$ $M$
$c_0$ $c_1$ ... $c_{N-1}$
$p_0$ $p_1$ ... $p_{M-1}$
```


Output:
```
$f(p_0)$ $f(p_1)$ ... $f(p_{M-1})$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'multipoint_evaluation'
    pass


if __name__ == "__main__":
    solve()