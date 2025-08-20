# Title: Bitwise And Convolution
# URL: https://judge.yosupo.jp/problem/bitwise_and_convolution
# Category: Convolution

"""
Title: Bitwise And Convolution

Link: https://judge.yosupo.jp/problem/bitwise_and_convolution

Category: Convolution


Statement:
Given size $2^N$ integer sequences $a_0, a_1, \dots, a_{2^N - 1}$ and $b_0, b_1, \dots, b_{2^N - 1}$. Calculate an integer sequence $c_0, c_1, \dots, c_{2^N - 1}$ as follows and print it $\bmod 998244353$.

$c_k = \sum_{i, j, i \And j = k} a_i b_j$

We note that $i \And j$ means bitwise-AND.


Constraints:
- $0 \leq N \leq 20$
- $0 \leq a_i < 998244353$
- $0 \leq b_i < 998244353$


Input:
```
$N$
$a_0$ $a_1$ ... $a_{2^N - 1}$
$b_0$ $b_1$ ... $b_{2^N - 1}$
```


Output:
```
$c_0$ $c_1$ ... $c_{2^N - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'bitwise_and_convolution'
    pass


if __name__ == "__main__":
    solve()