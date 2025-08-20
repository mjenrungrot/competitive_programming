# Title: Persistent Unionfind
# URL: https://judge.yosupo.jp/problem/persistent_unionfind
# Category: Data Structure

"""
Title: Persistent Unionfind

Link: https://judge.yosupo.jp/problem/persistent_unionfind

Category: Data Structure


Statement:
Let $G_{-1}$ be the graph which consists of $N$ vertices and no edges. Process $Q$ queries in order. The $i$-th query is given with the following format:

- `0 $k_{i}$ $u_{i}$ $v_{i}$`: Let $G\_{i}$ be the graph, which is made by adding an edge $\left( u, v \right)$ to $G\_{k\_{i}}$.
- `1 $k_{i}$ $u_{i}$ $v_{i}$`: If vertices $u, v$ in $G\_{k\_{i}}$ are connected, print $1$. Otherwise, print $0$.


Constraints:
- $1 \leq N \leq 200000$
- $1 \leq Q \leq 200000$
- $t\_{i} \in \left\lbrace 0, 1 \right\rbrace$
- $-1 \leq k\_{i} < i$
- for all $k_i$, $k\_i = -1$ or $t\_{k\_{i}} = 0$ holds.
- $0 \leq u\_{i}, v\_{i} < N$


Input:
```
$N$ $Q$
$t_0$ $k_0$ $u_0$ $v_0$
$\vdots$
$t_{Q-1}$ $k_{Q-1}$ $u_{Q-1}$ $v_{Q-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'persistent_unionfind'
    pass


if __name__ == "__main__":
    solve()