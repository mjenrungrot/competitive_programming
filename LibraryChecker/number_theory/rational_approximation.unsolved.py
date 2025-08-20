# Title: Rational Approximation
# URL: https://judge.yosupo.jp/problem/rational_approximation
# Category: Number Theory

"""
Title: Rational Approximation

Link: https://judge.yosupo.jp/problem/rational_approximation

Category: Number Theory


Statement:
You are given $T$ test cases. For each case, solve the following problem.

You are given positive integers $N, x, y$.
Let $S$ be the set of irreducible fractions whose numerator and denominator are both positive integers less than or equal to $N$.
Determine the maximum value in $S$ that is less than or equal to $x/y$ ($0/1$ if not exist) and the minimum value in $S$ that is greater than or equal to $x/y$ ($1/0$ if not exist).


Constraints:
- $1 \leq T \leq 100000$
- $1 \leq N, x, y \leq 1000000000$


Input:
```
$T$
$N_0$ $x_0$ $y_0$
$N_1$ $x_1$ $y_1$
$\vdots$
$N_{T-1}$ $x_{T-1}$ $y_{T-1}$
```


Output:
Print $T$ lines. When the values are $a/b$ and $c/d$, output as follows for each line.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'rational_approximation'
    pass


if __name__ == "__main__":
    solve()