# Title: Point Add Rectangle Sum
# URL: https://judge.yosupo.jp/problem/point_add_rectangle_sum
# Category: Data Structure

"""
Title: Point Add Rectangle Sum

Link: https://judge.yosupo.jp/problem/point_add_rectangle_sum

Category: Data Structure


Statement:
You are given $N$ weighted points on two-dimensional plane. $i$-th is at ($x_i$, $y_i$) and has a weight of $w_i$.
Process $Q$ queries of the following types.

 - `0 $x$ $y$ $w$` : Add a new point with weight $w$ at $(x, y)$. If there is another point at the same coordinates, add as a distinct point.
 - `1 $l$ $d$ $r$ $u$` : Find the sum of weight of points such that $l \leq x < r$, $d \leq y < u$ is satisfied.


Constraints:
- $1 \le N \le 100000$
 - $1 \le Q \le 100000$
 - $0 \le x_i, y_i \le 1000000000$
 - $0 \le w_i \le 1000000000$
 - For queries of type `0 $x$ $y$ $w$`
     - $0 \le x, y \le 1000000000$
     - $0 \le w \le 1000000000$
 - For queries of type `1 $l$ $d$ $r$ $u$`
     - $0 \le l \lt r \le 1000000000$
     - $0 \le d \lt u \le 1000000000$


Input:
~~~
$N$ $Q$
$x_0$ $y_0$ $w_0$
$x_1$ $y_1$ $w_1$
$x_2$ $y_2$ $w_2$
$\hspace{17pt} \vdots$
$x_{N - 1}$ $y_{N - 1}$ $w_{N - 1}$
$\mathrm{Query}_0$
$\mathrm{Query}_1$
$\mathrm{Query}_2$
$\hspace{13pt} \vdots$
$\mathrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'point_add_rectangle_sum'
    pass


if __name__ == "__main__":
    solve()