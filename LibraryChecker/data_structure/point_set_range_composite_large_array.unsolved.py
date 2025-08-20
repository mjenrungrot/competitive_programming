# Title: Point Set Range Composite (Large Array)
# URL: https://judge.yosupo.jp/problem/point_set_range_composite_large_array
# Category: Data Structure

"""
Title: Point Set Range Composite (Large Array)

Link: https://judge.yosupo.jp/problem/point_set_range_composite_large_array

Category: Data Structure


Statement:
Given a size $N$ sequence of linear functions $f_0, f_1, ..., f_{N-1}$. Initially, $f_i(x)=x$ For all $i$. Process $Q$ queries as follows:

- `0 $p$ $c$ $d$`: change $f_p \gets cx + d$.
- `1 $l$ $r$ $x$`: print $f_{r-1}(f_{r-2}(...f_l(x))) \bmod 998244353$.


Constraints:
- $1 \leq N \leq 1000000000$
- $1 \leq Q \leq 500000$
- $1 \leq c < 998244353$
- $0 \leq d, x < 998244353$
- $0 \leq p < N$
- $0 \leq l < r \leq N$


Input:
~~~
$N$ $Q$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'point_set_range_composite_large_array'
    pass


if __name__ == "__main__":
    solve()