# Title: Matching on Bipartite Graph
# URL: https://judge.yosupo.jp/problem/bipartitematching
# Category: Graph

"""
Title: Matching on Bipartite Graph

Link: https://judge.yosupo.jp/problem/bipartitematching

Category: Graph


Statement:
Given a bipartite graph with $L + R$ vertices and $M$ edges. $i$-th edge is $(a_i, b_i)$.

Calculate the maximum matching.


Constraints:
- $1 \leq L, R \leq 100,000$
- $1 \leq M \leq 200,000$
- $0 \leq a_i < L$
- $0 \leq b_i < R$
- There is no multiple edges.


Input:
~~~
$L$ $R$ $M$
$a_0$ $b_0$
$a_1$ $b_1$
:
$a_{M - 1}$ $b_{M - 1}$
~~~


Output:
$K$ is the number of maximum matching, and $(c_i, d_i)$ is the edge of the matching.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'bipartitematching'
    pass


if __name__ == "__main__":
    solve()