# Title: Dynamic Tree Vertex Add Subtree Sum
# URL: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum
# Category: Tree

"""
Title: Dynamic Tree Vertex Add Subtree Sum

Link: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum

Category: Tree


Statement:
You are given a tree with $N$ vertices. Its edges are $(u_i, v_i)$. Its $i$-th vertex has a value $a_i$ written on it.

Process $Q$ queries. It is guaranteed that the graph is a tree after each query.

- `0 $u$ $v$ $w$ $x$`: Remove an edge $(u, v)$ and add an edge $(w, x)$.
- `1 $p$ $x$`: $a_p \gets a_p + x$
- `2 $v$ $p$`: For an edge $(v, p)$ where $p$ is considered the parent, output the sum of weights of all vertices in the subtree of $v$.


Constraints:
- $1 \leq N, Q \leq 200,000$
- $0 \leq a_i, x \leq 10^9$
- $0 \leq p, u_i, v_i < N$
- $(u_i, v_i)$ is a tree


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
    # TODO: implement solution for 'dynamic_tree_vertex_add_subtree_sum'
    pass


if __name__ == "__main__":
    solve()