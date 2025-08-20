# Title: Point Add Range Sum
# URL: https://judge.yosupo.jp/problem/point_add_range_sum
# Category: Data Structure

"""
Title: Point Add Range Sum

Link: https://judge.yosupo.jp/problem/point_add_range_sum

Category: Data Structure


Statement:
You are given an integer sequence $a_0, a_1, ..., a_{N-1}$ with the length $N$.
Process the following $Q$ queries in order:

- `0 $p$ $x$`: $a_p \gets a_p + x$
- `1 $l$ $r$`: Print $\sum_{i = l}^{r - 1}{a_i}$


Constraints:
- $1 \leq N, Q \leq 500000$
- $0 \leq a_i, x \leq 1000000000$
- $0 \leq p < N$
- $0 \leq l_i < r_i \leq N$


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
    # TODO: implement solution for 'point_add_range_sum'
    pass


if __name__ == "__main__":
    solve()