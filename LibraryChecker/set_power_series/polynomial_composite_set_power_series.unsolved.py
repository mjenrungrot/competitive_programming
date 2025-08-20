# Title: Polynomial Composite Set Power Series
# URL: https://judge.yosupo.jp/problem/polynomial_composite_set_power_series
# Category: Set Power Series

"""
Title: Polynomial Composite Set Power Series

Link: https://judge.yosupo.jp/problem/polynomial_composite_set_power_series

Category: Set Power Series


Statement:
Given a polynomial $\displaystyle f(x) = \sum _ {i = 0} ^ {M - 1} a _ i x ^ i \in \mathbb{F} _ {998244353} \lbrack x \rbrack$ and an $N$-variable polynomial $\displaystyle s(x _ 0, x _ 1, \dots, x _ {N - 1}) = \sum _ {i = 0} ^ {2 ^ N - 1} b _ i \prod _ {k = 0} ^ {N - 1} x _ k ^ {i _ k} \in \mathbb{F} _ {998244353} \lbrack x _ 0, x _ 1, \dots, x _ {N - 1} \rbrack$.
Here, $i_k$ represents the number in the $2 ^ k$'s place when $i$ is expressed in binary.
Print $c _ 0, c _ 1, \dots, c _ {2 ^ N - 1} ~ (0 \leq c _ i \lt 998244353)$ satisfying

$$f(s(x _ 0, x _ 1, \dots, x _ {N - 1})) \equiv \sum _ {i = 0} ^ {2 ^ N - 1} c _ i \prod _ {k = 0} ^ {N - 1} x _ k ^ {i _ k} \pmod{(x _ 0 ^ 2, x _ 1 ^ 2, \dots, x _ {N - 1} ^ 2)}$$

.


Constraints:
- $0 \leq M \leq 100000$
- $0 \leq N \leq 20$
- $0 \leq a_i, b_i \lt 998244353$


Input:
```
$M$ $N$
$a_0$ $a_1$ $\cdots$ $a_{M-1}$
$b_0$ $b_1$ $\cdots$ $b_{2^N-1}$
```


Output:
```
$c_0$ $c_1$ $\cdots$ $c_{2^N-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'polynomial_composite_set_power_series'
    pass


if __name__ == "__main__":
    solve()