# Title: Sum of Floor of Linear
# URL: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
# Category: Number Theory

"""
Title: Sum of Floor of Linear

Link: https://judge.yosupo.jp/problem/sum_of_floor_of_linear

Category: Number Theory


Statement:
Each test case consists of $T$ cases.

Given $N, M, A, B$. Print $\sum_{i = 0}^{N - 1} floor((A \times i + B) / M)$.


Constraints:
- $1 \leq T \leq 100,000$
- $1 \leq N, M \leq 10^9$
- $0 \leq A, B < M$


Input:
```
$T$
$N_0$ $M_0$ $A_0$ $B_0$
$N_1$ $M_1$ $A_1$ $B_1$
:
$N_{T - 1}$ $M_{T - 1}$ $A_{T - 1}$ $B_{T - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'sum_of_floor_of_linear'
    pass


if __name__ == "__main__":
    solve()