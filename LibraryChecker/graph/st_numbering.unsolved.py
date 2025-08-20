# Title: st-Numbering
# URL: https://judge.yosupo.jp/problem/st_numbering
# Category: Graph

"""
Title: st-Numbering

Link: https://judge.yosupo.jp/problem/st_numbering

Category: Graph


Statement:
This problem has $T$ cases. 

You are given an undirected graph $G$, consisting of $N$ vertices and $M$ edges. The $i$-th edge connects vertices $u _ i$ and $v _ i$. This graph may not be simple but does not contain any self-loops.

You are also given two vertices $s$ and $t$ of $G$. 

Determine if there exists a permutation $p = (p _ 0,\ldots,p _ {N - 1})$ of the vertices satisfying the following condition, and if so, find such a permutation.

- Orient each edge of $G$ from $u _ i$ to $v _ i$ if $p _ {u _ i} < p _ {v _ i}$, or from $v _ i$ to $u _ i$ if $p _ {v _ i} < p _ {u _ i}$. Then, for any vertex $v$, there exists a path from $s$ to $t$ that passes through $v$.


Constraints:
- $1 \leq T \leq 100000$
- $1 \leq N \leq 200000$
- $0 \leq M \leq 200000$
- $0 \leq s, t \lt N$
- $s\neq t$
- $0 \leq u _ i, v _ i \lt N$
- $u _ i\neq v _ i$
- The sum of $N$ over all test cases does not exceed $200000$. 
- The sum of $M$ over all test cases does not exceed $200000$.


Input:
~~~
$T$
$N$ $M$ $s$ $t$
$u _ 0$ $v _ 0$
$\vdots$
$u _ {M - 1}$ $v _ {M - 1}$
$N$ $M$ $s$ $t$
$u _ 0$ $v _ 0$
$\vdots$
$u _ {M - 1}$ $v _ {M - 1}$
$\vdots$
~~~


Output:
If there exists no permutation $p$ satisfying the condition, print `No`. Otherwise, print a permutation $p$ in the following format.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'st_numbering'
    pass


if __name__ == "__main__":
    solve()