# Title: Dynamic Tree Vertex Add Path Sum
# URL: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
# Category: Tree

"""
Title: Dynamic Tree Vertex Add Path Sum

Link: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum

Category: Tree


Statement:
Given tree of $N$ vertices. Edges are $(u_i, v_i)$. Value $a_i$ is written on vertex $i$.

Process the following $Q$ queries in order. You can assume that the graph is always the tree while processing the queries.

- `0 $u$ $v$ $w$ $x$`: Delete a edge $(u, v)$, and add $(w, x)$.
- `1 $p$ $x$`: $a_p \gets a_p + x$
- `2 $u$ $v$`: Print the sum of values of vertices of the path between $u$ and $v$ (inclusive).


Constraints:
- $1 \leq N, Q \leq 200,000$
- $0 \leq a_i, x \leq 10^9$
- $0 \leq p, u_i, v_i < N$
- $(u_i, v_i)$ is tree.
- for type 0 queries, there is a edge $(u, v)$.
- The graph is always tree.


Input:
~~~
$N$ $Q$
$a_0$ $a_1$ ... $a_{N - 1}$
$u_0$ $v_0$
$u_1$ $v_1$
:
$u_{N - 2}$ $v_{N - 2}$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'dynamic_tree_vertex_add_path_sum'
    pass


if __name__ == "__main__":
    solve()