# Title: Chromatic Polynomial
# URL: https://judge.yosupo.jp/problem/chromatic_polynomial
# Category: Graph

"""
Title: Chromatic Polynomial

Link: https://judge.yosupo.jp/problem/chromatic_polynomial

Category: Graph


Statement:
Given an undirected graph $G$ with $N$ vertices and $M$ edges. The $i$-th edge is $\lbrace u_i, v_i\rbrace$. 


Calculate the chromatic polynomial $P(G,x)=p_0+p_1+\cdots+p_Nx^N$ modulo $998244353$.


Constraints:
- $1 \leq N \leq 20$
- $0 \leq M \leq 500$
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
~~~
$p_0$ $p_1$ $\cdots$ $p_N$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'chromatic_polynomial'
    pass


if __name__ == "__main__":
    solve()