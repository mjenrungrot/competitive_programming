# Title: Chromatic Number
# URL: https://judge.yosupo.jp/problem/chromatic_number
# Category: Graph

"""
Title: Chromatic Number

Link: https://judge.yosupo.jp/problem/chromatic_number

Category: Graph


Statement:
Given a simple undirected graph with $N$ vertices and $M$ edges. $i$-th edge is $\lbrace u_i, v_i\rbrace$。

Calculate the chromatic number $C$.


Constraints:
- $1 \leq N \leq 20$
- $0 \leq M \leq \frac{N(N-1)}{2}$
- $0 \leq u_i, v_i < N$
- $u_i \neq v_i$
- $\lbrace u_i, v_i\rbrace \neq \lbrace u_j, v_j\rbrace$


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
$C$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'chromatic_number'
    pass


if __name__ == "__main__":
    solve()