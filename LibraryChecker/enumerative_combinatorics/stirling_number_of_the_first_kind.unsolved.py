# Title: Stirling Number of the First Kind
# URL: https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind
# Category: Enumerative Combinatorics

"""
Title: Stirling Number of the First Kind

Link: https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind

Category: Enumerative Combinatorics


Statement:
The signed Stirling numbers of the first kind $s(n, k)$ are defined as the coefficients in the identity
$$x (x - 1) \cdots (x - (n - 1)) = \sum_{k=0}^n s(n, k) x^k.$$

You are given an integer $N$.
Calculate $s(N, k) \bmod 998244353$ for $0 \le k \le N$.


Constraints:
- $0 \le N \le 500000$


Input:
~~~
$N$
~~~


Output:
~~~
$s(N, 0)$ $\cdots$ $s(N, N)$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'stirling_number_of_the_first_kind'
    pass


if __name__ == "__main__":
    solve()