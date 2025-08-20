# Title: Range Reverse Range Sum
# URL: https://judge.yosupo.jp/problem/range_reverse_range_sum
# Category: Data Structure

"""
Title: Range Reverse Range Sum

Link: https://judge.yosupo.jp/problem/range_reverse_range_sum

Category: Data Structure


Statement:
You are given a sequence $a _ 0, a _ 1, ..., a _ {N - 1}$, consisting of $N$ integers.

Process $Q$ queries of the following types in order :

 - `0 $l$ $r$` : Reverse $a _ l, a _ {l + 1}, \dots, a _ {r - 1}$.
 - `1 $l$ $r$` : Print $\sum _ {i = l} ^ {r - 1} a _ i$.


Constraints:
- $0 \leq N \leq 200000$
- $0 \leq Q \leq 200000$
- $0 \leq a _ i \leq 1000000000$
- $0 \leq l _ j \leq r _ j \leq N$


Input:
~~~
$N$ $Q$
$a _ 0$ $a _ 1$ $\cdots$ $a _ {N - 1}$
$t _ 0$ $l _ 0$ $r _ 0$
$t _ 1$ $l _ 1$ $r _ 1$
$\vdots$
$t _ {Q - 1}$ $l _ {Q - 1}$ $r _ {Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'range_reverse_range_sum'
    pass


if __name__ == "__main__":
    solve()