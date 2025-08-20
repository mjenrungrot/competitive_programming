# Title: Manhattan MST
# URL: https://judge.yosupo.jp/problem/manhattanmst
# Category: Geometry

"""
Title: Manhattan MST

Link: https://judge.yosupo.jp/problem/manhattanmst

Category: Geometry


Statement:
Given $N$ 2D-points. $i$-th is $(x_i, y_i)$.

For each $i, j$, we add edge between them and whose weight is $|x_i - x_j| + |y_i - y_j|$.

Calculate MST of this graph.


Constraints:
- $1 \leq N \leq 200,000$
- $0 \leq x_i, y_i \leq 10^9$


Input:
~~~
$N$
$x_0$ $y_0$
$x_1$ $y_1$
:
$x_{N - 1}$ $y_{N - 1}$
~~~


Output:
$X$ is the sum of weight of tree.
If there are multiple solutions, print any of them.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'manhattanmst'
    pass


if __name__ == "__main__":
    solve()