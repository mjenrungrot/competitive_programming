# Title: Biconnected Components
# URL: https://judge.yosupo.jp/problem/biconnected_components
# Category: Graph

"""
Title: Biconnected Components

Link: https://judge.yosupo.jp/problem/biconnected_components

Category: Graph


Statement:
Given a undirected graph with $N$ vertices and $M$ edges. $i$-th edge is $(a _ i, b _ i)$. This graph may not be simple but never has a self-loop.
Decompose this graph into biconnected components and output their vertex sets.

A biconnected component is a maximal biconnected subgraph.


Constraints:
- $1 \leq N \leq 500000$
- $0 \leq M \leq 500000$
- $0 \leq a _ i, b _ i \lt N$
- $a _ i \neq b _ i$


Input:
~~~
$N$ $M$
$a _ 0$ $b _ 0$
$a _ 1$ $b _ 1$
:
$a _ {M-1}$ $b _ {M-1}$
~~~


Output:
Print the number of biconnected components $K$ in the first line.
Following $K$ lines, print as follows. $l$ is the number of vertices of biconnected components and $v _ i$ is an vertex index.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'biconnected_components'
    pass


if __name__ == "__main__":
    solve()