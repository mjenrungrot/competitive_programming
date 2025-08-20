# Title: Determinant of Matrix (Mod 2)
# URL: https://judge.yosupo.jp/problem/matrix_det_mod_2
# Category: Linear Algebra

"""
Title: Determinant of Matrix (Mod 2)

Link: https://judge.yosupo.jp/problem/matrix_det_mod_2

Category: Linear Algebra


Statement:
Given $N \times N$ matrix $M = (a_{ij})$. Print $\mathrm{det}(M) \bmod 2$.

When dealing with matrix input and output, please treat each row as a string concatenated with its components ($0$ or $1$).


Constraints:
- $1 \leq N \leq 4096$
- $a_{ij} \in \lbrace 0,1\rbrace$


Input:
```
$N$
$a_{11}a_{12} \cdots a_{1N}$
$a_{21}a_{22} \cdots a_{2N}$
$\vdots$
$a_{N1}a_{N2} \cdots a_{NN}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'matrix_det_mod_2'
    pass


if __name__ == "__main__":
    solve()