# Title: Frequency Table of Tree Distance
# URL: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
# Category: Tree

"""
Title: Frequency Table of Tree Distance

Link: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance

Category: Tree


Statement:
Given a tree with $N$ vertices, where the $i$-th edge connects vertex $a_i$ and $b_i$. Denote by $x_i$ the number of pairs $(u, v)$ such that $\mathrm{dist}(u, v) = i$. Find $x_i$ for each $i = 1, 2, \cdots, N - 1$.

$\mathrm{dist}(u, v)$ denotes the number of edges on the unique path between vertex $u$ and $v$.


Constraints:
- $1 \leq N \leq 200000$
- $0 \leq a_i, b_i < N$
- $a_i \neq b_i$


Input:
```
$N$
$a_0$ $b_0$
$a_1$ $b_1$
$\vdots$
$a_{N-2}$ $b_{N-2}$
```


Output:
```
$x_1$ $x_2$ $\ldots$ $x_{N-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'frequency_table_of_tree_distance'
    pass


if __name__ == "__main__":
    solve()