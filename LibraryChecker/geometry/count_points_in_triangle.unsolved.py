# Title: Count Points in Triangles
# URL: https://judge.yosupo.jp/problem/count_points_in_triangle
# Category: Geometry

"""
Title: Count Points in Triangles

Link: https://judge.yosupo.jp/problem/count_points_in_triangle

Category: Geometry


Statement:
Given 2D-points $A _ k=(x _ k, y _ k)$ $(k=0,1,\ldots ,N-1)$ and 2D-points $B _ k=(p _ k, q _ k)$ $(k=0,1,\ldots ,M-1)$ . Process the following $Q$ queries in order.

* Given $a$ , $b$ , $c$ . Please output the number of points in $B _ 0,B _ 1,\ldots ,B _ {M-1}$ included in the convex hull of $3$ points $A _ a,A _ b,A _ c$ (**exclude border**) .


Constraints:
- $1 \leq N \leq 500$
- $1 \leq M \leq 500$
- $|x _ i|, |y _ i| \leq 1000000000$
- $|p _ i|, |q _ i| \leq 1000000000$
- $1 \leq Q \leq 1000000$
- $0 \leq a,b,c \lt N$
- They are all integers.


Input:
```
$N$
$x _ 0$ $y _ 0$
$x _ 1$ $y _ 1$
$\ \vdots$
$x _ {N-1}$ $y _ {N-1}$
$M$
$p _ 0$ $q _ 0$
$p _ 1$ $q _ 1$
$\ \vdots$
$p _ {M-1}$ $q_{M-1}$
$Q$
$a$ $b$ $c$
$\ \vdots$
$a$ $b$ $c$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'count_points_in_triangle'
    pass


if __name__ == "__main__":
    solve()