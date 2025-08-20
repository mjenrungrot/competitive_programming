# Title: System of Linear Equations
# URL: https://judge.yosupo.jp/problem/system_of_linear_equations
# Category: Linear Algebra

"""
Title: System of Linear Equations

Link: https://judge.yosupo.jp/problem/system_of_linear_equations

Category: Linear Algebra


Statement:
Given $N \times M$ matrix $A$, a size $N$ vector $b$. Please calculate a (size $M$) vector $x$ s.t. $Ax = b$. We consider everything $\mathbb{F}_{998244353}$.


Constraints:
- $1 \leq N, M \leq 500$
- $0 \leq A_{ij} < 998244353$


Input:
```
$N$ $M$
$A_{0,0}$ $A_{0,1}$ ... $A_{0,M-1}$
$A_{1,0}$ $A_{1,1}$ ... $A_{1,M-1}$
:
$A_{N-1,0}$ $A_{N-1,1}$ ... $A_{N-1,M-1}$
$b_0$ $b_1$ ... $b_{N-1}$
```


Output:
If there is no solution, print
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'system_of_linear_equations'
    pass


if __name__ == "__main__":
    solve()