# Title: Matrix Product
# URL: https://judge.yosupo.jp/problem/matrix_product
# Category: Linear Algebra

"""
Title: Matrix Product

Link: https://judge.yosupo.jp/problem/matrix_product

Category: Linear Algebra


Statement:
Given $N \times M$ matrix $A$ and $M \times K$ matrix $B$, print $C = AB \bmod 998244353$.


Constraints:
- $1 \leq N,M,K \leq 1024$
- $0 \leq a_{ij},b_{ij} < 998244353$


Input:
```
$N\ M\ K$
$a_{11}$ $a_{12}$ ... $a_{1M}$
$a_{21}$ $a_{22}$ ... $a_{2M}$
:
$a_{N1}$ $a_{N2}$ ... $a_{NM}$
$b_{11}$ $b_{12}$ ... $b_{1K}$
$b_{21}$ $b_{22}$ ... $b_{2K}$
:
$b_{M1}$ $b_{M2}$ ... $b_{MK}$
```


Output:
```
$c_{11}$ $c_{12}$ ... $c_{1K}$
$c_{21}$ $c_{22}$ ... $c_{2K}$
:
$c_{N1}$ $c_{N2}$ ... $c_{NK}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'matrix_product'
    pass


if __name__ == "__main__":
    solve()