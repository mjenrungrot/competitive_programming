# Title: Find Linear Recurrence
# URL: https://judge.yosupo.jp/problem/find_linear_recurrence
# Category: Other

"""
Title: Find Linear Recurrence

Link: https://judge.yosupo.jp/problem/find_linear_recurrence

Category: Other


Statement:
You are given a sequence of integers $a_0, \ldots, a_{N-1}$.

Find a sequence of integers $c_1, \ldots, c_d$ of the minimum length $d \ge 0$ such that
$0 \le c_j < 998244353$ for $1 \le j \le d$ and
$$a_i \equiv \sum_{j=1}^d c_j a_{i-j} \pmod{998244353} \quad \text{for} \quad d \le i < N.$$


Constraints:
- $0 \le N \le 10000$
- $0 \le a_i < 998244353$


Input:
~~~
$N$
$a_0$ $\ldots$ $a_{N-1}$
~~~


Output:
~~~
$d$
$c_1$ $\ldots$ $c_d$
~~~

If there are multiple answers minimizing $d$, output any of them.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'find_linear_recurrence'
    pass


if __name__ == "__main__":
    solve()