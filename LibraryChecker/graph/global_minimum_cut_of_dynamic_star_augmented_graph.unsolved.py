# Title: Global Minimum Cut of Dynamic Star Augmented Graph
# URL: https://judge.yosupo.jp/problem/global_minimum_cut_of_dynamic_star_augmented_graph
# Category: Graph

"""
Title: Global Minimum Cut of Dynamic Star Augmented Graph

Link: https://judge.yosupo.jp/problem/global_minimum_cut_of_dynamic_star_augmented_graph

Category: Graph


Statement:
You are given a simple weighted undirected graph $G$, consisting of $N$ vertices and $M$ edges.
The $i$-th edge is $\lbrace u_i, v_i \rbrace$ and has a weight of $w_i$.

Let $H$ be a graph obtained by adding a new vertex $N$ to $G$ together with new $N$ edges.
The $i$-th edge is $\lbrace i, N \rbrace$ and has a weight of $a_i$.

Process the following $Q$ queries in order:

- change a weight of an edge $\lbrace x_i,N \rbrace$ to $y_i$ and print a global minmum cut size in $H$.


Constraints:
- $1 \le N \le 4000$
- $0 \le M \le \min ( \frac{N(N-1)}{2} , 4000 )$
- $1 \le Q \le 200000$
- $0 \le a_i \le 1000000000$
- $0 \le u_i, v_i \lt N$
- $u_i \neq v_i$
- $\lbrace u_i, v_i \rbrace \neq \lbrace u_j, v_j \rbrace \  (i \neq j)$
- $0 \le w_i \le 1000000000$
- $0 \le x_i \lt N$
- $0 \le y_i \le 1000000000$


Input:
~~~
$N$ $M$ $Q$
$a_0$ $a_1$ $\ldots$ $a_{N-1}$
$u_0$ $v_0$ $w_0$
$u_1$ $v_1$ $w_1$
$\vdots$
$u_{M-1}$ $v_{M-1}$ $w_{M-1}$
$x_0$ $y_0$
$x_1$ $y_1$
$\vdots$
$x_{Q-1}$ $y_{Q-1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'global_minimum_cut_of_dynamic_star_augmented_graph'
    pass


if __name__ == "__main__":
    solve()