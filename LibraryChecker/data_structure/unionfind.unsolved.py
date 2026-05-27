# Title: Unionfind
# URL: https://judge.yosupo.jp/problem/unionfind
# Category: Data Structure

"""
Title: Unionfind

Link: https://judge.yosupo.jp/problem/unionfind

Category: Data Structure


Statement:
We have an undirected graph with $N$ vertices and $0$ edges.
Process the following $Q$ queries in order:

- `$t_i$ = 0 $u_i$ $v_i$`: Add an edge $(u, v)$.
- `$t_i$ = 1 $u_i$ $v_i$`: If vertices $u, v$ are connected, print $1$. Otherwise, print $0$.


Constraints:
- $1 \leq N \leq 200000$
- $1 \leq Q \leq 200000$
- $0 \leq u_i, v_i \lt N$


Input:
~~~
$N$ $Q$
$t_1$ $u_1$ $v_1$
$t_2$ $u_2$ $v_2$
:
$t_Q$ $u_Q$ $v_Q$
~~~


Editorial:

Problem Overview

- We start with an empty undirected graph on `N` vertices and process `Q` operations of two types: add an edge `(u, v)` or query whether `u` and `v` are connected. The graph evolves only by adding edges (never removing), so connectivity is monotone.

Key Data Structure

- Disjoint Set Union (DSU), also known as Union-Find, maintains a partition of the vertices into connected components under edge insertions. It supports:
  - `find(x)`: returns the representative (root) of the set containing `x`.
  - `union(a, b)`: merges the sets containing `a` and `b`.
  - `same(a, b)`: checks if `find(a) == find(b)`.
- With path compression in `find` and union by size/rank in `union`, each operation runs in amortized O(α(N)) time, where α is the inverse Ackermann function (practically constant).

Algorithm

- Initialize DSU on `N` elements, each being its own set.
- For each query `(t, u, v)`:
  - If `t = 0`: call `union(u, v)` to connect the two components.
  - If `t = 1`: output `1` if `same(u, v)` else `0`.

Correctness Argument

- Invariant: DSU partitions vertices exactly by the connectivity relation induced by the edges processed so far.
  - Base: Initially, no edges, each vertex is isolated — DSU starts with `N` singleton sets.
  - Update: Adding edge `(u, v)` merges the components of `u` and `v`, which is exactly what connectivity requires; union maintains the transitive closure via set merging.
  - Query: Two vertices are connected if and only if they are in the same component; DSU checks this by comparing roots.
- Therefore, answers produced by DSU coincide with graph connectivity after each step.

Complexity

- Time: O((N + Q) α(N)), effectively linear for given constraints (`N, Q ≤ 2e5`).
- Memory: O(N) for the parent/size arrays.

Implementation Notes

- Store `parent_or_size[i]` with the convention: if `i` is a root, it stores `-size_of_set`; otherwise it stores the parent index. This enables union by size without extra arrays.
- Implement `find(x)` with path compression (iterative or recursive). In Python, an iterative version avoids recursion depth concerns.
- Input size is large; prefer `sys.stdin.buffer.read()` and write answers via a list joined by newlines for speed.
- Edge cases: self-union `(u == v)` and union of already-connected vertices must be handled idempotently (no change, no error).

Pseudocode

```
init(n): parent = [-1] * n

find(x):
  r = x
  while parent[r] >= 0: r = parent[r]
  # path compression
  while x != r:
    p = parent[x]
    parent[x] = r
    x = p
  return r

union(a, b):
  ra, rb = find(a), find(b)
  if ra == rb: return False
  if parent[ra] > parent[rb]: ra, rb = rb, ra  # ra has larger size (more negative)
  parent[ra] += parent[rb]
  parent[rb] = ra
  return True

same(a, b): return find(a) == find(b)
```

Why DSU is Optimal Here

- The graph changes only by adding edges; DSU maintains the connected components incrementally with near-constant-time updates and queries. Heavier structures (dynamic connectivity with deletions) are unnecessary.
"""

import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'unionfind'
    pass


if __name__ == "__main__":
    solve()
