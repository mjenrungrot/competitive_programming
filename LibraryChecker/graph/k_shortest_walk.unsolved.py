# Title: K-Shortest Walk
# URL: https://judge.yosupo.jp/problem/k_shortest_walk
# Category: Graph

"""
Title: K-Shortest Walk

Link: https://judge.yosupo.jp/problem/k_shortest_walk

Category: Graph


Statement:
You are given a not necessarily simple directed graph with $N$ vertices and $M$ edges. The $i$-th edge is directed from vertex $a_i$ to vertex $b_i$ and has weight $c_i$.

For $i$ from $1$ to $K$ (inclusive), output $x_i$, the length of the $i$-th shortest walk from vertex $s$ to vertex $t$. If such walk doesn't exist, output -1.

Multiple walks with the same length are considered different walks.


Constraints:
- $1 \leq N, M \leq 300000$
- $1 \leq K \leq 300000$
- $0 \leq s, t < N$
- $0 \leq u_i, v_i < N$
- $0 \leq c_i \leq 10000000$


Input:
~~~
$N~M~s~t~K$
$u_0~v_0~c_0$
$u_1~v_1~c_1$
$u_2~v_2~c_2$
:
$u_{M-1}~v_{M-1}~c_{M-1}$
~~~


Output:
~~~
$x_1$
$x_2$
$\vdots$
$x_K$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'k_shortest_walk'
    pass


if __name__ == "__main__":
    solve()