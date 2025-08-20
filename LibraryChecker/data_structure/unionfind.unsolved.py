# Title: Unionfind
# URL: https://judge.yosupo.jp/problem/unionfind
# Category: Data Structure

"""
Title: Unionfind

Link: https://judge.yosupo.jp/problem/unionfind

Category: Data Structure


Statement:
We have an undirected graph with $N$ vertices and $0$ edges.
Process the following $Q$ queries in order:

- `$t_i$ = 0 $u_i$ $v_i$`: Add an edge $(u, v)$.
- `$t_i$ = 1 $u_i$ $v_i$`: If vertices $u, v$ are connected, print $1$. Otherwise, print $0$.


Constraints:
- $1 \leq N \leq 200000$
- $1 \leq Q \leq 200000$
- $0 \leq u_i, v_i \lt N$


Input:
~~~
$N$ $Q$
$t_1$ $u_1$ $v_1$
$t_2$ $u_2$ $v_2$
:
$t_Q$ $u_Q$ $v_Q$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'unionfind'
    pass


if __name__ == "__main__":
    solve()