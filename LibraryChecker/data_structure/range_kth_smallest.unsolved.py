# Title: Range Kth Smallest
# URL: https://judge.yosupo.jp/problem/range_kth_smallest
# Category: Data Structure

"""
Title: Range Kth Smallest

Link: https://judge.yosupo.jp/problem/range_kth_smallest

Category: Data Structure


Statement:
You are given an integer sequence $a_0, a_1, ..., a_{N-1}$ with the length $N$.
Process the following $Q$ queries in order:

- `$l_i$ $r_i$ $k_i$`: Print $k_i+1$ th smallest value in $(a_{l_i}, a_{l_i + 1}, ..., a_{r_i - 1})$.


Constraints:
- $1 \leq N \leq 200000$
- $1 \leq Q \leq 200000$
- $0 \leq a_i \leq 1000000000$
- $0 \leq l_i < r_i \leq N$
- $0 \leq k_i < r_i - l_i$


Input:
~~~
$N$ $Q$
$a_0$ $a_1$ ... $a_{N - 1}$
$l_0$ $r_0$ $k_0$
$l_1$ $r_1$ $k_1$
:
$l_{Q-1}$ $r_{Q-1}$ $k_{Q-1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'range_kth_smallest'
    pass


if __name__ == "__main__":
    solve()