# Title: Cartesian Tree
# URL: https://judge.yosupo.jp/problem/cartesian_tree
# Category: Tree

"""
Title: Cartesian Tree

Link: https://judge.yosupo.jp/problem/cartesian_tree

Category: Tree


Statement:
You are given a sequence $A = (a_0, a_1, \dots, a _ {N-1})$ of distinct integers.
Construct the Cartesian tree derived from this sequence $A$.
The smallest element becomes the root.


Constraints:
- $1 \leq N \leq 1000000$
- $0 \leq a_i \leq 1000000000$
- $i \ne j$ implies $a_i \ne a_j$
- all values are integers


Input:
~~~
$N$
$a_0$ $a_1$ ... $a _ {N - 1}$
~~~


Output:
$p_i$ is the parent of vertex $i$. $p_r = r$ for the root node $r$ of the tree.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'cartesian_tree'
    pass


if __name__ == "__main__":
    solve()