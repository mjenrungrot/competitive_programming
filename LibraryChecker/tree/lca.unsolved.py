# Title: Lowest Common Ancestor
# URL: https://judge.yosupo.jp/problem/lca
# Category: Tree

"""
Title: Lowest Common Ancestor

Link: https://judge.yosupo.jp/problem/lca

Category: Tree


Statement:
Given a rooted tree with $N$ vertices. The root is vertex $0$ and a parent of a vertex $i$ is $p_i$. Process $Q$ queries as follows:

- `$u$ $v$`: Print LCA of vertex $u$ and $v$.


Constraints:
- $2 \leq N \leq 500000$
- $1 \leq Q \leq 500000$
- $0 \leq p_i < i$
- $0 \leq u < v \leq N - 1$


Input:
~~~
$N$ $Q$
$p_1$ $p_2$ ... $p_{N-1}$
$u_0$ $v_0$
$u_1$ $v_1$
:
$u_{Q - 1}$ $v_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'lca'
    pass


if __name__ == "__main__":
    solve()