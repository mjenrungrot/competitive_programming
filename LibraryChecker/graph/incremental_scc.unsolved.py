# Title: Strongly Connected Components (Incremental)
# URL: https://judge.yosupo.jp/problem/incremental_scc
# Category: Graph

"""
Title: Strongly Connected Components (Incremental)

Link: https://judge.yosupo.jp/problem/incremental_scc

Category: Graph


Statement:
There is a $N$ vertices and $0$ edges directed graph $G$, and an integer sequence $x_0, \ldots, x_{N-1}$.

Add $M$ directed edges to $G$. The $i$-th edge is directed from $a_i$ to $b_i$.

After adding each edge, output the remainder when $X$ defined below modulo $998244353$:

- Define $\mathrm{same}(i,j)$ as $1$ if vertices $i$ and $j$ belong to the same strongly connected component in $G$, and $0$ otherwise, for $0\leq i,j \leq N-1$.
- Define $X = \sum_{0\leq i<j\leq N-1}\mathrm{same}(i,j)x_ix_j$.


Constraints:
- $1 \leq N \leq 500000$
- $1 \leq M \leq 500000$
- $0 \leq x_i < 998244353$
- $0 \leq a_i, b_i < N$


Input:
~~~
$N$ $M$
$x_0$ $\ldots$ $x_{N-1}$
$a_0$ $b_0$
$a_1$ $b_1$
$\vdots$
$a_{M - 1}$ $b_{M - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'incremental_scc'
    pass


if __name__ == "__main__":
    solve()