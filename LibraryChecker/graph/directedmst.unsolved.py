# Title: Directed MST
# URL: https://judge.yosupo.jp/problem/directedmst
# Category: Graph

"""
Title: Directed MST

Link: https://judge.yosupo.jp/problem/directedmst

Category: Graph


Statement:
Given a simple weighted directed graph with $N$ vertices and $M$ edges. $i$-th edge is $(a_i, b_i)$ and has a weight of $c_i$.

Find the directed minimum spanning tree whose root is the vertex $S$ (it means that all the vertices have to be reachable from $S$).


Constraints:
- $1 \leq N \leq 200000$
- $N - 1 \leq M \leq 200000$
- $0 \leq S < N$
- $0 \leq a_i, b_i < N$
- $a_i \neq b_i$
- $(a_i, b_i) \neq (a_j, b_j) (i \neq j)$
- $0 \leq c_i \leq 1000000000$
- All the vertices are reachable from the vertex $S$.


Input:
~~~
$N$ $M$ $S$
$a_0$ $b_0$ $c_0$
$a_1$ $b_1$ $c_1$
:
$a_{M - 1}$ $b_{M - 1}$ $c_{M - 1}$
~~~


Output:
$X$ is the sum of the weights of the edges in the directed MST. $p_i$ is the parent of the vertex $i$ or $p_S = S$.

If there are multiple correct output, print any of them.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'directedmst'
    pass


if __name__ == "__main__":
    solve()