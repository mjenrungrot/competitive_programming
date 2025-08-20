# Title: Predecessor Problem
# URL: https://judge.yosupo.jp/problem/predecessor_problem
# Category: Data Structure

"""
Title: Predecessor Problem

Link: https://judge.yosupo.jp/problem/predecessor_problem

Category: Data Structure


Statement:
Let $S$ be a set consisting of integers between $0$ to $N-1$. Process the following $Q$ queries: 

- 0 $k$ : If $k\notin S$, insert $k$ into $S$. If $k\in S$, do nothing.
- 1 $k$ : If $k\in S$, remove $k$ from $S$. If $k\notin S$, do nothing.
- 2 $k$ : if $S$ contains $k$, print $1$. Otherwise, print $0$.
- 3 $k$ : Print the smallest key which is greater than or equal to $k$(if there are no keys, print $-1$).
- 4 $k$ : Print the largest key which is smaller than or equal to $k$(if there are no keys, print $-1$).


Constraints:
- $1 \leq N \leq 10000000$
- $1 \leq Q \leq 1000000$
- $0 \leq k_i \lt N$


Input:
The initial state of $S$ is given as a length $N$ string $T$  consisting of $0$ and $1$. $S$ contains $i$ if and only if $T_i = 1$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'predecessor_problem'
    pass


if __name__ == "__main__":
    solve()