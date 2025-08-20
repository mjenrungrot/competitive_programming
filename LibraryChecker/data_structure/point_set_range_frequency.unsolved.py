# Title: Point Set Range Frequency
# URL: https://judge.yosupo.jp/problem/point_set_range_frequency
# Category: Data Structure

"""
Title: Point Set Range Frequency

Link: https://judge.yosupo.jp/problem/point_set_range_frequency

Category: Data Structure


Statement:
You are given an integer sequence $a_0, a_1, \ldots, a_{N-1}$ with the length $N$. Process the following $Q$ queries in order:

- `0 $k$ $v$`: $a[k] \gets v$
- `1 $l$ $r$ $x$` : Print the number of times $x$ occurs in $a_{l}, a_{l+1}, \ldots, a_{r-1}$.


Constraints:
- $0 \leq N \leq 200000$
- $0 \leq Q \leq 200000$
- $0 \leq a_i \leq 1000000000$
- $0 \leq k < N$
- $0 \leq v \leq 1000000000$
- $0 \leq l \leq r \leq N$
- $0 \leq x \leq 1000000000$


Input:
```
$N$ $Q$
$a_0$ $a_1$ $\cdots$ $a_{N-1}$
$\mathrm{query}_0$
$\vdots$
$\mathrm{query}_{Q-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'point_set_range_frequency'
    pass


if __name__ == "__main__":
    solve()