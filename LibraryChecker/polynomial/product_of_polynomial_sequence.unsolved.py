# Title: Product of Polynomial Sequence
# URL: https://judge.yosupo.jp/problem/product_of_polynomial_sequence
# Category: Polynomial

"""
Title: Product of Polynomial Sequence

Link: https://judge.yosupo.jp/problem/product_of_polynomial_sequence

Category: Polynomial


Statement:
$N$ polynomials $f_i(x) = \sum_{j=0}^{d_j} a_{i,j} x^{j} \in \mathbb{Z}[x]$ ($i=0,\ldots,N-1$) are given. 
Compute $f(x) = \prod_{i=0}^{N-1} f_i(x)$ modulo $998244353$.


Constraints:
- $0 \leq N \leq 500000$
- $0 \leq d_{i}$ and $\sum_{i=0}^{N-1} d_i \leq 500000$
- $0 \leq a_{i,j} < 998244353$
- $a_{i, d_i}\neq 0$


Input:
```
$N$
$d_0$ $a_{0,0}$ $\ldots$ $a_{0,d_0}$
$\vdots$
$d_{N-1}$ $a_{N-1,0}$ $\ldots$ $a_{N-1,d_{N-1}}$
```


Output:
```
$a_0$ $a_1$ ... $a_{D}$
```

Here $D = \sum_{i=0}^{N-1} d_i$ and $f(x) = \sum_{j=0}^{D} a_jx^j \pmod{998244353}$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'product_of_polynomial_sequence'
    pass


if __name__ == "__main__":
    solve()