# Title: Ordered Set
# URL: https://judge.yosupo.jp/problem/ordered_set
# Category: Data Structure

"""
Title: Ordered Set

Link: https://judge.yosupo.jp/problem/ordered_set

Category: Data Structure


Statement:
You are given a set of non-negative integers $S = \lbrace a_0, \ldots, a_{N-1} \rbrace$.
Please process the following $Q$ queries:

- 0 $x$: If $x \notin S$, insert $x$ into $S$. If $x \in S$, do nothing.
- 1 $x$: If $x \in S$, remove $x$ from $S$. If $x \notin S$, do nothing.
- 2 $x$: Output the $x$-th smallest element of $S$ in ascending order. If $|S| < x$, output $-1$.
- 3 $x$: Output the number of elements in $S$ that are less than or equal to $x$.
- 4 $x$: Output the largest element in $S$ that is less than or equal to $x$ (or $-1$ if no such element exists).
- 5 $x$: Output the smallest element in $S$ that is greater than or equal to $x$ (or $-1$ if no such element exists).


Constraints:
- $0 \leq N \leq 500000$
- $1 \leq Q \leq 500000$
- $0 \leq a _ 0 < \cdots < a _ {N-1} \leq 1000000000$
- $0\leq x \leq 1000000000$
- $1\leq x$ if $t = 2$


Input:
```
$N$ $Q$
$a_0$ $\cdots$ $a_{N-1}$
$t$ $x$
$\vdots$
$t$ $x$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'ordered_set'
    pass


if __name__ == "__main__":
    solve()