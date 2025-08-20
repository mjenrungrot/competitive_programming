# Title: Maximum Independent Set
# URL: https://judge.yosupo.jp/problem/maximum_independent_set
# Category: Graph

"""
Title: Maximum Independent Set

Link: https://judge.yosupo.jp/problem/maximum_independent_set

Category: Graph


Statement:
Given a simple undirected graph with $N$ vertices and $M$ edges. $i$-th edge is $(u_i, v_i)$。

Calculate the maximum independent set.


Constraints:
- $1 \leq N \leq 40$
- $0 \leq M \leq \frac{N(N-1)}{2}$
- $0 \leq u_i, v_i < N$
- $u_i \neq v_i$
- $(u_i, v_i) \neq (u_j, v_j)$


Input:
~~~
$N$ $M$
$u_0$ $v_0$
$u_1$ $v_1$
:
$u_{M - 1}$ $v_{M - 1}$
~~~


Output:
$X$ is the size of MIS, and $p_i$ is the vertex index.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'maximum_independent_set'
    pass


if __name__ == "__main__":
    solve()