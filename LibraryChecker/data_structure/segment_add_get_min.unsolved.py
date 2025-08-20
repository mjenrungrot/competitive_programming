# Title: Segment Add Get Min
# URL: https://judge.yosupo.jp/problem/segment_add_get_min
# Category: Data Structure

"""
Title: Segment Add Get Min

Link: https://judge.yosupo.jp/problem/segment_add_get_min

Category: Data Structure


Statement:
There are $N$ segments $y = a_i x + b_i$ (where $x \in [l_i, r_i)$). Process $Q$ queries.

- `0 $l$ $r$ $a$ $b$`: Add a segment $y = ax + b$ (where $x \in [l, r)$)
- `1 $p$`: Find the minimal $y$ at $x = p$. If such $y$ doesn't exist, output `INFINITY`.


Constraints:
- $1 \leq N, Q \leq 200000$
- $-1000000000 \leq l_i \lt r_i \leq 1000000000$
- $|a_i|, |p| \leq 1000000000$
- $|b_i| \leq 1000000000000000000$


Input:
~~~
$N$ $Q$
$l_0$ $r_0$ $a_0$ $b_0$
$l_1$ $r_1$ $a_1$ $b_1$
:
$l_{N-1}$ $r_{N-1}$ $a_{N-1}$ $b_{N-1}$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'segment_add_get_min'
    pass


if __name__ == "__main__":
    solve()