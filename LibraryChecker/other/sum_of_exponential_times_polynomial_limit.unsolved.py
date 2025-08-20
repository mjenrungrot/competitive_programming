# Title: $\sum_{i=0}^{\infty} r^i i^d$
# URL: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
# Category: Other

"""
Title: $\sum_{i=0}^{\infty} r^i i^d$

Link: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit

Category: Other


Statement:
Let $\widetilde{r}$ be a rational number such that $-1 < \widetilde{r} < 1$ and $\widetilde{r} \equiv r \pmod{998244353}$.
Given integers $r$ and $d$, calculate $\sum_{i=0}^{\infty} \widetilde{r}^i i^d$ modulo $998244353$.
The answer is well-defined under the constraints of this problem.
We define $0^0 = 1$.


Constraints:
- $0 \le r < 998244353$
- $r \ne 1$
- $0 \le d \le 10000000$


Input:
~~~
$r$ $d$
~~~


Output:
~~~
$\mathit{answer}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'sum_of_exponential_times_polynomial_limit'
    pass


if __name__ == "__main__":
    solve()