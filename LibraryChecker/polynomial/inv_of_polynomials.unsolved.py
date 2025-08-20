# Title: Inv of Polynomials
# URL: https://judge.yosupo.jp/problem/inv_of_polynomials
# Category: Polynomial

"""
Title: Inv of Polynomials

Link: https://judge.yosupo.jp/problem/inv_of_polynomials

Category: Polynomial


Statement:
We consider polynomials over $\mathbb{F}_{998244353}$ in this problem.

Given polynomials $f(x)=\sum_{i=0}^{N-1} a_ix^i$ and $g(x)=\sum_{i=0}^{M-1}b_ix^i$.
Calculate a polynomial $h(x)=\sum_{i=0}^{T-1}c_ix^i$ s.t.

- $\deg(h) < \deg(g)$ and
- $f(x)h(x)\equiv1\pmod {g(x)}$

is satisfied.

We note that $\deg(0)=-\infty$ in this problem.
We can prove $h(x)$ is unique if it exists.
Print $-1$ if it doesn't exist.


Constraints:
- $1 \leq N \leq 50000$
- $1 \leq M \leq 50000$
- $0 \leq a_i < 998244353$
- $0 \leq b_i < 998244353$
- $a_{N-1} \neq 0$
- $b_{M-1} \neq 0$


Input:
```
$N$ $M$
$a_0$ $a_1$ $\ldots$ $a_{N - 1}$
$b_0$ $b_1$ $\ldots$ $b_{M - 1}$
```


Output:
If $h(x)$ doesn't exist, print $-1$.

If $h(x)$ exists, print $T$ ($c_{T-1} \neq 0$) in first line, or $T = 0$ when $h(x)=0$.
Print $c_0, c_1, \ldots, c_{T-1}$ in next line.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'inv_of_polynomials'
    pass


if __name__ == "__main__":
    solve()