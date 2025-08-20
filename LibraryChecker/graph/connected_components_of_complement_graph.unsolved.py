# Title: Connected Components of Complement Graph
# URL: https://judge.yosupo.jp/problem/connected_components_of_complement_graph
# Category: Graph

"""
Title: Connected Components of Complement Graph

Link: https://judge.yosupo.jp/problem/connected_components_of_complement_graph

Category: Graph


Statement:
You are given a simple undirected graph with $N$ vertices and $M$ edges. The $i$-th edge is $(a_i,b_i)$. Decompose the complement graph of $G$ into connected components.


Constraints:
- $1 \leq N \leq 500000$
- $0 \leq M \leq 500000$
- $0 \leq a_i, b_i < N$
- The given graph is simple


Input:
~~~
$N$ $M$
$a_0$ $b_0$
$a_1$ $b_1$
$\vdots$
$a_{M-1}$ $b_{M-1}$
~~~


Output:
Print the number of connected components $K$ in the first line. In the next $K$ lines, print as follows. $l$ is the number of vertices of a connected component and $v_i$ is a vertex index.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'connected_components_of_complement_graph'
    pass


if __name__ == "__main__":
    solve()