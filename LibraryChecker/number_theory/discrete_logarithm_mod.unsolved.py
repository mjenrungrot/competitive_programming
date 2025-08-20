# Title: Discrete Logarithm
# URL: https://judge.yosupo.jp/problem/discrete_logarithm_mod
# Category: Number Theory

"""
Title: Discrete Logarithm

Link: https://judge.yosupo.jp/problem/discrete_logarithm_mod

Category: Number Theory


Statement:
Each test case consist of $T$ cases.

Given $X, Y, M$. Print the minimum non-negative integer $K$ s.t. $X^K \equiv Y (\bmod M)$, or $-1$ if there is no such $K$.

We note that $0^0 = 1$ in this problem.


Constraints:
- $1 \leq T \leq 100$
- $0 \leq X, Y < M$
- $1 \leq M \leq 10^9$


Input:
```
$T$
$X_0$ $Y_0$ $M_0$
$X_1$ $Y_1$ $M_1$
:
$X_{T - 1}$ $Y_{T - 1}$ $M_{T - 1}$
```


Output:
For each line, print answer.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'discrete_logarithm_mod'
    pass


if __name__ == "__main__":
    solve()