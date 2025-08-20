# Title: Range Affine Range Sum (Large Array)
# URL: https://judge.yosupo.jp/problem/range_affine_range_sum_large_array
# Category: Data Structure

"""
Title: Range Affine Range Sum (Large Array)

Link: https://judge.yosupo.jp/problem/range_affine_range_sum_large_array

Category: Data Structure


Statement:
Given a size $N$ integer sequence $a_0, a_1, \dots, a_{N - 1}$. Initially, $a_i = 0$ for all $i$. 
Process $Q$ queries as follows:

- `0 $l$ $r$ $b$ $c$`: For each $i = l, l+1, \dots, {r - 1}$, $a_i \gets b \times a_i + c$.
- `1 $l$ $r$`: Print $\sum_{i = l}^{r - 1} a_i \bmod 998244353$.


Constraints:
- $1 \leq N \leq 1000000000$
- $1 \leq Q \leq 100000$
- $0 \leq l < r \leq N$
- $1 \leq b < 998244353$
- $0 \leq c < 998244353$


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
    # TODO: implement solution for 'range_affine_range_sum_large_array'
    pass


if __name__ == "__main__":
    solve()