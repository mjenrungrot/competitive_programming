# Title: Composition of Formal Power Series (Large)
# URL: https://judge.yosupo.jp/problem/composition_of_formal_power_series_large
# Category: Polynomial

"""
Title: Composition of Formal Power Series (Large)

Link: https://judge.yosupo.jp/problem/composition_of_formal_power_series_large

Category: Polynomial


Statement:
You are given two formal power series $f(x) = \sum_{i=0}^{N-1} a_i x^i \in \mathbb{F}\_{998244353}[[x]]$ and $g(x) = \sum_{i=0}^{N-1} b_i x^i \in \mathbb{F}\_{998244353}[[x]]$ with $b_0 = 0$.
Calculate the first $N$ terms of $f(g(x)) = \sum_{i=0}^{\infty} c_i x^i$.
In other words, find $h(x) = \sum_{i=0}^{N-1} c_i x^i \in \mathbb{F}\_{998244353}[[x]]$ such that

$$h(x) \equiv \sum_{i=0}^{N-1} a_i g(x)^i \pmod{x^N}.$$


Constraints:
- $1 \leq N \leq 131072$
- $0 \leq a_i, b_i < 998244353$
- $b_0 = 0$


Input:
```
$N$
$a_0$ $a_1$ $\cdots$ $a_{N - 1}$
$b_0$ $b_1$ $\cdots$ $b_{N - 1}$
```


Output:
```
$c_0$ $c_1$ $\cdots$ $c_{N - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'composition_of_formal_power_series_large'
    pass


if __name__ == "__main__":
    solve()