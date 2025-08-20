# Title: Pow of Formal Power Series
# URL: https://judge.yosupo.jp/problem/pow_of_formal_power_series
# Category: Polynomial

"""
Title: Pow of Formal Power Series

Link: https://judge.yosupo.jp/problem/pow_of_formal_power_series

Category: Polynomial


Statement:
You are given a formal power series $f(x) = \sum_{i=0}^{N-1} a_i x^i \in \mathbb{F}\_{998244353}[[x]]$ and a non-negative integer $M$.
Calculate the first $N$ terms of $(f(x))^M = \sum_{i=0}^{\infty} b_i x^i$.


Constraints:
- $1 \leq N \leq 500000$
- $0 \leq M \leq 1000000000000000000$
- $0 \leq a_i < 998244353$


Input:
```
$N$ $M$
$a_0$ $a_1$ $\cdots$ $a_{N-1}$
```


Output:
```
$b_0$ $b_1$ $\cdots$ $b_{N - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'pow_of_formal_power_series'
    pass


if __name__ == "__main__":
    solve()