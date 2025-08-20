# Title: Kth term of Linearly Recurrent Sequence
# URL: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
# Category: Other

"""
Title: Kth term of Linearly Recurrent Sequence

Link: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence

Category: Other


Statement:
An integer sequence $(a_i)$ satisfies the following linear recurrence:

$$a_{i} \equiv \sum_{j=1}^{d} c_j a_{i - j} \pmod{998244353},\  i\geq d$$

Given $a_0,a_1,\ldots,a_{d-1}$, print $a_k \bmod 998244353$.


Constraints:
- $1 \leq d \leq 100000$
- $0 \leq k \leq 1000000000000000000$
- $0 \leq a_i \lt 998244353\ (0 \leq i \leq d-1)$
- $0 \leq c_i \lt 998244353\ (1 \leq i \leq d)$


Input:
```
$d$ $k$
$a_0$ $a_1$ $\ldots$ $a_{d-1}$
$c_1$ $c_2$ $\ldots$ $c_d$
```


Output:
```
$a_k$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'kth_term_of_linearly_recurrent_sequence'
    pass


if __name__ == "__main__":
    solve()