# Title: Sum of Multiplicative Function(Large)
# URL: https://judge.yosupo.jp/problem/sum_of_multiplicative_function_large
# Category: Number Theory

"""
Title: Sum of Multiplicative Function(Large)

Link: https://judge.yosupo.jp/problem/sum_of_multiplicative_function_large

Category: Number Theory


Statement:
Given a multiplicative function $f(x)$, satisfying $f(p^e) = ae + bp$. Print $\displaystyle \sum_{i=1}^N f(i) \bmod 469762049$.  
($469762049$ is used instead of $998244353$ because it's easier to compute very long convolutions.)  
There are $T$ testcases.


Constraints:
- $1 \leq T \leq 10000$
- If $T = 1$, $1 \leq N \leq 10000000000000$. Otherwise, $1 \leq T \sqrt{N} \leq 1000000$.
- $0 \leq a, b \lt 469762049$


Input:
```
$T$
$N$ $a$ $b$
$N$ $a$ $b$
$\vdots$
$N$ $a$ $b$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'sum_of_multiplicative_function_large'
    pass


if __name__ == "__main__":
    solve()