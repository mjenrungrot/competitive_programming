# Title: Stirling Number of the Second Kind (Fixed K)
# URL: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k
# Category: Enumerative Combinatorics

"""
Title: Stirling Number of the Second Kind (Fixed K)

Link: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k

Category: Enumerative Combinatorics


Statement:
The Stirling numbers of the second kind $S(n, k)$ are defined as the coefficients in the identity
$$x^n = \sum_{k=0}^n S(n, k) x (x - 1) \cdots (x - (k - 1)).$$

You are given two integers $N,K$.
Calculate $S(n, K) \bmod 998244353$ for $K \le n \le N$.


Constraints:
- $0 \le K \le N \le 500000$


Input:
~~~
$N$ $K$
~~~


Output:
~~~
$S(K, K)$ $\cdots$ $S(N, K)$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'stirling_number_of_the_second_kind_fixed_k'
    pass


if __name__ == "__main__":
    solve()