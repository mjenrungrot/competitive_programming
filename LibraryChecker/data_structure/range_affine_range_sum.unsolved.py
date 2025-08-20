# Title: Range Affine Range Sum
# URL: https://judge.yosupo.jp/problem/range_affine_range_sum
# Category: Data Structure

"""
Title: Range Affine Range Sum

Link: https://judge.yosupo.jp/problem/range_affine_range_sum

Category: Data Structure


Statement:
Given a size $N$ integer sequence $a_0, a_1, \dots, a_{N - 1}$. Process $Q$ queries as follows:

- `0 $l$ $r$ $b$ $c$`: For each $i = l, l+1, \dots, {r - 1}$, $a_i \gets b \times a_i + c$.
- `1 $l$ $r$`: Print $\sum_{i = l}^{r - 1} a_i \bmod 998244353$.


Constraints:
- $1 \leq N, Q \leq 500000$
- $0 \leq a_i, c < 998244353$
- $1 \leq b < 998244353$
- $0 \leq l < r \leq N$


Input:
~~~
$N$ $Q$
$a_0$ $a_1$ ... $a_{N - 1}$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'range_affine_range_sum'
    pass


if __name__ == "__main__":
    solve()