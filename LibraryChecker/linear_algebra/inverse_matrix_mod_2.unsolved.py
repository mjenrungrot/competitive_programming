# Title: Inverse Matrix (Mod 2)
# URL: https://judge.yosupo.jp/problem/inverse_matrix_mod_2
# Category: Linear Algebra

"""
Title: Inverse Matrix (Mod 2)

Link: https://judge.yosupo.jp/problem/inverse_matrix_mod_2

Category: Linear Algebra


Statement:
Given $N \times N$ matrix $A = \lbrace a_{ij} \rbrace$ with entries in $\mathbb{Z}/2\mathbb{Z}$, print $A^{-1} = \lbrace b_{ij} \rbrace$. If it doesn't exist, print `-1`.

When dealing with matrix input and output, please treat each row as a string concatenated with its components ($0$ or $1$).


Constraints:
- $1 \leq N \leq 4096$
- $0 \leq a_{ij} < 2$


Input:
```
$N$
$a _ {11} \cdots a _ {1N}$
$\vdots$
$a _ {N1} \cdots a _ {NN}$
```


Output:
If there are no matrices satisfying the condition, print
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'inverse_matrix_mod_2'
    pass


if __name__ == "__main__":
    solve()