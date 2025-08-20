# Title: Dynamic Graph Vertex Add Component Sum
# URL: https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
# Category: Graph

"""
Title: Dynamic Graph Vertex Add Component Sum

Link: https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum

Category: Graph


Statement:
You are given an empty graph with $N$ vertices. The $i$-th vertex has a value $a_i$ written on it.

Process $Q$ queries:

- `0 $u$ $v$` : Add an edge between vertex $u$ and vertex $v$. (It is guaranteed that, immediately before this query, there is no edge between vertex $u$ and vertex $v$)
- `1 $u$ $v$` : Remove the edge between vertex $u$ and vertex $v$. (It is guaranteed that, immediately before this query, there is an edge between vertex $u$ and vertex $v$)
- `2 $v$ $x$` : $a_v \gets a_v + x$
- `3 $v$ `   : Output the sum of values on all vertices that are connected to vertex $v$ by a path.


Constraints:
- $1 \leq N, Q \leq 300000$
- $0 \leq a_i, x \leq 1000000000$
- $0 \leq u_i, v_i < N$
- $u_i \neq v_i$


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
    # TODO: implement solution for 'dynamic_graph_vertex_add_component_sum'
    pass


if __name__ == "__main__":
    solve()