# Title: Binomial Coefficient
# URL: https://judge.yosupo.jp/problem/binomial_coefficient
# Category: Enumerative Combinatorics

"""
Title: Binomial Coefficient

Link: https://judge.yosupo.jp/problem/binomial_coefficient

Category: Enumerative Combinatorics


Statement:
Given integers $n,k$ and $m$, print $\binom{n}{k} \bmod m$.

Each test consists of $T$ cases, and $m$ is fixed in all cases.


Constraints:
- $1 \leq T \leq 200000$
- $1 \leq m \leq 1000000$
- $0 \leq k \leq n \leq 1000000000000000000$


Input:
```
$T\ m$
$n_0\ k_0$
$n_1\ k_1$
$\vdots$
$n_{T-1}\ k_{T-1}$
```


Output:
For each line, print $\binom{n}{k} \bmod m$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'binomial_coefficient'
    pass


if __name__ == "__main__":
    solve()