# Title: Convolution on the Multiplicative Monoid of $\mathbb{Z} / 2^N\mathbb{Z}$
# URL: https://judge.yosupo.jp/problem/mul_mod2n_convolution
# Category: Convolution

"""
Title: Convolution on the Multiplicative Monoid of $\mathbb{Z} / 2^N\mathbb{Z}$

Link: https://judge.yosupo.jp/problem/mul_mod2n_convolution

Category: Convolution


Statement:
Given integer sequences $a_0, a_1, ..., a_{2^N - 1}$ and $b_0, b_1, ..., b_{2^N - 1}$. Calculate an integer sequence $c_0, c_1, ..., c_{2^N - 1}$ as follows:

$$c_k = \sum_{i \times j \equiv k \pmod{2^N}} a_i b_j \bmod 998244353$$


Constraints:
- $0 \leq N \leq 20$
- $0 \leq a_i, b_i < 998244353$


Input:
```
$N$
$a_0$ $a_1$ ... $a_{2^N - 1}$
$b_0$ $b_1$ ... $b_{2^N - 1}$
```


Output:
```
$c_0$ $c_1$ ... $c_{2^N - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'mul_mod2n_convolution'
    pass


if __name__ == "__main__":
    solve()