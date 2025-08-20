# Title: Polynomial Root Finding (Mod 998244353)
# URL: https://judge.yosupo.jp/problem/polynomial_root_finding
# Category: Polynomial

"""
Title: Polynomial Root Finding (Mod 998244353)

Link: https://judge.yosupo.jp/problem/polynomial_root_finding

Category: Polynomial


Statement:
Given a polynomial $f(x) = \sum_{i=0}^Nf _ ix^i\in \mathbb{F} _ {998244353}[x]$ of degree $N$. 
Find all $a\in \mathbb{F} _ {998244353}$ satisfying $f(a)=0$.


Constraints:
- $0\leq N\leq 4000$
- $0\leq f_i < 998244353$
- $f_N\neq 0$


Input:
```
$N$
$f_0$ $\cdots$ $f_N$
```


Output:
Print all $a$ satisfying $f(a)=0$ in the following format.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'polynomial_root_finding'
    pass


if __name__ == "__main__":
    solve()