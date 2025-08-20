# Title: Sqrt Mod
# URL: https://judge.yosupo.jp/problem/sqrt_mod
# Category: Number Theory

"""
Title: Sqrt Mod

Link: https://judge.yosupo.jp/problem/sqrt_mod

Category: Number Theory


Statement:
Each test cases consists of $T$ cases.

Given $Y, P(P: \textrm{prime})$.

Print $X$ s.t. $X^2 \equiv Y (\bmod P)$, or $-1$ if there is no such $X$.


Constraints:
- $1 \leq T \leq 100,000$
- $2 \leq P \leq 10^9$
- $0 \leq Y < P$
- $P$ is prime.


Input:
```
$T$
$Y_0$ $P_0$
$Y_1$ $P_1$
:
$Y_{T-1}$ $P_{T-1}$
```


Output:
For each line, print $X$ or $-1$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'sqrt_mod'
    pass


if __name__ == "__main__":
    solve()