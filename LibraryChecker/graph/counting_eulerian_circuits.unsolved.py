# Title: Counting Eulerian Circuits
# URL: https://judge.yosupo.jp/problem/counting_eulerian_circuits
# Category: Graph

"""
Title: Counting Eulerian Circuits

Link: https://judge.yosupo.jp/problem/counting_eulerian_circuits

Category: Graph


Statement:
You are given a **directed** graph $G$, consisting of $N$ vertices and $M$ edges. The $i$-th edge is directed from $u_i$ to $v_i$. 

An **eulerian circuit** of $G$ is a pair of sequence of vertices $(v_0,\ldots,v_{M-1})$ and sequence of edges $(e_0,\ldots,e_{M-1})$ satisfying following conditions. 

- $(e_0,\ldots,e_{M-1})$ is a permutation of $(0, \ldots, M-1)$. 
- For $0\leq i < M-1$, the edge $e_i$ is directed from $v_i$ to $v_{i+1}$. The edge $e_{M-1}$ is directed from $v_{M-1}$ to $v_0$. 

Note that an Eulerian circuit remains an Eulerian circuit after any cyclic shift.

Find the number of Eulerian circuits of $G$, considered the same if they can be obtained from one another by a cyclic shift (in other words, the number of Eulerian circuits with $e_0 = 0$), and give the result modulo $998244353$.


Constraints:
- $1 \leq N \leq 500$
- $1 \leq M \leq 200000$
- $0 \leq u_i, v_i \lt N$


Input:
~~~
$N$ $M$
$u_0$ $v_0$
$\vdots$
$u_{M-1}$ $v_{M-1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'counting_eulerian_circuits'
    pass


if __name__ == "__main__":
    solve()