# Title: Inverse Matrix
# URL: https://judge.yosupo.jp/problem/inverse_matrix
# Category: Linear Algebra

"""
Title: Inverse Matrix

Link: https://judge.yosupo.jp/problem/inverse_matrix

Category: Linear Algebra


Statement:
Given $N \times N$ matrix $A = \lbrace a_{ij} \rbrace$ with entries in $\mathbb{Z}/998244353\mathbb{Z}$, print $A^{-1} = \lbrace b_{ij} \rbrace$. If it doesn't exist, print `-1`.


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
If there are no matrices satisfying the condition, print
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'inverse_matrix'
    pass


if __name__ == "__main__":
    solve()