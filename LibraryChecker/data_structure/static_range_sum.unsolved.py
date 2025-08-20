# Title: Static Range Sum
# URL: https://judge.yosupo.jp/problem/static_range_sum
# Category: Data Structure

"""
Title: Static Range Sum

Link: https://judge.yosupo.jp/problem/static_range_sum

Category: Data Structure


Statement:
You are given a non-negative integer sequence $A = (a_0, a_1, \ldots, a_{N-1})$ with the length $N$. Process the following $Q$ queries in order:

- You are given integers $l_i$ and $r_i$. Print $\sum_{k=l_i}^{r_i-1} a_k$.


Constraints:
- $1 \leq N \leq 500000$
- $1 \leq Q \leq 500000$
- $0 \leq a_i \leq 1000000000$
- $0 \leq l_i < r_i \leq N$


Input:
```
$N$ $Q$
$a_0$ $a_1$ $\ldots$ $a_{N-1}$
$l_1$ $r_1$
$\vdots$
$l_Q$ $r_Q$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'static_range_sum'
    pass


if __name__ == "__main__":
    solve()