# Title: Tetration Mod
# URL: https://judge.yosupo.jp/problem/tetration_mod
# Category: Number Theory

"""
Title: Tetration Mod

Link: https://judge.yosupo.jp/problem/tetration_mod

Category: Number Theory


Statement:
Each test cases consist of $T$ cases.

Given $A, B, M$. Print ${A \uparrow \uparrow B} (\bmod M)$.

We note that $0^0 = 1$ (at least in this problem).


Constraints:
- $1 \leq T \leq 1000$
- $0 \leq A, B \leq 10^9$
- $1 \leq M \leq 10^9$


Input:
```
$T$
$A_0$ $B_0$ $M_0$
$A_1$ $B_1$ $M_1$
:
$A_{T-1}$ $B_{T-1}$ $M_{T-1}$
```


Output:
For each line, print ${A \uparrow \uparrow B} (\bmod M)$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'tetration_mod'
    pass


if __name__ == "__main__":
    solve()