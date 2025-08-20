# Title: Static Range Count Distinct
# URL: https://judge.yosupo.jp/problem/static_range_count_distinct
# Category: Data Structure

"""
Title: Static Range Count Distinct

Link: https://judge.yosupo.jp/problem/static_range_count_distinct

Category: Data Structure


Statement:
You are given an integer sequence $a_0, a_1, \ldots, a_{N-1}$ with the length $N$. Process the following $Q$ queries in order:

- $l$ $r$ : Print the number of distinct integers that occur in $a_{l}, a_{l+1}, \ldots, a_{r-1}$.


Constraints:
- $0 \leq N \leq 500000$
- $0 \leq Q \leq 500000$
- $0 \leq a_i \leq 1000000000$
- $0 \leq l \leq r \leq N$


Input:
```
$N$ $Q$
$a_0$ $a_1$ $\cdots$ $a_{N-1}$
$l_0$ $r_0$
$l_1$ $r_1$
$\vdots$
$l_{Q-1}$ $r_{Q-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'static_range_count_distinct'
    pass


if __name__ == "__main__":
    solve()