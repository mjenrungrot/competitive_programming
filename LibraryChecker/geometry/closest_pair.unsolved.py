# Title: Closest Pair of Points
# URL: https://judge.yosupo.jp/problem/closest_pair
# Category: Geometry

"""
Title: Closest Pair of Points

Link: https://judge.yosupo.jp/problem/closest_pair

Category: Geometry


Statement:
This problem has $T$ cases.

Given $N$ 2D points $p _ i(x _ i , y _ i)$ ($0\leq i\leq N - 1$). Find a pair $(i,j)$, such that $i\neq j$ and $\mathrm{dist}(p _ i,p _ j) = \min_{i\neq j}\mathrm{dist}(p _ i,p _ j)$. 

Here, $\mathrm{dist}$ denotes the Euclidean distance between two points.


Constraints:
- $1\leq T\leq 10^5$
- $2 \leq N \leq 500000$
- $|x_i|, |y_i| \leq 1000000000$
- $x_i, y_i$ are integers.
- The sum of $N$ over all test cases does not exceed $500000$


Input:
```
$T$
$N$
$x_0$ $y_0$
$x_1$ $y_1$
:
$x_{N - 1}$ $y_{N - 1}$
$N$
$x_0$ $y_0$
$x_1$ $y_1$
:
$x_{N - 1}$ $y_{N - 1}$
$\vdots$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'closest_pair'
    pass


if __name__ == "__main__":
    solve()