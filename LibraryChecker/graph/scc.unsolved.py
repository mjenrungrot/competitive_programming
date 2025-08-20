# Title: Strongly Connected Components
# URL: https://judge.yosupo.jp/problem/scc
# Category: Graph

"""
Title: Strongly Connected Components

Link: https://judge.yosupo.jp/problem/scc

Category: Graph


Statement:
Given a directed graph with $N$ vertices and $M$ edges. $i$-th edge is $(a_i, b_i)$. This graph may not be simple.

Please decompose this graph into SCCs and print them in topological order.


Constraints:
- $1 \leq N \leq 500,000$
- $1 \leq M \leq 500,000$
- $0 \leq a_i, b_i < N$


Input:
~~~
$N$ $M$
$a_0$ $b_0$
$a_1$ $b_1$
:
$a_{M - 1}$ $b_{M - 1}$
~~~


Output:
First line, print the number of SCCs $K$.
Following $K$ line, we print the information of SCC for each line as follows.
$l$ is the number of vertices of SCC, and $v_i$ is the vertex index.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'scc'
    pass


if __name__ == "__main__":
    solve()