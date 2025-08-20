# Title: Counting Spanning Trees (Undirected)
# URL: https://judge.yosupo.jp/problem/counting_spanning_tree_undirected
# Category: Graph

"""
Title: Counting Spanning Trees (Undirected)

Link: https://judge.yosupo.jp/problem/counting_spanning_tree_undirected

Category: Graph


Statement:
You are given an undirected graph, consisting of $N$ vertices and $M$ edges. The $i$-th edge connects vertex $u_i$ and $v_i$. This graph may not be simple.

Find the number of spanning trees of the graph modulo $998244353$.


Constraints:
- $1 \leq N \leq 500$
- $0 \leq M \leq 500000$
- $0 \leq u_i \lt N$
- $0 \leq v_i \lt N$


Input:
```
$N$ $M$
$u_0$ $v_0$
$u_1$ $v_1$
$u_2$ $v_2$
$\vdots$
$u_{M-1}$ $v_{M-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'counting_spanning_tree_undirected'
    pass


if __name__ == "__main__":
    solve()