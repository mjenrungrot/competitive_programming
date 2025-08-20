# Title: Dominator Tree
# URL: https://judge.yosupo.jp/problem/dominatortree
# Category: Graph

"""
Title: Dominator Tree

Link: https://judge.yosupo.jp/problem/dominatortree

Category: Graph


Statement:
Given a directed graph with $N$ vertices and $M$ edges. $i$-th edge is $(a_i, b_i)$.

Calculate the dominator tree of this graph whose root is $S$.


Constraints:
- $1 \leq N \leq 200,000$
- $0 \leq M \leq 200,000$
- $0 \leq S, a_i, b_i < N$


Input:
~~~
$N$ $M$ $S$
$a_0$ $b_0$
$a_1$ $b_1$
:
$a_{M - 1}$ $b_{M - 1}$
~~~


Output:
$p_i$ is the parent of vertex $i$. If we can not reach $i$ from $S$, print $-1$. $p_S$ is $S$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'dominatortree'
    pass


if __name__ == "__main__":
    solve()