# Title: Two-Edge-Connected Components
# URL: https://judge.yosupo.jp/problem/two_edge_connected_components
# Category: Graph

"""
Title: Two-Edge-Connected Components

Link: https://judge.yosupo.jp/problem/two_edge_connected_components

Category: Graph


Statement:
Given a undirected graph with $N$ vertices and $M$ edges. $i$-th edge is $(a_i, b_i)$. This graph may not be simple.
Please decompose this graph into two-edge-connected components.


Constraints:
- $1 \leq N \leq 200000$
- $1 \leq M \leq 200000$
- $0 \leq a_i, b_i < N$


Input:
~~~
$N$ $M$
$a_0$ $b_0$
$a_1$ $b_1$
:
$a_{M - 1}$ $b_{M - 1}$
~~~


Output:
Print the number of two-edge-connected components $K$ in the first line.
Following $K$ lines, print as follows. $l$ is the number of vertices of two-edge-connected components and $v_i$ is a vertex index.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'two_edge_connected_components'
    pass


if __name__ == "__main__":
    solve()