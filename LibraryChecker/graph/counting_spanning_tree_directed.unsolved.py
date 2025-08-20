# Title: Counting Spanning Trees (Directed)
# URL: https://judge.yosupo.jp/problem/counting_spanning_tree_directed
# Category: Graph

"""
Title: Counting Spanning Trees (Directed)

Link: https://judge.yosupo.jp/problem/counting_spanning_tree_directed

Category: Graph


Statement:
You are given a directed graph, consisting of $N$ vertices and $M$ edges. The $i$-th edge is directed from vertex $u_i$ to vertex $v_i$. This graph may not be simple.
You are also given a vertex $r$. 

Find the number of directed spanning trees whose root is the vertex $r$ (it means that all the vertices have to be reachable from $r$), modulo $998244353$.


Constraints:
- $1 \leq N \leq 500$
- $0 \leq M \leq 500000$
- $0 \leq r \lt N$
- $0 \leq u_i \lt N$
- $0 \leq v_i \lt N$


Input:
```
$N$ $M$ $r$
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
    # TODO: implement solution for 'counting_spanning_tree_directed'
    pass


if __name__ == "__main__":
    solve()