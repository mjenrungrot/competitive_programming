# Title: Static Range Inversions Query
# URL: https://judge.yosupo.jp/problem/static_range_inversions_query
# Category: Data Structure

"""
Title: Static Range Inversions Query

Link: https://judge.yosupo.jp/problem/static_range_inversions_query

Category: Data Structure


Statement:
You are given an integer sequence $(A_0, A_1, \ldots, A_{N-1})$ 
with the length $N$. Process the following $Q$ queries in order.

- `$l_i$ $r_i$`: Print the number of inversions in $(A_{l_i}, A_{l_i+1}, \ldots, A_{r_i-1})$

An inversion in a sequence $(B_0, B_1, \ldots, B_{M-1})$
is a pair of indices $(i, j)$ such that
$0 \leq i < j \lt M$ and $B_i \gt B_j$.


Constraints:
- $1 \leq N \leq 100000$
- $1 \leq Q \leq 100000$
- $0 \leq A_i \leq 1000000000$
- $0 \leq l_i \lt r_i \leq N$


Input:
```
$N$ $Q$
$A_0$ $A_1$ $\ldots$ $A_{N-1}$
$l_0$ $r_0$
$l_1$ $r_1$
$\vdots$
$l_{Q-1}$ $r_{Q-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'static_range_inversions_query'
    pass


if __name__ == "__main__":
    solve()