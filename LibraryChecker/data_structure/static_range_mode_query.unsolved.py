# Title: Static Range Mode Query
# URL: https://judge.yosupo.jp/problem/static_range_mode_query
# Category: Data Structure

"""
Title: Static Range Mode Query

Link: https://judge.yosupo.jp/problem/static_range_mode_query

Category: Data Structure


Statement:
You are given an integer sequence $a_0, a_1, \ldots, a_{N-1}$ with the length $N$. Process the following $Q$ queries in order:

- $l$ $r$ : Print a mode of $a_{l}, a_{l+1}, \ldots, a_{r-1}$, and the number of the occurrence of it. If there exists multiple modes, print any of them.


Constraints:
- $1 \leq N \leq 100000$
- $0 \leq Q \leq 100000$
- $0 \leq a_i \leq 1000000000$
- $0 \leq l \lt r \leq N$


Input:
```
$N$ $Q$
$a_0$ $a_1$ $\cdots$ $a_{N-1}$
$l_0$ $r_0$
$\vdots$
$l_{Q-1}$ $r_{Q-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'static_range_mode_query'
    pass


if __name__ == "__main__":
    solve()