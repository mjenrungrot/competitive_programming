# Title: Common Interval Decomposition Tree
# URL: https://judge.yosupo.jp/problem/common_interval_decomposition_tree
# Category: Tree

"""
Title: Common Interval Decomposition Tree

Link: https://judge.yosupo.jp/problem/common_interval_decomposition_tree

Category: Tree


Statement:
Given a size-$N$ permutation $P_0, P_1, \cdots, P_{N-1}$,
print the **common interval decomposition tree** corresponding to this permutation.  In this question, the terms are defined as follows.

- An **interval** is a set that can be expressed as $\lbrace i\in \mathbb{Z}\ |\ l \leq i \leq r\rbrace $ for some integers $l$ and $r$ ($\ 0 \leq l \leq r <N$). We denote such an **interval** by **interval** $\[l, r\]$.
- A **connected interval** is an **interval** $\[l, r\]$ such that $\lbrace P_i\ |\ l \leq i \leq r\rbrace$ is also an **interval**.
- A **strong interval** is a **connected interval** $I$ such that one of $I \subset J$, $J \subset I$, and $I \cap J =\emptyset$ holds for all **connected interval** $J$.
- The **common interval decomposition tree** is a rooted tree expressed as the Hasse diagram of the entire **strong intervals** for the partial order by inclusion.
- A **linear node** is a vertex such that, when its children is arranged in ascending order of their left ends $l$, the union of any consecutive children forms a **connected interval**.
- A **prime node** is a vertex that is not a **linear node**.


Constraints:
- $1 \leq N \leq 500000$
- $0 \leq P_i < N$
- $P_i \neq P_j (i \neq j)$


Input:
~~~
$N$
$P_0\ P_1\ P_2\ \cdots P_{N-1}$
~~~


Output:
$X$ is the number of vertices in the **common interval decomposition tree**.  $p_i$( $p_i < i$ ) is the integer numbered to the vertex that is the parent of the $i$-th vertex, or $p_i=-1$ if the $i$-th vertex is a tree root. $\[l_i,r_i\]$ is the **interval** corresponding to the $i$-th vertex, and $S_i$ is "linear" if the $i$-th vertex is a **linear node** or "prime" if it is a **prime node**.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'common_interval_decomposition_tree'
    pass


if __name__ == "__main__":
    solve()