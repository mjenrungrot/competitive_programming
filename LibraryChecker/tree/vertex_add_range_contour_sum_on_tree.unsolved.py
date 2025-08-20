# Title: Vertex Add Range Contour Sum on Tree
# URL: https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
# Category: Tree

"""
Title: Vertex Add Range Contour Sum on Tree

Link: https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree

Category: Tree


Statement:
Given a tree with $N$ vertices, where the $i$-th edge connects vertices $u_i$ and $v_i$. Value $a_i$ is written on the vertex $i$. Process the following $Q$ queries in order:

- `0 $p$ $x$`: $a_p \leftarrow a_p+x$
- `1 $p$ $l$ $r$`: Print the sum of the values written on the vertices whose distance from the vertex $p$ is in $[l,r)$.


Constraints:
- $1 \leq N \leq 100000$
- $1 \leq Q \leq 200000$
- $-1000000000 \leq a_i \leq 1000000000$
- $0 \leq u_i, v_i \leq N-1$
- $0 \leq p \leq N-1$
- $-1000000000 \leq x \leq 1000000000$
- $0 \leq l \lt r \leq N$


Input:
~~~
$N$ $Q$
$a_0$ $\cdots$ $a_{N-1}$
$u_0$ $v_0$
$\vdots$
$u_{N-2}$ $v_{N-2}$
$\mathrm{Query}_0$
$\vdots$
$\mathrm{Query}_{Q-1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'vertex_add_range_contour_sum_on_tree'
    pass


if __name__ == "__main__":
    solve()