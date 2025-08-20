# Title: Static Rectangle Add Rectangle Sum
# URL: https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum
# Category: Data Structure

"""
Title: Static Rectangle Add Rectangle Sum

Link: https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum

Category: Data Structure


Statement:
You are given a $1000000000 \times 1000000000$ matrix $A = (A_{xy})$ ($0\leq x < 1000000000$, $0\leq y < 1000000000$). 
Initially, all entries $A_{xy}$ equal $0$. 

First, process following $N$ queries. 

- `$l$ $d$ $r$ $u$ $w$`: Add $w$ to all entries $A_{xy}$ satisfying $l\leq x < r$ and $d\leq y < u$. 

Then, process following $Q$ queries. 

- `$l$ $d$ $r$ $u$`: Calculate sum of entries $A_{xy}$ satisfying $l\leq x < r$ and $d\leq y < u$, and print it modulo $998244353$.


Constraints:
- $1 \leq N \leq 200000$
- $1 \leq Q \leq 200000$
- $0 \leq l_i < r_i \leq 1000000000$
- $0 \leq d_i < u_i \leq 1000000000$
- $0 \leq w_i < 998244353$


Input:
~~~
$N$ $Q$
$l_0$ $d_0$ $r_0$ $u_0$ $w_0$
$\vdots$
$l_{N-1}$ $d_{N-1}$ $r_{N-1}$ $u_{N-1}$ $w_{N-1}$
$l_0$ $d_0$ $r_0$ $u_0$
$\vdots$
$l_{Q-1}$ $d_{Q-1}$ $r_{Q-1}$ $u_{Q-1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'static_rectangle_add_rectangle_sum'
    pass


if __name__ == "__main__":
    solve()