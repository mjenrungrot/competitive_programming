# Title: Dynamic Point Rectangle Affine Rectangle Sum
# URL: https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum
# Category: Data Structure

"""
Title: Dynamic Point Rectangle Affine Rectangle Sum

Link: https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum

Category: Data Structure


Statement:
You are given an initial multiset of $N$ weighted points, $P = (P_0, P_1, \dots, P_{N - 1})$, on a two-dimensional plane. Each point $P_i$ ($0 \leq i < N$) is located at $(x_i, y_i)$ and has an associated weight $w_i$. Process $Q$ queries of the following types. For the $i$-th ($0\leq i < Q$) query:

- `0 $x$ $y$ $w$`: Append a new point with weight $w$ at coordinates $(x, y)$. Let $k = |P|$ before the addition, then refer to this point as $P_k$. If a point already exists at these coordinates, add the new point as a separate instance.
- `1 $x$ $w$`: Update the weight of point $P_x$ to $w$. (i.e., $w_x \gets w$)

- `2 $l$ $d$ $r$ $u$`: Calculate the sum of weights modulo $998244353$ for all points where $l \leq x_i < r$ and $d \leq y_i < u$.

- `3 $l$ $d$ $r$ $u$ $a$ $b$`: For each $i$ such that $l \leq x_i < r$ and $d \leq y_i < u$, apply the transformation $w_i \gets a \cdot w_i + b$.


Constraints:
- $1 \leq N \leq 100000$
- $1 \leq Q \leq 100000$
- $0 \leq x_i, y_i \leq 1000000000$
- $0 \leq w_i < 998244353$

For each query type:
- Type `0`: $0 \leq x, y \leq 1000000000$, $0 \leq w < 998244353$
- Type `1`: $0\leq x < |P|, 0\leq w < 998244353$
- Type `2`: $0 \leq l < r \leq 1000000000$, $0 \leq d < u \leq 1000000000$
- Type `3`: $0 \leq l < r \leq 1000000000$, $0 \leq d < u \leq 1000000000$, $0 \leq a, b < 998244353$


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
    # TODO: implement solution for 'dynamic_point_set_rectangle_affine_rectangle_sum'
    pass


if __name__ == "__main__":
    solve()