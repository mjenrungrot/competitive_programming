# Title: Min Plus Convolution (Concave and Arbitrary)
# URL: https://judge.yosupo.jp/problem/min_plus_convolution_concave_arbitrary
# Category: Convolution

"""
Title: Min Plus Convolution (Concave and Arbitrary)

Link: https://judge.yosupo.jp/problem/min_plus_convolution_concave_arbitrary

Category: Convolution


Statement:
Given integer sequences $a_0, a_1, ..., a_{N - 1}$ and $b_0, b_1, ..., b_{M - 1}$. Here, $a$ is concave. Calculate an integer sequence $c_0, c_1, ..., c_{(N - 1) + (M - 1)}$ defined as follows:

$$c_k = \min_{i+j=k} (a_i+b_j)$$


Constraints:
- $1 \leq N, M \leq 524288$
- $0 \leq a_i, b_i \leq 1000000000$
- $a$ is concave. i.e. $a_{i+1}-a_i\geq a_{i+2}-a_{i+1}$ holds for $0\leq i < N - 2$.


Input:
```
$N$ $M$
$a_0$ $a_1$ ... $a_{N-1}$
$b_0$ $b_1$ ... $b_{M-1}$
```


Output:
```
$c_0$ $c_1$ ... $c_{(N - 1) + (M - 1)}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'min_plus_convolution_concave_arbitrary'
    pass


if __name__ == "__main__":
    solve()