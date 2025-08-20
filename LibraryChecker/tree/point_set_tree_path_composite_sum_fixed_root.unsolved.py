# Title: Point Set Tree Path Composite Sum (Fixed Root)
# URL: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
# Category: Tree

"""
Title: Point Set Tree Path Composite Sum (Fixed Root)

Link: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root

Category: Tree


Statement:
You are given

- a tree with $N$ vertices,
- $N$ integers $a _ 0, a _ 1, \ldots, a _ {N-1}$ ,
- $N-1$ integers $b _ 0, b _ 1, \ldots, b _ {N-2}$ , and
- $N-1$ integers $c _ 0, c _ 1, \ldots, c _ {N-2}$ .

Edge $i$ connects vertices $u _ i$ and $v _ i$ bidirectionally.

For an integer $e$ that satisfies $0 \leq e \leq N-2$ , let $f _ e(x) = b _ e x + c _ e$ .

Let $e _ 0, e _ 1, \ldots, e _ k$ be the edges on the simple path from vertex $0$ to vertex $y$ in order, and define $P(y) = f _ {e _ 0}(f _ {e _ 1}(\ldots f _ {e _ k}(a _ y) \ldots ))$ .

Process $Q$ queries in the order they are given. There are two types of queries:

- `0 w x` : Update $a_w$ to $x$ and then print $\left(\sum_{v=0}^{N-1} P(v)\right) \bmod 998244353$.
- `1 e y z` : Update $(b_e, c_e)$ to $(y, z)$ and then print $\left(\sum_{v=0}^{N-1} P(v)\right) \bmod 998244353$.


Constraints:
- All input are integers.
- $1 \leq N \leq 200000$
- $1 \leq Q \leq 200000$
- $0 \leq u _ i, v _ i \leq N - 1$
- $0 \leq a _ w \lt 998244353$
- $1 \leq b _ e \lt 998244353$
- $0 \leq c _ e \lt 998244353$
- $0 \leq w \leq N - 1$
- $0 \leq e \leq N - 2$
- $0 \leq x \lt 998244353$
- $1 \leq y \lt 998244353$
- $0 \leq z \lt 998244353$


Input:
$\mathrm{Query}_i$ represents the $i$-th query.


Output:
$p_i$ represents the answer to the $i$-th query.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'point_set_tree_path_composite_sum_fixed_root'
    pass


if __name__ == "__main__":
    solve()