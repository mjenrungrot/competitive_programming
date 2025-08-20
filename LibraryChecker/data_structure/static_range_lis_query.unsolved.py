# Title: Static Range LIS Query
# URL: https://judge.yosupo.jp/problem/static_range_lis_query
# Category: Data Structure

"""
Title: Static Range LIS Query

Link: https://judge.yosupo.jp/problem/static_range_lis_query

Category: Data Structure


Statement:
You are given permutation $P$ of $\lbrace 0, 1, \dots, N-1 \rbrace$.
Process the following $Q$ queries in order:

- `$l$ $r$`: Print the length of the longest increasing subsequence of $(P_l, P_{l+1}, \dots, P_{r-1})$.


Constraints:
- $1 \leq N \leq 100000$
- $1 \leq Q \leq 100000$
- $P$ is a permutation of $\lbrace 0, 1, \dots, N-1 \rbrace$
- $0 \leq l_i \leq r_i \leq N$


Input:
```
$N$ $Q$
$P_0$ $P_1$ $\cdots$ $P_{N-1}$
$l_0$ $r_0$
$l_1$ $r_1$
$\vdots$
$l_{Q-1}$ $r_{Q-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'static_range_lis_query'
    pass


if __name__ == "__main__":
    solve()