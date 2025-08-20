# Title: Pow of Formal Power Series (Sparse)
# URL: https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse
# Category: Polynomial

"""
Title: Pow of Formal Power Series (Sparse)

Link: https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse

Category: Polynomial


Statement:
You are given a formal power series $f(x) = \sum_{i=0}^{N-1} a_i x^i \in \mathbb{F}\_{998244353}[[x]]$ and a non-negative integer $M$. 
Only $K$ coefficients of $f$ are non-zero, and only such coefficients $a_{i_k}$ are given from input. 

Calculate the first $N$ terms of $(f(x))^M = \sum_{i=0}^{\infty} b_i x^i$.


Constraints:
- $1 \leq N \leq 1000000$
- $0 \leq K \leq 10$
- $0 \leq M \leq 1000000000000000000$
- $0 \leq i_0 < \cdots < i_{K-1} \leq N - 1$
- $1 \leq a_{i_k} < 998244353$


Input:
```
$N$ $K$ $M$
$i_0$ $a_{i_0}$
$\vdots$
$i_{K-1}$ $a_{i_{K-1}}$
```


Output:
```
$b_0$ $b_1$ $\cdots$ $b_{N - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'pow_of_formal_power_series_sparse'
    pass


if __name__ == "__main__":
    solve()