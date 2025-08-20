# Title: Adjugate Matrix
# URL: https://judge.yosupo.jp/problem/adjugate_matrix
# Category: Linear Algebra

"""
Title: Adjugate Matrix

Link: https://judge.yosupo.jp/problem/adjugate_matrix

Category: Linear Algebra


Statement:
Given $N \times N$ matrix $A = \lbrace a_{ij} \rbrace$ with entries in $\mathbb{Z}/998244353\mathbb{Z}$, print $\operatorname{adj} A = \lbrace (-1)^{i+j}M_{ji} \rbrace$, where $M_{ij}$ is the determinant of the matrix that is obtained from $A$ by removing its $i$-th row and $j$-th column.


Constraints:
- $1 \leq N \leq 500$
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
Print $b_{ij} = (-1)^{i+j} M_{ji}$:
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'adjugate_matrix'
    pass


if __name__ == "__main__":
    solve()