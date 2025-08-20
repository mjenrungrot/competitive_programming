# Title: Chordal Graph Recognition
# URL: https://judge.yosupo.jp/problem/chordal_graph_recognition
# Category: Graph

"""
Title: Chordal Graph Recognition

Link: https://judge.yosupo.jp/problem/chordal_graph_recognition

Category: Graph


Statement:
You are given a simple undirected unweighted graph, consisting of $N$ vertices and $M$ edges.  
The $i$-th edge is between vertex $a_i$ and vertex $b_i$.

A graph is chordal if it does not have an induced cycle of length four or more.
A perfect elimination ordering is an ordering of the vertices such that for every vertex $v$, $v$ and the neighbors of $v$ that appear after it in the ordering form a clique.
It can be shown that a graph is chordal if and only if it has a perfect elimination ordering.

If the graph is chordal, find a perfect elimination ordering. If there are multiple perfect elimination orderings, print any of them.

If the graph is not chordal, find an induced cycle of length four or more. If there are multiple such cycles, print any of them.


Constraints:
- $1 \leq N \leq 200000$
- $0 \leq M \leq 200000$
- $0 \leq a_i \lt N$
- $0 \leq b_i \lt N$
- $a_i \neq b_i$
- $\lbrace a_i, b_i \rbrace \neq \lbrace a_j, b_j \rbrace (i \neq j)$


Input:
```
$N$ $M$
$a_0$ $b_0$
$a_1$ $b_1$
$a_2$ $b_2$
$\vdots$
$a_{M - 1}$ $b_{M - 1}$
```


Output:
If the graph is not chordal, output an induced cycle of length four or more in the following format.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'chordal_graph_recognition'
    pass


if __name__ == "__main__":
    solve()