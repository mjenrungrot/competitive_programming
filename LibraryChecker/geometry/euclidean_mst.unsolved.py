# Title: Euclidean MST
# URL: https://judge.yosupo.jp/problem/euclidean_mst
# Category: Geometry

"""
Title: Euclidean MST

Link: https://judge.yosupo.jp/problem/euclidean_mst

Category: Geometry


Statement:
Given $N$ 2D-points. $i$-th is $(x _ i, y _ i)$.

For each $i$ , $j$, we add edge between them and whose weight is $\sqrt{(x _ i - x _ j)^2 + (y _ i - y _ j)^2}$.

Calculate a minimum spanning tree of this graph.


Constraints:
- $1 \leq N \leq 200000$
- $|x _ i|, |y _ i| \leq 10000$


Input:
~~~
$N$
$x _ 0$ $y _ 0$
$x _ 1$ $y _ 1$
:
$x _ {N - 1}$ $y _ {N - 1}$
~~~


Output:
Output all those $N-1$ pairs of $u _ i$ , $v _ i$ as the indices of the points that are the terminals of the edges in a minimum spanning tree.

If there are multiple solutions, print any of them.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'euclidean_mst'
    pass


if __name__ == "__main__":
    solve()