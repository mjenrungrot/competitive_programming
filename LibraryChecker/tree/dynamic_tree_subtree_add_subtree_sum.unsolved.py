# Title: Dynamic Tree Subtree Add Subtree Sum
# URL: https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum
# Category: Tree

"""
Title: Dynamic Tree Subtree Add Subtree Sum

Link: https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum

Category: Tree


Statement:
You are given a tree with $N$ vertices. $i$-th edge connects vertex $u_i$ and vertex $v_i$. A number $a_i$ is written on vertex $i$.

Process $Q$ queries of the following types in order :

 - `0 $u$ $v$ $w$ $x$`: remove edge $(u, v)$ and add a new edge $(w, x)$. It is guranteed that the graph remains a tree after processing.
 - `1 $v$ $p$ $x$`: focusing on edge $(v, p)$ and regarding $p$ as a parent, add $x$ to values of all vertices in the subtree of vertex $v$.
 - `2 $v$ $p$`: focusing on edge $(v, p)$ and regarding $p$ as a parent, find the sum over values of all vertices in the subtree of vertex $v$.


Constraints:
- $2 \le N \le 200000$
 - $1 \le Q \le 200000$
 - $0 \le a_i \le 10000000$
 - $0 \le u_i, v_i < N$
 - The graph is a tree
 - For queries of type `0 $u$ $v$ $w$ $x$` :
    - $0 \le u, v, w, x \lt N$
    - Edge $(u, v)$ exists when processing a query of this type
    - The graph remains a tree after processing
 - For queries of type `1 $v$ $p$ $x$` :
    - $0 \le v, p \lt N$
    - $0 \le x \le 10000000$
    - Edge $(v, p)$ exists when processing a query of this type
 - For queries of type `2 $v$ $p$` :
    - $0 \le v, p \lt N$
    - Edge $(v, p)$ exists when processing a query of this type


Input:
~~~
$N$ $Q$
$a_0$ $a_1$ ... $a_{N - 1}$
$u_0$ $v_0$
$u_1$ $v_1$
$\hspace{11pt} \vdots$
$u_{N - 2}$ $v_{N - 2}$
$\mathrm{Query}_0$
$\mathrm{Query}_1$
$\hspace{14pt} \vdots$
$\mathrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'dynamic_tree_subtree_add_subtree_sum'
    pass


if __name__ == "__main__":
    solve()