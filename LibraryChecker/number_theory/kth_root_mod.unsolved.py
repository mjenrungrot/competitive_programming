# Title: Kth Root (Mod)
# URL: https://judge.yosupo.jp/problem/kth_root_mod
# Category: Number Theory

"""
Title: Kth Root (Mod)

Link: https://judge.yosupo.jp/problem/kth_root_mod

Category: Number Theory


Statement:
Each test case consists of $T$ cases.

Given $K, Y, P(P: \textrm{prime})$.

Print any $X$ s.t. $X^K \equiv Y \pmod{P}$, or $-1$ if there is no such $X$.

We note that $0^0\equiv 1 \pmod{P}$ in this problem.


Constraints:
- $1 \leq T \leq 5000$
- $0 \leq K \leq 1000000000$
- $2 \leq P \leq 1000000000$
- $0 \leq Y  < P$
- $P$ is prime.


Input:
```
$T$
$K_0$ $Y_0$ $P_0$
$K_1$ $Y_1$ $P_1$
$\vdots$
$K_{T-1}$ $Y_{T-1}$ $P_{T-1}$
```


Output:
For each line, print $X$ or $-1$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'kth_root_mod'
    pass


if __name__ == "__main__":
    solve()