# Title: Division of Polynomials
# URL: https://judge.yosupo.jp/problem/division_of_polynomials
# Category: Polynomial

"""
Title: Division of Polynomials

Link: https://judge.yosupo.jp/problem/division_of_polynomials

Category: Polynomial


Statement:
You are given polynomials $f(x) = \sum _ {i = 0} ^ {N - 1} f _ i x^i \in \mathbb{F} _ {998244353}[x]$ and $g(x)=\sum _ {i=0}^{M-1}g_ix^i\in \mathbb{F}_{998244353}[x]$. Calculate polynomials $q(x)$ and $r(x)$ such that 

- $f(x) = q(x)g(x) + r(x)$ and 
- $\deg(r) \lt \deg(g)$.


Constraints:
- $1 \leq N \leq 500000$
- $1 \leq M \leq 500000$
- $0 \leq f_i < 998244353$
- $0 \leq g_i < 998244353$
- $f_{N-1} \neq 0$
- $g_{M-1} \neq 0$


Input:
```
$N\ M$
$f_0\ f_1\ \ldots\ f_{N - 1}$
$g_0\ g_1\ \ldots\ g_{M - 1}$
```


Output:
Print $u=\deg(q)+1$ and $v=\deg(r)+1$ in the first line. Let $u = 0$ instead if $q(x) = 0$. (The same is true for $r(x)$.)

Print the coefficients of $q(x)$ in the second line and $r(x)$ in the third line.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'division_of_polynomials'
    pass


if __name__ == "__main__":
    solve()