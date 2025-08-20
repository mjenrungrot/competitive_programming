# Title: Minimum Spanning Tree
# URL: https://judge.yosupo.jp/problem/minimum_spanning_tree
# Category: Graph

"""
Title: Minimum Spanning Tree

Link: https://judge.yosupo.jp/problem/minimum_spanning_tree

Category: Graph


Statement:
Given a weighted undirected graph with $N$ vertices and $M$ edges. The $i$-th edge is $(a_i, b_i)$ and has a weight of $c_i$. This graph may not be simple.
Find the minimum spanning tree.


Constraints:
- $1 \leq N \leq 500000$
- $N - 1 \leq M \leq 500000$
- $0 \leq a_i, b_i < N$
- $0 \leq c_i \leq 1000000000$
- The given graph is connected.


Input:
~~~
$N$ $M$
$a_0$ $b_0$ $c_0$
$a_1$ $b_1$ $c_1$
:
$a_{M - 1}$ $b_{M - 1}$ $c_{M - 1}$
~~~


Output:
$X$ is the sum of the weights of the edges in the minimum spanning tree. $e_i$ is the index of the edge in the minimum spanning tree.
If there are multiple correct output, print any of them.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'minimum_spanning_tree'
    pass


if __name__ == "__main__":
    solve()