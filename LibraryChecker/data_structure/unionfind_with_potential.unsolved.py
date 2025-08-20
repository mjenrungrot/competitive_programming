# Title: Unionfind with Potential
# URL: https://judge.yosupo.jp/problem/unionfind_with_potential
# Category: Data Structure

"""
Title: Unionfind with Potential

Link: https://judge.yosupo.jp/problem/unionfind_with_potential

Category: Data Structure


Statement:
There is an unknown sequence of integers $(a_0, \ldots, a_{N - 1})$, process $Q$ queries.

- `$t_i$ = 0 $u_i$ $v_i$ $x_i$`: You are provided with information that $a_u \equiv a_v + x \pmod{998244353}$. This information is valid if it does not contradict any previously given valid information. If this information is valid, output $1$; otherwise, output $0$.

- `$t_i$ = 1 $u_i$ $v_i$`: Based on the valid information provided so far, output the value of $a_u - a_v \bmod 998244353$ if it can be determined; otherwise, output $-1$.


Constraints:
- $1 \leq N \leq 200000$
- $1 \leq Q \leq 200000$
- $0 \leq u_i, v_i \lt N$
- $0 \leq x_i \lt 998244353$


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
    # TODO: implement solution for 'unionfind_with_potential'
    pass


if __name__ == "__main__":
    solve()