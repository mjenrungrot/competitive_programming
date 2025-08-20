# Title: Cycle Detection (Directed)
# URL: https://judge.yosupo.jp/problem/cycle_detection
# Category: Graph

"""
Title: Cycle Detection (Directed)

Link: https://judge.yosupo.jp/problem/cycle_detection

Category: Graph


Statement:
You are given a graph, consisting of $N$ vertices and $M$ edges.

The $i$-th edge is directed from vertex $u_i$ to vertex $v_i$.

Find and report an **edge-disjoint** cycle in given graph, or report that no such cycle exists.

If there are multiple cycles, print any of them.


Constraints:
- $2 \leq N \leq 500000$
- $1 \leq M \leq 500000$
- $0 \leq u_i \lt N$
- $0 \leq v_i \lt N$
- $u_i \neq v_i$


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
If there are no cycles, output ```-1```.

Otherwise, output one of the cycles in the following format. $e_i$ denotes the ID of $i$-th edge to use. Note that $(e_0, e_1, \ldots, e_{L-1})$ must be a cycle, and $e_i$ must not be equal to $e_j$ if $i \neq j$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'cycle_detection'
    pass


if __name__ == "__main__":
    solve()