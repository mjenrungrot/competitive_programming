# Title: Tree Path Composite Sum
# URL: https://judge.yosupo.jp/problem/tree_path_composite_sum
# Category: Tree

"""
Title: Tree Path Composite Sum

Link: https://judge.yosupo.jp/problem/tree_path_composite_sum

Category: Tree


Statement:
You are given

- a tree with $N$ vertices,
- $N$ integers $a _ 0, a _ 1, \ldots, a _ {N-1}$ ,
- $N-1$ integers $b _ 0, b _ 1, \ldots, b _ {N-2}$ , and
- $N-1$ integers $c _ 0, c _ 1, \ldots, c _ {N-2}$ .

Edge $i$ connects vertices $u _ i$ and $v _ i$ bidirectionally.

For an integer $e$ that satisfies $0 \leq e \leq N-2$ , let $f _ e(x) = b _ e x + c _ e$ .

Let $e _ 0, e _ 1, \ldots, e _ k$ be the edges on the simple path from vertex $x$ to vertex $y$ in order, and define $P(x, y) = f _ {e _ 0}(f _ {e _ 1}(\ldots f _ {e _ k}(a _ y) \ldots ))$ .

Find $q _ x = \sum _ {y=0} ^ {N-1} P(x, y)$ modulo $998244353$ for each vertex $x$ .


Constraints:
- All input are integers.
- $1 \leq N \leq 200000$
- $0 \leq u _ i, v _ i \leq N - 1$
- $0 \leq a _ i \lt 998244353$
- $1 \leq b _ i \lt 998244353$
- $0 \leq c _ i \lt 998244353$


Input:
```
$N$
$a _ 0$ $a _ 1$ $\ldots$ $a _ {N-1}$
$u _ 0$ $v _ 0$ $b _ 0$ $c _ 0$
$u _ 1$ $v _ 1$ $b _ 1$ $c _ 1$
$\vdots$
$u _ {N-2}$ $v _ {N-2}$ $b _ {N-2}$ $c _ {N-2}$
```


Output:
```
$q _ 0$ $q _ 1$ $\ldots$ $q _ {N-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'tree_path_composite_sum'
    pass


if __name__ == "__main__":
    solve()