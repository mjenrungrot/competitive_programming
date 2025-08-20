# Title: Polynomial Taylor Shift
# URL: https://judge.yosupo.jp/problem/polynomial_taylor_shift
# Category: Polynomial

"""
Title: Polynomial Taylor Shift

Link: https://judge.yosupo.jp/problem/polynomial_taylor_shift

Category: Polynomial


Statement:
A Polynomial $f(x) = \sum_{i=0}^{N-1} a_ix^i \in \mathbb{Z}[x]$ and an integer $c$ is given.
Compute the sequence $b_0, b_1, \ldots, b_{N-1}$ satisfying $f(x+c) = \sum_{i=0}^{N-1}b_ix^i$, and print it modulo $998244353$.


Constraints:
- $1 \leq N \leq 524288$
- $0 \leq c, a_i < 998244353$


Input:
```
$N$ $c$
$a_0$ $a_1$ ... $a_{N-1}$
```


Output:
```
$b_0$ $b_1$ ... $b_{N - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'polynomial_taylor_shift'
    pass


if __name__ == "__main__":
    solve()