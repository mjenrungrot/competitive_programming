# Title: Line Add Get Min
# URL: https://judge.yosupo.jp/problem/line_add_get_min
# Category: Data Structure

"""
Title: Line Add Get Min

Link: https://judge.yosupo.jp/problem/line_add_get_min

Category: Data Structure


Statement:
There are $N$ straight lines $y = a_i x + b_i$. Process $Q$ queries.

- `0 $a$ $b$`: Add a straight line $y = ax + b$.
- `1 $p$`: Find the minimal $y$ at $x = p$.


Constraints:
- $1 \leq N, Q \leq 200000$
- $|a_i|, |p| \leq 1000000000$
- $|b_i| \leq 1000000000000000000$


Input:
~~~
$N$ $Q$
$a_0$ $b_0$
$a_1$ $b_1$
:
$a_{N-1}$ $b_{N-1}$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'line_add_get_min'
    pass


if __name__ == "__main__":
    solve()