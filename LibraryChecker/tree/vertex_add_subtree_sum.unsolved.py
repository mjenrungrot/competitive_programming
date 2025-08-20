# Title: Vertex Add Subtree Sum
# URL: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
# Category: Tree

"""
Title: Vertex Add Subtree Sum

Link: https://judge.yosupo.jp/problem/vertex_add_subtree_sum

Category: Tree


Statement:
Given rooted tree of $N$ vertices. The root of tree is a vertex $0$. A value of vertex $i$ is $a_i$, and a parent of it is $p_i$. Process the following $Q$ queries in order:

- `0 $u$ $x$`: $a_u \gets a_u + x$
- `1 $u$`: Print the sum of values of subtree, whose root is $u$.


Constraints:
- $1 \leq N, Q \leq 500,000$
- $0 \leq p_i < i$
- $0 \leq a_i, x \leq 10^9$


Input:
~~~
$N$ $Q$
$a_0$ $a_1$ ... $a_{N - 1}$
$p_1$ $p_2$ ... $p_{N - 1}$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'vertex_add_subtree_sum'
    pass


if __name__ == "__main__":
    solve()