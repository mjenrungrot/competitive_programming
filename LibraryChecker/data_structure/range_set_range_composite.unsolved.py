# Title: Range Set Range Composite
# URL: https://judge.yosupo.jp/problem/range_set_range_composite
# Category: Data Structure

"""
Title: Range Set Range Composite

Link: https://judge.yosupo.jp/problem/range_set_range_composite

Category: Data Structure


Statement:
Given a size $N$ sequence of linear functions $f _ 0, f _ 1, ..., f _ {N-1}$. For all $i$, $f _ i(x) = a _ i x + b _ i$. Process $Q$ queries as follows:

- `0 $l$ $r$ $c$ $d$`: For each $i = l, l+1, \dots, {r - 1}$, $f _ i \gets cx + d$.
- `1 $l$ $r$ $x$`: Print $f _ {r-1}(f _ {r-2}(...f _ l(x))) \bmod 998244353$.


Constraints:
- $1 \leq N, Q \leq 500000$
- $1 \leq a _ i, c < 998244353$
- $0 \leq b _ i, d, x < 998244353$
- $0 \leq l < r \leq N$


Input:
~~~
$N$ $Q$
$a _ 0$ $b _ 0$
$a _ 1$ $b _ 1$
:
$a _ {N - 1}$ $b _ {N - 1}$
$\textrm{Query} _ 0$
$\textrm{Query} _ 1$
:
$\textrm{Query} _ {Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'range_set_range_composite'
    pass


if __name__ == "__main__":
    solve()