# Title: Tree Diameter
# URL: https://judge.yosupo.jp/problem/tree_diameter
# Category: Tree

"""
Title: Tree Diameter

Link: https://judge.yosupo.jp/problem/tree_diameter

Category: Tree


Statement:
You are given a weighted undirected tree with $N$ vertices.
The $i$-th edge bidirectionally connects vertices $a_i$ and $b_i$, and its weight is $c_i$.

Find a pair of vertices $(u, v)$ that are farthest apart, and output the path from $u$ to $v$.


Constraints:
- All input are integers.
- $1 \leq N \leq 500000$
- $0 \leq a_i, b_i \leq N - 1$
- $a_i \neq b_i$
- $1 \leq c_i \leq 1000000000$


Input:
```
$N$
$a_0$ $b_0$ $c_0$
$a_1$ $b_1$ $c_1$
$\vdots$
$a_{N-2}$ $b_{N-2}$ $c_{N-2}$
```


Output:
$X$ is the sum of weights on the path, and $Y$ is the number of vertices on the path.
$u_i$ and $u_{i+1}$ are the starting and ending vertices of the $i+1$-th edge traveled.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'tree_diameter'
    pass


if __name__ == "__main__":
    solve()