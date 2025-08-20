# Title: Double-Ended Priority Queue
# URL: https://judge.yosupo.jp/problem/double_ended_priority_queue
# Category: Data Structure

"""
Title: Double-Ended Priority Queue

Link: https://judge.yosupo.jp/problem/double_ended_priority_queue

Category: Data Structure


Statement:
Given a multiset $S=\lbrace S_1, \ldots, S_N \rbrace$. Process the following $Q$ queries in order:

- `0 x`: Add $x$ to $S$.
- `1`: Output one of the minimum elements in $S$ and remove it from $S$.
- `2`: Output one of the maximum elements in $S$ and remove it from $S$.

It is guaranteed that $S$ is not empty when processing queries of types `1` and `2`.


Constraints:
- $0 \leq N \leq 500000$
- $1 \leq Q \leq 500000$
- $-1000000000 \leq S _ i, x \leq 1000000000$


Input:
```
$N\; Q$
$S_1 \cdots S_N$
$\mathrm{Query}_0$
$\vdots$
$\mathrm{Query}_{Q-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'double_ended_priority_queue'
    pass


if __name__ == "__main__":
    solve()