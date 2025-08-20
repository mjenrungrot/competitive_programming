# Title: Persistent Range Affine Range Sum
# URL: https://judge.yosupo.jp/problem/persistent_range_affine_range_sum
# Category: Data Structure

"""
Title: Persistent Range Affine Range Sum

Link: https://judge.yosupo.jp/problem/persistent_range_affine_range_sum

Category: Data Structure


Statement:
Given a size $N$ integer sequence $a _ 0, a _ 1, \dots, a _ {N - 1}$.
Let $A _ {-1}$ be the sequence $(a _ 0, a _ 1, \dots, a _ {N - 1})$.

For $i=0,1,\ldots ,Q-1$ , process a query as follows:

- `0 $k$ $l$ $r$ $b$ $c$`: Make a copy of $A _ {k}$ as $A _ i$ . For each $j = l, l+1, \dots, {r - 1}$ , on $A _ i$ , $a _ j \gets b \times a _ j + c$.
- `1 $k$ $s$ $l$ $r$`: Make a copy of $A _ {k}$ as $A _ i$ . For each $j = l, l+1, \dots, {r - 1}$ , on $A _ i$ , $a _ j \gets a ^ {\prime} _ j$ (where $a ^ {\prime} _ j$ is the value of $a _ j$ in $A _ {s}$ ).
- `2 $k$ $l$ $r$`: Print $\sum_{j = l} ^ {r - 1} a _ j \bmod 998244353$ from $A _ {k}$.


Constraints:
Let $t _ i$ as the type of the $i$-th query ($0\leq i \lt Q$ , $t _ i\in\lbrace 0,1,2\rbrace$) .

- $1 \leq N \leq 100000$
- $1 \leq Q \leq 100000$
- $0 \leq a \lt 998244353$
- $1 \leq b \lt 998244353$
- $0 \leq c \lt 998244353$
- $-1 \leq k \lt i$
- $k=-1$ or $t _ k\in \lbrace 0,1\rbrace$
- $-1 \leq s \lt i$
- $s=-1$ or $t _ s\in \lbrace 0,1\rbrace$
- $0 \leq l \lt r \leq N$


Input:
~~~
$N$ $Q$
$a _ 0$ $a _ 1$ ... $a _ {N - 1}$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'persistent_range_affine_range_sum'
    pass


if __name__ == "__main__":
    solve()