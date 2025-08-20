# Title: Jump on Tree
# URL: https://judge.yosupo.jp/problem/jump_on_tree
# Category: Tree

"""
Title: Jump on Tree

Link: https://judge.yosupo.jp/problem/jump_on_tree

Category: Tree


Statement:
Given a tree with $N$ vertices, where the $i$-th edge connects vertex $a_i$ and $b_i$. Process $Q$ queries as follows:

- `$s$ $t$ $i$`: Print $v_i$, where the shortest path on the tree from $s$ to $t$ is $(v_0, v_1, \ldots, v_k)$ ($v_0 = s$, $v_k = t$). If $i>k$, print `-1`.


Constraints:
- $2 \leq N \leq 500000$
- $1 \leq Q \leq 500000$
- $0 \leq a_i, b_i \leq N-1$
- $a_i \neq b_i$
- $0 \leq s, t \leq N - 1$
- $0 \leq i \leq N - 1$


Input:
~~~
$N$ $Q$
$a_0$ $b_0$
$\vdots$
$a_{N-2}$ $b_{N-2}$
$s_0$ $t_0$ $i_0$
$\vdots$
$s_{Q-1}$ $t_{Q-1}$ $i_{Q-1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'jump_on_tree'
    pass


if __name__ == "__main__":
    solve()