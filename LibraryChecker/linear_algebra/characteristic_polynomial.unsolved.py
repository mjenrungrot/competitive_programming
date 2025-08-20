# Title: Characteristic Polynomial
# URL: https://judge.yosupo.jp/problem/characteristic_polynomial
# Category: Linear Algebra

"""
Title: Characteristic Polynomial

Link: https://judge.yosupo.jp/problem/characteristic_polynomial

Category: Linear Algebra


Statement:
Given $N \times N$ matrix $M = \lbrace a_{ij} \rbrace$. Print its (monic) characteristic polynomial $p(x)$ where

$$p(x) = \det (xI - M) = \sum_{i = 0}^N p_i x^i$$

and $I$ denotes the $N \times N$ identity matrix. The determinant of $0 \times 0$ matrix is equal to $1$. We consider everything $\mathbb{Z}/998244353\mathbb{Z}$.


Constraints:
- $0 \leq N \leq 500$
- $0 \leq a_{ij} < 998244353$


Input:
```
$N$
$a_{11}$ $a_{12}$ ... $a_{1N}$
$a_{21}$ $a_{22}$ ... $a_{2N}$
:
$a_{N1}$ $a_{N2}$ ... $a_{NN}$
```


Output:
```
$p_0$ $p_1$ ... $p_N$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'characteristic_polynomial'
    pass


if __name__ == "__main__":
    solve()