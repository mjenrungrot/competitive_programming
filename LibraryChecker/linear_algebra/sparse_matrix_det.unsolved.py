# Title: Determinant of Sparse Matrix
# URL: https://judge.yosupo.jp/problem/sparse_matrix_det
# Category: Linear Algebra

"""
Title: Determinant of Sparse Matrix

Link: https://judge.yosupo.jp/problem/sparse_matrix_det

Category: Linear Algebra


Statement:
Given $N \times N$ matrix $M$.
Only $K$ elements of $M$ is non-zero, and $i$-th is $M(a_i, b_i) = c_i$.
Print $\mathrm{det}(M) \bmod 998244353$.


Constraints:
- $1 \leq N \leq 3000$
- $1 \leq K \leq 10000$
- $0 \leq a_i, b_i \leq N - 1$
- $(a_i, b_i)$ is distinct.
- $1 \leq c_i < 998244353$


Input:
```
$N$ $K$
$a_1$ $b_1$ $c_1$
$a_2$ $b_2$ $c_2$
:
$a_K$ $b_K$ $c_K$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'sparse_matrix_det'
    pass


if __name__ == "__main__":
    solve()