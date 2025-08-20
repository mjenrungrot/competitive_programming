# Title: Range Chmin Chmax Add Range Sum
# URL: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
# Category: Data Structure

"""
Title: Range Chmin Chmax Add Range Sum

Link: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum

Category: Data Structure


Statement:
Given a size $N$ integer sequence $a_0, a_1, \dots, a _ {N - 1}$. Process the following $Q$ queries in order:

- `0 $l$ $r$ $b$`: For each $i = l, \dots, {r-1}$, $a_i \gets \min(a_i, b)$
- `1 $l$ $r$ $b$`: For each $i = l, \dots, {r-1}$, $a_i \gets \max(a_i, b)$
- `2 $l$ $r$ $b$`: For each $i = l, \dots, {r-1}$, $a_i \gets a_i + b$
- `3 $l$ $r$`: Print $\sum _ {i = l} ^ {r-1} a_i$


Constraints:
- $1 \leq N, Q \leq 200000$
- $\vert a_i \vert \leq 1000000000000$ is satisfied always while processing queries. 
- $0 \leq l < r \leq N$


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
    # TODO: implement solution for 'range_chmin_chmax_add_range_sum'
    pass


if __name__ == "__main__":
    solve()