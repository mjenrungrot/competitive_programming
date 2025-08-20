# Title: Edge Coloring of Bipartite Graph
# URL: https://judge.yosupo.jp/problem/bipartite_edge_coloring
# Category: Graph

"""
Title: Edge Coloring of Bipartite Graph

Link: https://judge.yosupo.jp/problem/bipartite_edge_coloring

Category: Graph


Statement:
Given an undirected bipartite graph with $L + R$ vertices and $M$ edges. $i$-th edge is $(a_i, b_i)$.

Calculate the proper edge coloring which gives the edge chromatic number.


Constraints:
- $1 \leq L, R \leq 100000$
- $1 \leq M \leq  100000$
- $0 \leq a_i < L$
- $0 \leq b_i < R$


Input:
~~~
$L$ $R$ $M$
$a_0$ $b_0$
$a_1$ $b_1$
$\vdots$
$a_{M - 1}$ $b_{M - 1}$
~~~


Output:
$K$ is the edge chromatic number, and $c_i$ is the integer which repersents the color of the i-th edge. $c_i$ should satisfy $0 \leq c_i < K$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'bipartite_edge_coloring'
    pass


if __name__ == "__main__":
    solve()