# Title: Number of Increasing Sequences Between Two Sequences
# URL: https://judge.yosupo.jp/problem/number_of_increasing_sequences_between_two_sequences
# Category: Enumerative Combinatorics

"""
Title: Number of Increasing Sequences Between Two Sequences

Link: https://judge.yosupo.jp/problem/number_of_increasing_sequences_between_two_sequences

Category: Enumerative Combinatorics


Statement:
Given integers $N,M$ and two non-negative integer sequences $A = \left( A_0, A_1, \cdots, A_{N-1} \right), B = \left( B_0, B_1, \cdots, B_{N-1} \right)$.

Find the number of a non-negative integer sequences $x = \left( x_0, x_1, \cdots, x_{N-1} \right)$ which satisfies the following conditions, and print it $\bmod \ 998244353$.

- $0 \leq x_0 \leq \cdots \leq x_{N-1} < M$
- $A_i \leq x_i < B_i$


Constraints:
- $1 \leq N \leq 131072$
- $1 \leq M \leq 131072$
- $0 \leq A_i < B_i \leq M$ ($0 \leq i \leq N - 1$)


Input:
```
$N$ $M$
$A_0$ $A_1$ $\cdots$ $A_{N-1}$
$B_0$ $B_1$ $\cdots$ $B_{N-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'number_of_increasing_sequences_between_two_sequences'
    pass


if __name__ == "__main__":
    solve()