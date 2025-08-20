# Title: Point Set Range Sort Range Composite
# URL: https://judge.yosupo.jp/problem/point_set_range_sort_range_composite
# Category: Data Structure

"""
Title: Point Set Range Sort Range Composite

Link: https://judge.yosupo.jp/problem/point_set_range_sort_range_composite

Category: Data Structure


Statement:
A Sequence of triples of integers $\bigl((p_i, a_i, b_i)\bigr)_{0\leq i < N}$ is given. 
Process $Q$ queries as follows:

- `0 $i$ $p$ $a$ $b$`: change $(p_i,a_i,b_i) \gets (p,a,b)$.
- `1 $l$ $r$ $x$`: print $f_{r-1}(f_{r-2}(...f_l(x))) \bmod 998244353$, where $f_i(x) := a_ix + b_i$.
- `2 $l$ $r$`: Sort $\bigl((p_i, a_i, b_i)\bigr)_{l\leq i < r}$ so that $p_i$ is **increasing**. 
- `3 $l$ $r$`: Sort $\bigl((p_i, a_i, b_i)\bigr)_{l\leq i < r}$ so that $p_i$ is **decreasing**.


Constraints:
- $1 \leq N \leq 100000$
- $1 \leq Q \leq 100000$
- $0 \leq i < N$
- $0 \leq p_i, p \leq 1000000000$
- All values $p_i, p$ (initial values and values given in query 0) are distinct. 
- $1 \leq a_i, a < 998244353$
- $0 \leq b_i, b < 998244353$
- $0 \leq x < 998244353$
- $0 \leq l < r \leq N$


Input:
~~~
$N$ $Q$
$p_0$ $a_0$ $b_0$
$\vdots$
$p_{N-1}$ $a_{N-1}$ $b_{N-1}$
$\textrm{Query}_0$
$\vdots$
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'point_set_range_sort_range_composite'
    pass


if __name__ == "__main__":
    solve()