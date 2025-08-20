# Title: Power Projection of Set Power Series
# URL: https://judge.yosupo.jp/problem/power_projection_of_set_power_series
# Category: Set Power Series

"""
Title: Power Projection of Set Power Series

Link: https://judge.yosupo.jp/problem/power_projection_of_set_power_series

Category: Set Power Series


Statement:
Given an integer $M$, an $N$-variable polynomial $\displaystyle s(x _ 0, x _ 1, \dots, x _ {N - 1}) = \sum _ {i = 0} ^ {2 ^ N - 1} a _ i \prod _ {k = 0} ^ {N - 1} x _ k ^ {i _ k} \in \mathbb{F} _ {998244353} \lbrack x _ 0, x _ 1, \dots, x _ {N - 1} \rbrack$ and a sequence $(w _ 0, \ldots, w _ {2 ^ N - 1})$ of elements of $\mathbb{F} _ {998244353}$. Here, $i_k$ represents the number in the $2 ^ k$'s place when $i$ is expressed in binary.

For each $m=0,1,\ldots,M-1$, compute $\sum _ {i=0} ^ {2 ^ N - 1} w_ib_i$, where $b_i$ is defined by $s(x _ 0, x _ 1, \dots, x _ {N - 1})^m \equiv \sum _ {i = 0} ^ {2 ^ N - 1} b _ i \prod _ {k = 0} ^ {N - 1} x _ k ^ {i _ k} \pmod{(x _ 0 ^ 2, x _ 1 ^ 2, \dots, x _ {N - 1} ^ 2)}$.


Constraints:
- $0 \leq N \leq 20$
- $0 \leq M \leq 100000$
- $0 \leq a_i, w_i \lt 998244353$


Input:
```
$N$ $M$
$a _ 0$ $a _ 1$ $\cdots$ $a _ {2^N-1}$
$w _ 0$ $w _ 1$ $\cdots$ $w _ {2^N-1}$
```


Output:
```
$\mathrm{ans}_0$ $\mathrm{ans}_1$ $\cdots$ $\mathrm{ans}_{M-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'power_projection_of_set_power_series'
    pass


if __name__ == "__main__":
    solve()