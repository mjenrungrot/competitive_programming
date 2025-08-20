# Title: Log of Formal Power Series
# URL: https://judge.yosupo.jp/problem/log_of_formal_power_series
# Category: Polynomial

"""
Title: Log of Formal Power Series

Link: https://judge.yosupo.jp/problem/log_of_formal_power_series

Category: Polynomial


Statement:
You are given a formal power series $f(x) = \sum_{i=0}^{N-1} a_i x^i \in \mathbb{Q}[[x]]$ with $a_0 = 1$.
Calculate the first $N$ terms of $\log(f(x)) = \sum_{i=0}^{\infty} b_i x^i$.
In other words, find $g(x) = \sum_{i=0}^{N-1} b_i x^i \in \mathbb{Q}[[x]]$ such that $b_0 = 0$ and

$$f(x) \equiv \sum_{k=0}^{N-1} \frac{g(x)^k}{k!} \pmod{x^N}.$$

Print the coefficients modulo $998244353$.


Constraints:
- $1 \leq N \leq 500000$
- $0 \leq a_i < 998244353$
- $a_0 = 1$


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
    # TODO: implement solution for 'log_of_formal_power_series'
    pass


if __name__ == "__main__":
    solve()