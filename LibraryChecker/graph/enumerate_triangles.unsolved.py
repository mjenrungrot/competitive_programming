# Title: Enumerate Triangles
# URL: https://judge.yosupo.jp/problem/enumerate_triangles
# Category: Graph

"""
Title: Enumerate Triangles

Link: https://judge.yosupo.jp/problem/enumerate_triangles

Category: Graph


Statement:
You are given a simple undirected graph, consisting of $N$ vertices and $M$ edges.
The $i$-th edge is $\lbrace u_i, v_i \rbrace$.
Each vertex has an integer value, and the value of $i$ th vertex is $x_i$.

Three vertices $a, b, c (a \lt b \lt c)$ connected by three edges $\lbrace a, b \rbrace, \lbrace a, c \rbrace, \lbrace b, c \rbrace$ are called triangle.
Find the sum of $x_a x_b x_c$ over all triangles, and print the sum modulo $998244353$ .


Constraints:
- $1 \le N \le 100000$
- $1 \le M \le 100000$
- $0 \le x_i \lt 998244353$
- $0 \le u_i \lt N$
- $0 \le v_i \lt N$
- $u_i \neq v_i$
- $\lbrace u_i, v_i \rbrace \neq \lbrace u_j, v_j \rbrace \  (i \neq j)$


Input:
```
$N$ $M$
$x_0$ $x_1$ $\ldots$ $x_{N-1}$
$u_0$ $v_0$
$u_1$ $v_1$
$\vdots$
$u_{M-1}$ $v_{M-1}$
```


Output:
```
$A$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'enumerate_triangles'
    pass


if __name__ == "__main__":
    solve()