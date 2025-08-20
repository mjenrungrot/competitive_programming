# Title: Dynamic Tree Vertex Set Path Composite
# URL: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
# Category: Tree

"""
Title: Dynamic Tree Vertex Set Path Composite

Link: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite

Category: Tree


Statement:
Given an $N$ vertices tree. Edges are $(u_i, v_i)$ and a linear function $f_i(x) = a_i x + b_i$ is written on the vertex $i$ for each $i$.

Process $Q$ queries as follows. The graph remains a tree even after queries have been processed.

- `0 $u$ $v$ $w$ $x$`: Remove the existing edge $(u, v)$ and add the new edge $(w, x)$
- `1 $p$ $c$ $d$`: Set $f_p \gets cx + d$
- `2 $u$ $v$ $x$`: Let vertices on the path between $u$ and $v$ be $p_1 = u, p_2, ..., p_k = v$. Print $f_{p_k}(...f_{p_2}(f_{p_1}(x))) \bmod 998244353$


Constraints:
- $1 \leq N, Q \leq 200000$
- $1 \leq a_i, c < 998244353$
- $0 \leq b_i, d, x < 998244353$
- $0 \leq p < N$
- $0 \leq u, v < N$


Input:
~~~
$N$ $Q$
$a_0$ $b_0$
$a_1$ $b_1$
:
$a_{N - 1}$ $b_{N - 1}$
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
    # TODO: implement solution for 'dynamic_tree_vertex_set_path_composite'
    pass


if __name__ == "__main__":
    solve()