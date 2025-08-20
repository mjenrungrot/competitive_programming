# Title: Rooted Tree Topological Order with Minimum Inversions
# URL: https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions
# Category: Tree

"""
Title: Rooted Tree Topological Order with Minimum Inversions

Link: https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions

Category: Tree


Statement:
You are given :

* a rooted tree of $N$ vertices ,
* $N$ integers $c _ 0 , c _ 1 , \dots , c _ {N-1}$ and
* $N$ integers $d _ 0 , d _ 1 , \dots , d _ {N-1}$.

The root of the tree is the vertex $0$ , and the parent of the vertex $i$ is $p _ i$ .

Find one permutation $p$ of $(0,1,\dots ,N-1)$ which satisfies following condition. If there are multiple candidates, you can choose any of them.

* If $i\neq j$ and the vertex $p _ i$ is an ancestor of the vertex $p _ j$, $i \lt j$ holds.
* Among one that satisfies the condition above, the value $X=\sum _ {i=0} ^ {N-1} \sum _ {j=0} ^ {i-1} c _ {p _ i} d _ {p _ j}$ is minimized.

Output the minimum value of $X$ and a possible permutation $p$ with the value $X$ is minimized.


Constraints:
- $1 \leq N \leq 200000$
- $0 \leq p _ i \lt i$
- $0 \leq c _ i \leq 1000000000$
- $0 \leq d _ i \leq 1000000000$
- $\sum _ {i=0} ^ {N-1} c _ i \leq 1000000000$
- $\sum _ {i=0} ^ {N-1} d _ i \leq 1000000000$


Input:
~~~
$N$
$p _ 1$ $p _ 2$ ... $p _ {N-1}$
$c _ 0$ $c _ 1$ ... $c _ {N-1}$
$d _ 0$ $d _ 1$ ... $d _ {N-1}$
~~~


Output:
~~~
$X$
$p _ 0$ $p _ 1$ $\ldots$ $p _ {N-1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'rooted_tree_topological_order_with_minimum_inversions'
    pass


if __name__ == "__main__":
    solve()