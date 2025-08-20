# Title: Static RMQ
# URL: https://judge.yosupo.jp/problem/staticrmq
# Category: Data Structure

"""
Title: Static RMQ

Link: https://judge.yosupo.jp/problem/staticrmq

Category: Data Structure


Statement:
You are given an integer sequence $a_0, a_1, ..., a_{N-1}$ with the length $N$.
Process the following $Q$ queries in order:

- `$l_i$ $r_i$`: Print $\min(a_{l_i}, a_{l_i + 1}, ..., a_{r_i - 1})$.


Constraints:
- $1 \leq N, Q \leq 500000$
- $0 \leq a_i \leq 10^9$
- $0 \leq l_i < r_i \leq N$


Input:
~~~
$N$ $Q$
$a_0$ $a_1$ ... $a_{N - 1}$
$l_1$ $r_1$
$l_2$ $r_2$
:
$l_Q$ $r_Q$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'staticrmq'
    pass


if __name__ == "__main__":
    solve()