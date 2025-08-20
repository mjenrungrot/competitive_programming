# Title: Static Range Sum
# URL: https://judge.yosupo.jp/problem/static_range_sum
# Category: Data Structure

"""
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
