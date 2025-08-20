# Title: Rectangle Sum
# URL: https://judge.yosupo.jp/problem/rectangle_sum
# Category: Data Structure

"""
Title: Rectangle Sum

Link: https://judge.yosupo.jp/problem/rectangle_sum

Category: Data Structure


Statement:
There are $N$ weighted points on the $2$ dimensional plane. The coordinate of the $i$-th point is $(x_i, y_i)$, and its weight is $w_i$.
Process $Q$ queries.

- `$l$ $d$ $r$ $u$`: Find the sum of weights of all points that satisfy $l \leq x < r$, $d \leq y < u$.


Constraints:
- $1 \leq N, Q \leq 200,000$
- $0 \leq x_i, y_i, w_i \leq 10^9$
- $0 \leq l_i < r_i \leq 10^9$
- $0 \leq d_i < u_i \leq 10^9$


Input:
~~~
$N$ $Q$
$x_0$ $y_0$ $w_0$
$x_1$ $y_1$ $w_1$
:
$x_{N - 1}$ $y_{N - 1}$ $w_{N - 1}$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'rectangle_sum'
    pass


if __name__ == "__main__":
    solve()