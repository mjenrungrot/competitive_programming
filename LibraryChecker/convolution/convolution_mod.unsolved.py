# Title: Convolution
# URL: https://judge.yosupo.jp/problem/convolution_mod
# Category: Convolution

"""
Title: Convolution

Link: https://judge.yosupo.jp/problem/convolution_mod

Category: Convolution


Statement:
Given integer sequences $a_0, a_1, ..., a_{N - 1}$ and $b_0, b_1, ..., b_{M - 1}$. Calculate an integer sequence $c_0, c_1, ..., c_{(N - 1) + (M - 1)}$ as follows:

$$c_k = \sum_{i+j=k} a_i b_j \bmod 998244353$$


Constraints:
- $1 \leq N, M \leq 524288$
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
    # TODO: implement solution for 'convolution_mod'
    pass


if __name__ == "__main__":
    solve()