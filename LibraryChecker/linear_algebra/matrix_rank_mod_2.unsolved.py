# Title: Rank of Matrix (Mod 2)
# URL: https://judge.yosupo.jp/problem/matrix_rank_mod_2
# Category: Linear Algebra

"""
Title: Rank of Matrix (Mod 2)

Link: https://judge.yosupo.jp/problem/matrix_rank_mod_2

Category: Linear Algebra


Statement:
Given $N \times M$ matrix $A = \lbrace a_{ij} \rbrace$ with entries in $\mathbb{Z}/2\mathbb{Z}$, print the matrix rank of $A$. 

When dealing with matrix input, please treat each row as a string concatenated with its components ($0$ or $1$).


Constraints:
- $0 \leq N, M \leq 16777216$
- $0 \leq NM \leq 16777216$
- $0 \leq a_{ij} < 2$


Input:
```
$N$ $M$
$a _ {11} \cdots a _ {1M}$
$\vdots$
$a _ {N1} \cdots a _ {NM}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'matrix_rank_mod_2'
    pass


if __name__ == "__main__":
    solve()