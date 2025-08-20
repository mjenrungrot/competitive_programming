# Title: Convolution (Large)
# URL: https://judge.yosupo.jp/problem/convolution_mod_large
# Category: Convolution

"""
Title: Convolution (Large)

Link: https://judge.yosupo.jp/problem/convolution_mod_large

Category: Convolution


Statement:
Given integer sequences $a_0, a_1, ..., a_{N - 1}$ and $b_0, b_1, ..., b_{M - 1}$. Calculate an integer sequence $c_0, c_1, ..., c_{(N - 1) + (M - 1)}$ as follows:

$$c_k = \sum_{i+j=k} a_ib_j \bmod 998244353$$


Constraints:
- $1 \leq N, M \leq 16777216$
- $0 \leq a_i, b_i < 998244353$


Input:
```
$N$ $M$
$a_0$ $a_1$ ... $a_{N-1}$
$b_0$ $b_1$ ... $b_{M-1}$
```


Output:
```
$c_0$ $c_1$ ... $c_{(N - 1) + (M - 1)}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'convolution_mod_large'
    pass


if __name__ == "__main__":
    solve()