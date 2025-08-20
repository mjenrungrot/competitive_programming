# Title: General Weighted Matching
# URL: https://judge.yosupo.jp/problem/general_weighted_matching
# Category: Graph

"""
Title: General Weighted Matching

Link: https://judge.yosupo.jp/problem/general_weighted_matching

Category: Graph


Statement:
Given a simple weighted undirected graph with $N$ vertices and $M$ edges. $i$-th edge is $(u_i, v_i)$ with a weight $w_i$.
Calculate the matching in which the sum of weights is maximized.


Constraints:
- $1 \leq N \leq 500$
- $0 \leq M \leq \frac{N(N-1)}{2}$
- $0 \leq u_i, v_i < N$
- $1 \leq w_i \leq 1\thinspace 000\thinspace 000$


Input:
~~~
$N$ $M$
$u_0$ $v_0$ $w_0$
$u_1$ $v_1$ $w_1$
:
$u_{M - 1}$ $v_{M - 1}$ $w_{M-1}$
~~~


Output:
$X$ is the size of the maximum matching.
$W$ is the maximum matching weight.
$(a_i, b_i)$ is the edge of the matching.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'general_weighted_matching'
    pass


if __name__ == "__main__":
    solve()