# Title: Rectangle Add Point Get
# URL: https://judge.yosupo.jp/problem/rectangle_add_point_get
# Category: Data Structure

"""
Title: Rectangle Add Point Get

Link: https://judge.yosupo.jp/problem/rectangle_add_point_get

Category: Data Structure


Statement:
You are given $N$ weighted rectangles on two-dimensional plane.
The position of $i$-th rectangle is 
$$[l_i,r_i) \times [d_i,u_i) = \lbrace(x,y)\in \mathbb{R}^2\mid l_i\leq x<r_i, d_i\leq y<u_i\rbrace$$
and has a weight of $w_i$. Process $Q$ queries of the following types.

 - `0 $l$ $d$ $r$ $u$ $w$` : Add a new rectangle with weight $w$ at $[l,r) \times [d,u)$. 
 - `1 $x$ $y$` : Find the sum of weight of rectangles which contain $(x,y)$.


Constraints:
- $1 \le N \le 100000$
 - $1 \le Q \le 100000$
 - $0 \le l_i \lt r_i \le 1000000000$
 - $0 \le d_i \lt u_i \le 1000000000$
 - $0 \le w_i \le 1000000000$
 - For queries of type `0 $l$ $d$ $r$ $u$ $w$`
     - $0 \le l \lt r \le 1000000000$
     - $0 \le d \lt u \le 1000000000$
     - $0 \le w \le 1000000000$
 - For queries of type `1 $x$ $y$`
     - $0 \le x, y \le 1000000000$


Input:
~~~
$N$ $Q$
$l_0$ $d_0$ $r_0$ $u_0$ $w_0$
$\vdots$
$l_{N-1}$ $d_{N-1}$ $r_{N-1}$ $u_{N-1}$ $w_{N-1}$
$\mathrm{Query}_0$
$\vdots$
$\mathrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'rectangle_add_point_get'
    pass


if __name__ == "__main__":
    solve()