# Title: Rank of Matrix
# URL: https://judge.yosupo.jp/problem/matrix_rank
# Category: Linear Algebra

"""
Title: Rank of Matrix

Link: https://judge.yosupo.jp/problem/matrix_rank

Category: Linear Algebra


Statement:
Given $N \times M$ matrix $A$. Please calculate the rank of $A$. We consider everything $\mathbb{F}_{998244353}$.


Constraints:
- $0 \leq N, M \leq 250000$
- $NM\leq 250000$
- $0 \leq A_{ij} < 998244353$


Input:
```
$N$ $M$
$A_{0,0}$ $A_{0,1}$ ... $A_{0,M-1}$
$A_{1,0}$ $A_{1,1}$ ... $A_{1,M-1}$
:
$A_{N-1,0}$ $A_{N-1,1}$ ... $A_{N-1,M-1}$
```


Output:
Output the rank of $A$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'matrix_rank'
    pass


if __name__ == "__main__":
    solve()