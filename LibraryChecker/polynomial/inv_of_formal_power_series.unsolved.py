# Title: Inv of Formal Power Series
# URL: https://judge.yosupo.jp/problem/inv_of_formal_power_series
# Category: Polynomial

"""
Title: Inv of Formal Power Series

Link: https://judge.yosupo.jp/problem/inv_of_formal_power_series

Category: Polynomial


Statement:
You are given a formal power series $f(x) = \sum_{i=0}^{N-1} a_i x^i \in \mathbb{F}\_{998244353}[[x]]$ with $a_0 \ne 0$.
Calculate the first $N$ terms of $\frac{1}{f(x)} = \sum_{i=0}^{\infty} b_i x^i$.
In other words, find $g(x) = \sum_{i=0}^{N-1} b_i x^i \in \mathbb{F}\_{998244353}[[x]]$ such that

$$f(x) g(x) \equiv 1 \pmod{x^N}.$$


Constraints:
- $1 \leq N \leq 500000$
- $0 \leq a_i < 998244353$
- $a_0 \neq 0$


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
    # TODO: implement solution for 'inv_of_formal_power_series'
    pass


if __name__ == "__main__":
    solve()