# Title: Hafnian of Matrix
# URL: https://judge.yosupo.jp/problem/hafnian_of_matrix
# Category: Linear Algebra

"""
Title: Hafnian of Matrix

Link: https://judge.yosupo.jp/problem/hafnian_of_matrix

Category: Linear Algebra


Statement:
Given $N \times N$ zero diagonal symmetric matrix $A = (a_{i,j})$. Print the hafnian of $A$ modulo $998244353$.


Constraints:
- $2 \le N \le 38$
- $N \bmod 2 = 0$
- $0 \le a_{ij} \lt 998244353$
- $a_{i,i} = 0$
- $a_{i,j} = a_{j,i}$


Input:
```
$N$
$a_{0,0}$ $a_{0,1}$ $\ldots$ $a_{0,N-1}$
$a_{1,0}$ $a_{1,1}$ $\ldots$ $a_{1,N-1}$
$\vdots$
$a_{N-1,0}$ $a_{N-1,1}$ $\ldots$ $a_{N-1,N-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'hafnian_of_matrix'
    pass


if __name__ == "__main__":
    solve()