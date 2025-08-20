# Title: Matrix Product (Mod 2)
# URL: https://judge.yosupo.jp/problem/matrix_product_mod_2
# Category: Linear Algebra

"""
Title: Matrix Product (Mod 2)

Link: https://judge.yosupo.jp/problem/matrix_product_mod_2

Category: Linear Algebra


Statement:
Given $N \times M$ matrix $A$ and $M \times K$ matrix $B$, print $C = AB \bmod 2$. 

When dealing with matrix input and output, please treat each row as a string concatenated with its components ($0$ or $1$).


Constraints:
- $1 \leq N,M,K \leq 4096$
- $a_{ij},b_{ij} \in \lbrace 0,1\rbrace$


Input:
```
$N\ M\ K$
$a_{11}a_{12} \cdots a_{1M}$
$a_{21}a_{22} \cdots a_{2M}$
$\vdots$
$a_{N1}a_{N2} \cdots a_{NM}$
$b_{11}b_{12} \cdots b_{1K}$
$b_{21}b_{22} \cdots b_{2K}$
$\vdots$
$b_{M1}b_{M2} \cdots b_{MK}$
```


Output:
```
$c_{11}c_{12} \cdots c_{1K}$
$c_{21}c_{22} \cdots c_{2K}$
$\vdots$
$c_{N1}c_{N2} \cdots c_{NK}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'matrix_product_mod_2'
    pass


if __name__ == "__main__":
    solve()