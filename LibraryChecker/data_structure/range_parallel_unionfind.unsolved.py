# Title: Range Parallel Unionfind
# URL: https://judge.yosupo.jp/problem/range_parallel_unionfind
# Category: Data Structure

"""
Title: Range Parallel Unionfind

Link: https://judge.yosupo.jp/problem/range_parallel_unionfind

Category: Data Structure


Statement:
There's an undirected graph $G$ with $N$ vertices and $0$ edges, along with a sequence of integers $x_0, \ldots, x_{N-1}$. Please process $Q$ queries of the following format:

- `$k$ $a$ $b$`: Add edge $(a + i, b + i)$ to $G$ for each $i=0,1,\ldots,k-1$.

After processing each query, output the remainder when $X$ defined below modulo $998244353$:

- Define $\mathrm{same}(i,j)$ as $1$ if vertices $i$ and $j$ belong to the same connected component in $G$, and $0$ otherwise, for $0\leq i,j \leq N-1$.
- Define $X = \sum_{0\leq i<j\leq N-1}\mathrm{same}(i,j)x_ix_j$.


Constraints:
- $1 \leq N \leq 500000$
- $1 \leq Q \leq 500000$
- $0 \leq x_i < 998244353$
- $0 \leq k\leq N$
- $0 \leq a,b \leq N-k$


Input:
~~~
$N$ $Q$
$x_0$ $\cdots$ $x_{N-1}$
$k$ $a$ $b$
$\vdots$
$k$ $a$ $b$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'range_parallel_unionfind'
    pass


if __name__ == "__main__":
    solve()