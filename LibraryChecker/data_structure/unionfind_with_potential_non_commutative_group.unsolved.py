# Title: Unionfind with Potential (Non-Commutative Group)
# URL: https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
# Category: Data Structure

"""
Title: Unionfind with Potential (Non-Commutative Group)

Link: https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group

Category: Data Structure


Statement:
There is an unknown sequence of $2 \times 2$ invertible matrices with integer components $(a_0, \ldots, a_{N - 1})$, process $Q$ queries.

- `$t_i$ = 0 $u_i$ $v_i$ $x_{0, 0}$ $x_{0, 1}$ $x_{1, 0}$ $x_{1, 1}$`: You are provided with information that $a_u \equiv a_v x \pmod{998244353}$, where $x$ is a $2 \times 2$ matrix with elements $x_{0, 0}, x_{0, 1}, x_{1, 0}, x_{1, 1}$. This information is valid if it does not contradict any previously given valid information. If this information is valid, output $1$; otherwise, output $0$.
- `$t_i$ = 1 $u_i$ $v_i$`: Based on the valid information provided so far, output the value of $a_v^{-1}a_u \bmod 998244353$ if it can be determined; otherwise, output $-1$.


Constraints:
- $1 \leq N \leq 200000$
- $1 \leq Q \leq 200000$
- $0 \leq u_i, v_i \lt N$
- $0 \leq x_{0, 0}, x_{0, 1}, x_{1, 0}, x_{1, 1} < 998244353$
- $x_{0, 0}x_{1, 1} - x_{0, 1}x_{1, 0} \equiv 1 \pmod {998244353}$


Input:
~~~
$N$ $Q$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'unionfind_with_potential_non_commutative_group'
    pass


if __name__ == "__main__":
    solve()