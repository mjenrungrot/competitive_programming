# Title: Lcm Convolution
# URL: https://judge.yosupo.jp/problem/lcm_convolution
# Category: Convolution

"""
Title: Lcm Convolution

Link: https://judge.yosupo.jp/problem/lcm_convolution

Category: Convolution


Statement:
Given integer sequences $a_1, ..., a_{N}$ and $b_1, ..., b_{N}$. 
Calculate an integer sequence $c_1, ..., c_{N}$ as follows:

$$c_k = \sum_{\mathrm{lcm}(i,j)=k} a_ib_j \bmod 998244353$$


Constraints:
- $1 \leq N \leq 1000000$
- $0 \leq a_i, b_i < 998244353$


Input:
```
$N$
$a_1$ ... $a_{N}$
$b_1$ ... $b_{N}$
```


Output:
```
$c_1$ ... $c_{N}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'lcm_convolution'
    pass


if __name__ == "__main__":
    solve()