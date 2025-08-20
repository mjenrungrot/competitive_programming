# Title: Cycle Detection (Undirected)
# URL: https://judge.yosupo.jp/problem/cycle_detection_undirected
# Category: Graph

"""
Title: Cycle Detection (Undirected)

Link: https://judge.yosupo.jp/problem/cycle_detection_undirected

Category: Graph


Statement:
You are given an undirected graph, consisting of $N$ vertices and $M$ edges.
The $i$-th edge connects vertex $u_i$ and $v_i$.
This graph may not be simple. 

A **cycle** is a pair of sequence of vertices $(v_0, \ldots, v_{L-1})$ and sequence of edges $(e_0, \ldots, e_{L-1})$ satisfying following conditions. 

- $L\geq 1$
- $i\neq j \implies v_i\neq v_j, e_i\neq e_j$
- For $0\leq i < L- 1$, the edge $e_i$ connects $v_i$ and $v_{i+1}$
- The edge $e_{L-1}$ connects $v_{L-1}$ and $v_{0}$

Determine if a cycle exists in $G$, and output it if exists. 
If there are multiple cycles, print any of them.


Constraints:
- $1 \leq N \leq 500000$
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


Output:
If there are no cycles, output ```-1```. Otherwise, output one of the cycles in the following format.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'cycle_detection_undirected'
    pass


if __name__ == "__main__":
    solve()