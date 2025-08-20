# Title: Enumerate Primes
# URL: https://judge.yosupo.jp/problem/enumerate_primes
# Category: Number Theory

"""
Title: Enumerate Primes

Link: https://judge.yosupo.jp/problem/enumerate_primes

Category: Number Theory


Statement:
Let the prime numbers be $p_0 < p_1 < p_2 < \cdots$ (i.e. $p_0 = 2$, $p_1 = 3$, $p_2 = 5$, and so on).

You are given integers $N$, $A$ and $B$.
Find $\pi(N)$ (the number of primes no greater than $N$),
and print $p_{Ai+B}$ for nonnegative integers $i$ with $p_{Ai+B} \le N$.


Constraints:
- $1 \le N \le 500000000$
- $0 \le B < A \le N$
- $0 \le X \le 1000000$ where $X = \\#\lbrace i \in \mathbb{Z}\_{\ge 0} \mid p_{Ai+B} \le N \rbrace$


Input:
~~~
$N$ $A$ $B$
~~~


Output:
~~~
$\pi(N)$ $X$
$p_{B}$ $p_{A+B}$ $\cdots$ $p_{A(X-1)+B}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'enumerate_primes'
    pass


if __name__ == "__main__":
    solve()