# Title: Vertex Add Path Sum
# URL: https://judge.yosupo.jp/problem/vertex_add_path_sum
# Category: Tree

"""
Title: Vertex Add Path Sum

Link: https://judge.yosupo.jp/problem/vertex_add_path_sum

Category: Tree


Statement:
Given a tree of $N$ vertices. Edges are $(u_i, v_i)$. Value $a_i$ is written on the vertex $i$.

Process the following $Q$ queries in order:

- `0 $p$ $x$`: $a_p \gets a_p + x$
- `1 $u$ $v$`: Print the sum of the values of vertices of the path between vertex $u$ and $v$ (inclusive).


Constraints:
- $1 \leq N, Q \leq 500000$
- $0 \leq a_i, x \leq 1000000000$
- $0 \leq p, u_i, v_i < N$


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
    # TODO: implement solution for 'vertex_add_path_sum'
    pass


if __name__ == "__main__":
    solve()