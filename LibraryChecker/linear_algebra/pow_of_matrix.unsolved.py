# Title: Pow of Matrix
# URL: https://judge.yosupo.jp/problem/pow_of_matrix
# Category: Linear Algebra

"""
Title: Pow of Matrix

Link: https://judge.yosupo.jp/problem/pow_of_matrix

Category: Linear Algebra


Statement:
Given $N \times N$ matrix $A = \lbrace a_{ij} \rbrace$ with entries in $\mathbb{Z}/998244353\mathbb{Z}$, and a non-negative integer $K$. 
print $A^K = (b_{ij})_{i,j}$.


Constraints:
- $1 \leq N \leq 200$
- $0 \leq K \leq 1000000000000000000$
- $0 \leq a_{ij} < 998244353$


Input:
```
$N$ $K$
$a_{11}$ $a_{12}$ ... $a_{1N}$
$a_{21}$ $a_{22}$ ... $a_{2N}$
:
$a_{N1}$ $a_{N2}$ ... $a_{NN}$
```


Output:
```
$b_{11}$ $b_{12}$ ... $b_{1N}$
$b_{21}$ $b_{22}$ ... $b_{2N}$
:
$b_{N1}$ $b_{N2}$ ... $b_{NN}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'pow_of_matrix'
    pass


if __name__ == "__main__":
    solve()