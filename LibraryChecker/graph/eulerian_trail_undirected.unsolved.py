# Title: Eulerian Trail (Undirected)
# URL: https://judge.yosupo.jp/problem/eulerian_trail_undirected
# Category: Graph

"""
Title: Eulerian Trail (Undirected)

Link: https://judge.yosupo.jp/problem/eulerian_trail_undirected

Category: Graph


Statement:
This problem has $T$ cases. 

You are given an **undirected** graph $G$, consisting of $N$ vertices and $M$ edges. The $i$-th edge connects vertex $u_i$ and $v_i$. This graph may not be simple. 

An **eulerian trail** of $G$ is a pair of sequence of vertices $(v_0,\ldots,v_M)$ and sequence of edges $(e_0,\ldots,e_{M-1})$ satisfying following conditions. 

- $(e_0,\ldots,e_{M-1})$ is a permutation of $(0, \ldots, M-1)$. 
- For $0\leq i < M-1$, the edge $e_i$ connects $v_i$ and $v_{i+1}$. 

Determine if an eulerian trail of $G$ exists, and output if it exists.


Constraints:
- $1 \leq T \leq 100000$
- $1 \leq N \leq 200000$
- $0 \leq M \leq 200000$
- $0 \leq u_i, v_i \lt N$
- The sum of $N$ over all test cases does not exceed $200000$. 
- The sum of $M$ over all test cases does not exceed $200000$.


Input:
~~~
$T$
$N$ $M$
$u_0$ $v_0$
$\vdots$
$u_{M-1}$ $v_{M-1}$
$N$ $M$
$u_0$ $v_0$
$\vdots$
$u_{M-1}$ $v_{M-1}$
$\vdots$
~~~


Output:
If there exists no eulerian trail, print `No`. Otherwise, print an eulerian trail in the following format.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'eulerian_trail_undirected'
    pass


if __name__ == "__main__":
    solve()