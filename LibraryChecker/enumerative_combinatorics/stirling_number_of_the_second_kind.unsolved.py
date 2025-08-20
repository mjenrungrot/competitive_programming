# Title: Stirling Number of the Second Kind
# URL: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
# Category: Enumerative Combinatorics

"""
Title: Stirling Number of the Second Kind

Link: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind

Category: Enumerative Combinatorics


Statement:
The Stirling numbers of the second kind $S(n, k)$ are defined as the coefficients in the identity
$$x^n = \sum_{k=0}^n S(n, k) x (x - 1) \cdots (x - (k - 1)).$$

You are given an integer $N$.
Calculate $S(N, k) \bmod 998244353$ for $0 \le k \le N$.


Constraints:
- $0 \le N \le 500000$


Input:
~~~
$N$
~~~


Output:
~~~
$S(N, 0)$ $\cdots$ $S(N, N)$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'stirling_number_of_the_second_kind'
    pass


if __name__ == "__main__":
    solve()