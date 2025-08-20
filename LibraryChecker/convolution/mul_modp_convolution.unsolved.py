# Title: Convolution on the Multiplicative Monoid of $\mathbb{Z} / P\mathbb{Z}$
# URL: https://judge.yosupo.jp/problem/mul_modp_convolution
# Category: Convolution

"""
Title: Convolution on the Multiplicative Monoid of $\mathbb{Z} / P\mathbb{Z}$

Link: https://judge.yosupo.jp/problem/mul_modp_convolution

Category: Convolution


Statement:
Given a prime $P$ and integer sequences $a_0, a_1, ..., a_{P - 1}$ and $b_0, b_1, ..., b_{P - 1}$. Calculate an integer sequence $c_0, c_1, ..., c_{P - 1}$ as follows:

$$c_k = \sum_{i \times j \equiv k \pmod{P}} a_i b_j \bmod 998244353$$


Constraints:
- $2 \leq P \leq 524288$
- $P$ is a prime
- $0 \leq a_i, b_i < 998244353$


Input:
```
$P$
$a_0$ $a_1$ ... $a_{P - 1}$
$b_0$ $b_1$ ... $b_{P - 1}$
```


Output:
```
$c_0$ $c_1$ ... $c_{P - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'mul_modp_convolution'
    pass


if __name__ == "__main__":
    solve()