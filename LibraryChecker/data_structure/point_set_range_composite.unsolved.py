# Title: Point Set Range Composite
# URL: https://judge.yosupo.jp/problem/point_set_range_composite
# Category: Data Structure

"""
Title: Point Set Range Composite

Link: https://judge.yosupo.jp/problem/point_set_range_composite

Category: Data Structure


Statement:
Given a size $N$ sequence of linear functions $f_0, f_1, ..., f_{N-1}$. For all $i$, $f_i(x) = a_i x + b_i$. Process $Q$ queries as follows:

- `0 $p$ $c$ $d$`: change $f_p \gets cx + d$.
- `1 $l$ $r$ $x$`: print $f_{r-1}(f_{r-2}(...f_l(x))) \bmod 998244353$.


Constraints:
- $1 \leq N, Q \leq 500,000$
- $1 \leq a_i, c < 998244353$
- $0 \leq b_i, d, x < 998244353$
- $0 \leq p < N$
- $0 \leq l < r \leq N$


Input:
~~~
$N$ $Q$
$a_0$ $b_0$
$a_1$ $b_1$
:
$a_{N - 1}$ $b_{N - 1}$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'point_set_range_composite'
    pass


if __name__ == "__main__":
    solve()