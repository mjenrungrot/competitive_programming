# Title: Range Linear Add Range Min
# URL: https://judge.yosupo.jp/problem/range_linear_add_range_min
# Category: Data Structure

"""
Title: Range Linear Add Range Min

Link: https://judge.yosupo.jp/problem/range_linear_add_range_min

Category: Data Structure


Statement:
Given a size $N$ integer sequence $a_0, a_1, \dots, a_{N - 1}$. Process $Q$ queries as follows:

- `0 $l$ $r$ $b$ $c$`: For each $i = l, l+1, \dots, {r - 1}$, $a_i \gets a_i+bi+c$.
- `1 $l$ $r$`: Print $\min_{i \in [l,r)} a_i$.


Constraints:
- $1 \leq N, Q \leq 100000$
- $|a_i| < 1000000000$
- $0 \leq l < r\leq N$
- $|b| < 100$
- $|c| < 10000000$


Input:
~~~
$N$ $Q$
$a_0$ $a_1$ ... $a_{N - 1}$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'range_linear_add_range_min'
    pass


if __name__ == "__main__":
    solve()