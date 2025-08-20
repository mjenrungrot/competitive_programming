# Title: System of Linear Equations (Mod 2)
# URL: https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2
# Category: Linear Algebra

"""
Title: System of Linear Equations (Mod 2)

Link: https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2

Category: Linear Algebra


Statement:
Given $N \times M$ matrix $A$, a size $N$ vector $b$. Please calculate a (size $M$) vector $x$ s.t. $Ax = b$. We consider everything $\mathbb{F}_{2}$.

For the input and output of matrices and vectors, please treat each row as a string concatenated with its components ($0$ or $1$).


Constraints:
- $1 \leq N \leq 4096$
- $1 \leq M \leq 4096$
- $A_{ij} \in \lbrace 0,1\rbrace$
- $b_{i} \in \lbrace 0,1\rbrace$


Input:
```
$N$ $M$
$A_{0,0}A_{0,1}\cdots A_{0,M-1}$
$A_{1,0}A_{1,1}\cdots A_{1,M-1}$
$\vdots$
$A_{N-1,0}A_{N-1,1}\cdots A_{N-1,M-1}$
$b_0b_1\cdots b_{N-1}$
```


Output:
If there is no solution, print
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'system_of_linear_equations_mod_2'
    pass


if __name__ == "__main__":
    solve()