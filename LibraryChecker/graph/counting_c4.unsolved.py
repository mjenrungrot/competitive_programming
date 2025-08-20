# Title: Counting $C _ 4$'s
# URL: https://judge.yosupo.jp/problem/counting_c4
# Category: Graph

"""
Title: Counting $C _ 4$'s

Link: https://judge.yosupo.jp/problem/counting_c4

Category: Graph


Statement:
You are given an undirected graph, consisting of $N$ vertices and $M$ edges. This graph may not be simple.
The $i$-th edge is $\lbrace u _ i, v _ i \rbrace$.

For each edge $i$, find $A _ i$ , as the number of unordered combinations of $3$ edges $x$ , $y$ , $z$
that those $4$ edges ( $i,x,y,z$ ) forms a subgraph isomorphic to $C _ 4$ ( A cycle with $4$ edges ).


Constraints:
- $2 \le N \le 300000$
- $1 \le M \le 300000$
- $0 \le u _ i \lt N$
- $0 \le v _ i \lt N$
- $u _ i \neq v _ i$


Input:
```
$N$ $M$
$u _ 0$ $v _ 0$
$u _ 1$ $v _ 1$
$\vdots$
$u _ {M-1}$ $v _ {M-1}$
```


Output:
```
$A _ 0$ $A _ 1$ $\cdots$ $A _ {M-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'counting_c4'
    pass


if __name__ == "__main__":
    solve()