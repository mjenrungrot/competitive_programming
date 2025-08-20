# Title: Compositional Inverse of Formal Power Series (Large)
# URL: https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large
# Category: Polynomial

"""
Title: Compositional Inverse of Formal Power Series (Large)

Link: https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large

Category: Polynomial


Statement:
You are given a formal power series $f(x) = \sum_{i=0}^{N-1} a_i x^i \in \mathbb{F}\_{998244353}[[x]]$ with $a_0 = 0, a_1 \neq 0$.
Calculate the first $N$ terms of $f^{\langle -1 \rangle}(x) = \sum_{i=0}^{\infty} b_i x^i$ with $b_0 = 0$.
In other words, find $g(x) = \sum_{i=0}^{N-1} b_i x^i \in \mathbb{F}\_{998244353}[[x]]$ such that

$$
f(g(x)) \equiv g(f(x)) \equiv x \pmod{x^{N}}
$$

Print the coefficients modulo $998244353$.


Constraints:
- $2 \leq N \leq 131072$
- $0 \leq a_i < 998244353$
- $a_0 = 0$
- $a_1  \neq 0$


Input:
```
$N$
$a_0$ $a_1$ $\cdots$ $a_{N - 1}$
```


Output:
```
$b_0$ $b_1$ $\cdots$ $b_{N - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'compositional_inverse_of_formal_power_series_large'
    pass


if __name__ == "__main__":
    solve()