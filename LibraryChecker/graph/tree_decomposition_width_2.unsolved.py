# Title: Tree Decomposition (Width 2)
# URL: https://judge.yosupo.jp/problem/tree_decomposition_width_2
# Category: Graph

"""
Title: Tree Decomposition (Width 2)

Link: https://judge.yosupo.jp/problem/tree_decomposition_width_2

Category: Graph


Statement:
You are given a simple, undirected graph with $N$ vertices and $M$ edges. Its edges are $(u_i, v_i)$.

Determine whether the tree width of the graph is no more than 2. If it is, construct a tree decomposition with tree width no more than 2.

In other words, construct a tree with $K$ vertices, and the bag (subset of vertices in the original graph) $B_0, B_1, \cdots, B_{K - 1}$ on each of its vertices.

- $0 \leq K \leq 10N + M + 10$
- For each edge $(u_i, v_i)$, there is a bag that contains both $u_i, v_i$.
- For each vertex $i$ in the original graph, all vertices in the tree whose bag contains vertex $i$ are connected.


Constraints:
- $1 \leq N \leq 500000$
- $0 \leq M \leq 500000$
- The graph is simple.


Input:
Input and output are in the format used in [PACE 2017 Track A](https://pacechallenge.wordpress.com/pace-2017/track-a-treewidth/).
Also refer to the samples.


Output:
If the tree width is $3$ or larger, output $-1$ in the first line. (This is not the format used in PACE 2017 Track A)

Otherwise, output in the following format.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'tree_decomposition_width_2'
    pass


if __name__ == "__main__":
    solve()