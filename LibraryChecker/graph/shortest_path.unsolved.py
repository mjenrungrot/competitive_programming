# Title: Shortest Path
# URL: https://judge.yosupo.jp/problem/shortest_path
# Category: Graph

"""
Title: Shortest Path

Link: https://judge.yosupo.jp/problem/shortest_path

Category: Graph


Statement:
You are given a simple directed weighted graph, consisting of $N$ vertices and $M$ edges.  
The $i$-th edge is directed from vertex $a_i$ to vertex $b_i$ and has a weight of $c_i$.  
Find the (simple) shortest path from vertex $s$ to vertex $t$, or report that no such path exists.  
If there are multiple shortest paths, print any of them.


Constraints:
- $2 \leq N \leq 500000$
- $1 \leq M \leq 500000$
- $0 \leq s \lt N$
- $0 \leq t \lt N$
- $s \neq t$
- $0 \leq a_i \lt N$
- $0 \leq b_i \lt N$
- $a_i \neq b_i$
- $(a_i, b_i) \neq (a_j, b_j) (i \neq j)$
- $0 \leq c_i \leq 1000000000$


Input:
```
$N$ $M$ $s$ $t$
$a_0$ $b_0$ $c_0$
$a_1$ $b_1$ $c_1$
$a_2$ $b_2$ $c_2$
$\vdots$
$a_{M - 1}$ $b_{M - 1}$ $c_{M - 1}$
```


Output:
If there are no paths from vertex $s$ to vertex $t$, output ```-1```.
Otherwise, output one of the shortest paths in the following format.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'shortest_path'
    pass


if __name__ == "__main__":
    solve()