# Title: Matching on General Graph
# URL: https://judge.yosupo.jp/problem/general_matching
# Category: Graph

"""
Title: Matching on General Graph

Link: https://judge.yosupo.jp/problem/general_matching

Category: Graph


Statement:
Given a simple undirected graph with $N$ vertices and $M$ edges. $i$-th edge is $(u_i, v_i)$.

Calculate the maximum matching.


Constraints:
- $1 \leq N \leq 500$
- $0 \leq M \leq \frac{N(N-1)}{2}$
- $0 \leq u_i, v_i < N$


Input:
~~~
$N$ $M$
$u_0$ $v_0$
$u_1$ $v_1$
:
$u_{M - 1}$ $v_{M - 1}$
~~~


Output:
$X$ is the size of the maximum matching.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'general_matching'
    pass


if __name__ == "__main__":
    solve()