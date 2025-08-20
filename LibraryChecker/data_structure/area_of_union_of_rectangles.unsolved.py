# Title: Area of Union of Rectangles
# URL: https://judge.yosupo.jp/problem/area_of_union_of_rectangles
# Category: Data Structure

"""
Title: Area of Union of Rectangles

Link: https://judge.yosupo.jp/problem/area_of_union_of_rectangles

Category: Data Structure


Statement:
Given $N$ rectangles : the $i$-th rectangle is represented by $\lbrace (x,y):l_i \leq x \leq r_i,d_i \leq y \leq u_i \rbrace$. Output the area of the union set of these rectangles.


Constraints:
- $1 \le N \le 500000$
 - $0 \le l_i < r_i \le 1000000000$
 - $0 \le d_i < u_i \le 1000000000$


Input:
~~~
$N$
$l_0$ $d_0$ $r_0$ $u_0$
$l_1$ $d_1$ $r_1$ $u_1$
$\vdots$
$l_{N-1}$ $d_{N-1}$ $r_{N-1}$ $u_{N-1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'area_of_union_of_rectangles'
    pass


if __name__ == "__main__":
    solve()