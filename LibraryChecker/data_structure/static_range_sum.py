# Title: Static Range Sum
# URL: https://judge.yosupo.jp/problem/static_range_sum
# Category: Data Structure

r"""
Title: Static Range Sum

Link: https://judge.yosupo.jp/problem/static_range_sum

Category: Data Structure


Statement:
You are given a non-negative integer sequence $A = (a_0, a_1, \ldots, a_{N-1})$ with the length $N$. Process the following $Q$ queries in order:

- You are given integers $l_i$ and $r_i$. Print $\sum_{k=l_i}^{r_i-1} a_k$.


Constraints:
- $1 \leq N \leq 500000$
- $1 \leq Q \leq 500000$
- $0 \leq a_i \leq 1000000000$
- $0 \leq l_i < r_i \leq N$


Input:
```
$N$ $Q$
$a_0$ $a_1$ $\ldots$ $a_{N-1}$
$l_1$ $r_1$
$\vdots$
$l_Q$ $r_Q$
```


Editorial:
Problem Overview

- Given: array A[0..N-1] (non-negative), and Q queries (l, r).
- Task: report sum(A[l..r-1]) for each query.
- Constraints: up to N, Q = 5e5, A[i] ≤ 1e9, 0 ≤ l < r ≤ N.

Key Idea

- Precompute 1-based prefix sums P where P[0]=0 and P[i+1]=P[i]+A[i].
- Answer query in O(1) as P[r] - P[l].
- Total time O(N+Q), memory O(N).

Algorithm

- Build prefix sums:
    - P[0] = 0
    - For i = 0..N-1: P[i+1] = P[i] + A[i]
- For each query (l, r):
    - Output P[r] - P[l]

Pseudocode:

- Read N, Q
- Read array A of length N
- P = [0]
- For x in A: P.append(P[-1] + x)
- Repeat Q times:
    - Read l, r
    - Print P[r] - P[l]

Correctness

- For any l < r:
    - P[r] = A[0] + A[1] + ... + A[r-1]
    - P[l] = A[0] + A[1] + ... + A[l-1]
    - Subtracting telescopes to A[l] + ... + A[r-1], which is exactly the required range sum.

Complexity

- Preprocessing: O(N) additions.
- Each query: O(1).
- Total: O(N + Q) time, O(N) extra space.
- Maximum sum fits in 64-bit: 5e5 * 1e9 = 5e14 < 2^63.

Implementation Notes

- Input is large; use fast I/O (e.g., sys.stdin.buffer.read() in Python) and buffer outputs before printing.
- Use 64-bit integers where needed in compiled languages (long long in C++). In Python, int is arbitrary precision.
- Build P with size N+1; be careful with off-by-one when indexing.


- Small ranges: r = l+1 yields a single element.
- Prefix sums at boundaries: l = 0 correctly gives P[r] - P[0] = P[r].
- Zeros and large values: handled naturally; no overflow with 64-bit.

Why This Works Best

- The array is static (no updates), so offline prefix sums are optimal.
- More complex structures (Fenwick/segment trees) are unnecessary overhead here.

Extensions

- If updates were allowed, switch to a Fenwick tree or segment tree for O(log N) updates and queries.
- If multiple arrays or 2D ranges, generalize to 2D prefix sums.

Common Pitfalls

- Building P of length N instead of N+1.
- Mixing 0-based and 1-based thinking in queries.
- Using slow per-line I/O for 5e5 queries.
"""


def get_input():
    N, Q = map(int, input().split())
    a = list(map(int, input().split()))
    queries = [tuple(map(int, input().split())) for _ in range(Q)]
    return N, Q, a, queries


def prefix_sum(a):
    n = len(a)
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i + 1] = prefix_sum[i] + a[i]
    return prefix_sum


def solve():
    N, Q, a, queries = get_input()

    prefix_sum_arr = prefix_sum(a)
    for left, right in queries:
        print(prefix_sum_arr[right] - prefix_sum_arr[left])


if __name__ == "__main__":
    solve()
