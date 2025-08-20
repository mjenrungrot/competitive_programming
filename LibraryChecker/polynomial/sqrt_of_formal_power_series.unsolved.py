# Title: Sqrt of Formal Power Series
# URL: https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
# Category: Polynomial

"""
Title: Sqrt of Formal Power Series

Link: https://judge.yosupo.jp/problem/sqrt_of_formal_power_series

Category: Polynomial


Statement:
You are given a formal power series $f(x) = \sum_{i=0}^{N-1} a_i x^i \in \mathbb{F}\_{998244353}[[x]]$.
Calculate the first $N$ terms of a square root of $f(x)$.
In other words, find $g(x) = \sum_{i=0}^{N-1} b_i x^i \in \mathbb{F}\_{998244353}[[x]]$ such that

$$f(x) \equiv g(x)^2 \pmod{x^N}.$$


Constraints:
- $1 \leq N \leq 500000$
- $0 \leq a_i < 998244353$


Input:
```
$N$
$a_0$ $a_1$ $\cdots$ $a_{N - 1}$
```


Output:
If there are no $g(x)$ satisfying the condition, print
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'sqrt_of_formal_power_series'
    pass


if __name__ == "__main__":
    solve()