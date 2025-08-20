# Title: Static RMQ
# URL: https://judge.yosupo.jp/problem/staticrmq
# Category: Data Structure

"""
Title: Static RMQ

Link: https://judge.yosupo.jp/problem/staticrmq

Category: Data Structure


Statement:
You are given an integer sequence $a_0, a_1, ..., a_{N-1}$ with the length $N$.
Process the following $Q$ queries in order:

- `$l_i$ $r_i$`: Print $\min(a_{l_i}, a_{l_i + 1}, ..., a_{r_i - 1})$.


Constraints:
- $1 \leq N, Q \leq 500000$
- $0 \leq a_i \leq 10^9$
- $0 \leq l_i < r_i \leq N$


Input:
~~~
$N$ $Q$
$a_0$ $a_1$ ... $a_{N - 1}$
$l_1$ $r_1$
$l_2$ $r_2$
:
$l_Q$ $r_Q$
~~~


Editorial:

Overview
- We must answer many range-minimum queries (RMQ) on a static array (no updates).
- The min operation is idempotent and associative, which enables powerful table precomputation.

Sparse Table Solution
- Idea: Precompute answers for all intervals of length 2^k starting at each index.
- Table definition: st[k][i] = min over the subarray a[i .. i + 2^k - 1].
- Build recurrence: st[0][i] = a[i]; for k > 0,
  st[k][i] = min(st[k-1][i], st[k-1][i + 2^{k-1}]).
- Query [l, r): let len = r - l and k = floor(log2(len)). The minimum over [l, r) is the min of two overlapping blocks of length 2^k:
  ans = min(st[k][l], st[k][r - 2^k]).
  This works because the union of these two blocks covers [l, r), and min is idempotent.

Complexity Analysis
- Build: There are about log2(N) levels; each level scans O(N) entries.
  Total preprocessing time O(N log N), memory O(N log N).
- Query: We only compute k and take two table lookups and one min.
  Per-query time O(1), so total query time O(Q).
- Overall: O(N log N + Q) time, which is excellent when Q is large (up to 5e5),
  because each query is constant time after preprocessing.

Why This Is Good Here
- The problem is static: we never update the array. Sparse Table specializes in this regime.
- RMQ is an idempotent operation, so overlapping blocks are safe to combine without double counting.
- For typical limits (N up to 5e5), log2(N) ≈ 19. In languages with flat arrays, memory ~ N * log2(N) integers is practical.

Practical Notes (Python)
- Python objects are heavier than primitive arrays. A naive 2D list sparse table may use a lot of memory when N is near the upper bound.
- If memory is tight, alternatives include:
  - Segment Tree: O((N + Q) log N) time, O(N) memory, simpler and memory-friendly in Python.
  - Disjoint Sparse Table: Same asymptotics for static queries, with a slightly different layout.
  - Fischer-Heun RMQ: O(N) build and O(1) query with O(N) memory, but significantly more complex to implement.
- For competitive programming in Python, Segment Tree often passes within time/memory; Sparse Table is preferable if memory allows and maximum throughput is needed.


Segment Tree Solution (Alternative 1)

Idea
- Build a binary tree where each node stores the min over a segment of the array.
- Leaves correspond to single elements; internal nodes store min(left, right).

Build
- Bottom-up (iterative) or top-down (recursive) construction in O(N).
- Iterative approach: pad to the next power of two, put the array at the leaves, then compute parents upward.

Query [l, r)
- Walk upward while covering the query range with O(log N) disjoint segments.
- Combine answers using min as you expand from the left/right borders.

Complexity and When It's Good
- Build O(N), each query O(log N), total O(N + Q log N).
- Memory O(N).
- Excellent when updates are needed (point/range with lazy propagation) or when Sparse Table memory is too large in Python.
- With N, Q ≤ 5e5 and log2(N) ≈ 19, Q log N ≈ 9.5M operations — practical in Python with tight loops and fast I/O.

"""

MAX_N = 500_005
MAX_Q = 500_005
MAX_A = 10**9 + 5


def get_input() -> tuple[int, int, list[int], list[tuple[int, int]]]:
    N, Q = map(int, input().split())
    a = list(map(int, input().split()))
    queries = [tuple(map(int, input().split())) for _ in range(Q)]
    return N, Q, a, queries


def solution_sparse_table(
    N: int,
    Q: int,
    a: list[int],
    queries: list[tuple[int, int]],
) -> list[int]:
    num_depth = MAX_N.bit_length() + 1
    st = [[0] * MAX_N for _ in range(num_depth)]

    # Base case: st[0][i] = a[i]
    for i in range(N):
        st[0][i] = a[i]

    # Recursive case: st[k][i] = min(st[k - 1][i], st[k - 1][i + 2^(k - 1)])
    for k in range(1, num_depth):
        for i in range(N - (1 << k) + 1):
            st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))])

    # queries
    for left, right in queries:
        k = (right - left).bit_length() - 1
        ans = min(st[k][left], st[k][right - (1 << k)])
        print(ans)


def solve():
    N, Q, a, queries = get_input()
    solution_sparse_table(N, Q, a, queries)


if __name__ == "__main__":
    solve()
