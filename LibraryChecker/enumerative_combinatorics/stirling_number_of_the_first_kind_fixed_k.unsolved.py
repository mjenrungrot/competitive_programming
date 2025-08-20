# Title: Stirling Number of the First Kind (Fixed K)
# URL: https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k
# Category: Enumerative Combinatorics

"""
Title: Stirling Number of the First Kind (Fixed K)

Link: https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k

Category: Enumerative Combinatorics


Statement:
The signed Stirling numbers of the first kind $s(n, k)$ are defined as the coefficients in the identity
$$x (x - 1) \cdots (x - (n - 1)) = \sum_{k=0}^n s(n, k) x^k.$$

You are given two integers $N,K$.
Calculate $s(n, K) \bmod 998244353$ for $K \le n \le N$.


Constraints:
- $0 \le K \le N \le 500000$


Input:
~~~
$N$ $K$
~~~


Output:
~~~
$s(K, K)$ $\cdots$ $s(N, K)$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'stirling_number_of_the_first_kind_fixed_k'
    pass


if __name__ == "__main__":
    solve()