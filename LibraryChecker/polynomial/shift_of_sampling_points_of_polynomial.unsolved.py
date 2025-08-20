# Title: Shift of Sampling Points of Polynomial
# URL: https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial
# Category: Polynomial

"""
Title: Shift of Sampling Points of Polynomial

Link: https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial

Category: Polynomial


Statement:
Given sampling points $f(0), f(1), \ldots , f(N - 1)$ of polynomial $f(x) \in \mathbb{F}_{998244353}[x]$ of degree less than $N$, compute $f(c ＋ i)$ for $i = 0, 1, \ldots , M - 1$.


Constraints:
- $1 \leq N,M \leq 524288$
- $0 \leq c, f(i) < 998244353$


Input:
```
$N$ $M$ $c$
$f(0)$ $f(1)$ ... $f(N - 1)$
```


Output:
```
$f(c)$ $f(c + 1)$ ... $f(c + M - 1)$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'shift_of_sampling_points_of_polynomial'
    pass


if __name__ == "__main__":
    solve()