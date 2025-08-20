# Title: Rooted Tree Isomorphism Classification
# URL: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
# Category: Tree

"""
Title: Rooted Tree Isomorphism Classification

Link: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification

Category: Tree


Statement:
Given a rooted tree with $N$ vertices. The root of tree is the vertex $0$ . A parent of the vertex $i$ is $p _ i$ . You will get $N$ rooted subtrees by choosing a root. Classify them by isomorphism of rooted trees.

Now print a number of distinct subtrees $K$ and an integer seqence $a _ 0 , a _ 1 , \ldots , a _ {N-1}$ that satisfy the following conditions.

- $0 \leq a _ i \lt K$
- $a _ i = a _ j$ if and only if the $2$ subtrees whose roots are $i$ and $j$ are isomorphic.


Constraints:
- $1 \leq N \leq 500000$
- $0 \leq p _ i \lt i$


Input:
~~~
$N$
$p _ 1$ $p _ 2$ $\ldots$ $p _ {N-1}$
~~~


Output:
If there are multiple solutions, print any of them.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'rooted_tree_isomorphism_classification'
    pass


if __name__ == "__main__":
    solve()