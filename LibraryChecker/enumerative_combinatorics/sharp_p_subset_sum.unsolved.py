# Title: $\#_p$ Subset Sum
# URL: https://judge.yosupo.jp/problem/sharp_p_subset_sum
# Category: Enumerative Combinatorics

"""
Title: $\#_p$ Subset Sum

Link: https://judge.yosupo.jp/problem/sharp_p_subset_sum

Category: Enumerative Combinatorics


Statement:
Given $N$ positive integers $s_0,s_1,\ldots,s_{N-1}$ and a positive integer $T$.

For each $t=1,2,...,T$, count the number of subset $I \subseteq \lbrace 0,1,...,N-1\rbrace$ s.t. $\sum_{i \in I} s_i=t$ and print it $\bmod 998244353$ (we denote it as $p_t$).


Constraints:
- $1 \leq N \leq 1000000$
- $1 \leq T \leq 500000$
- $1 \leq s_i \leq T$


Input:
```
$N$ $T$
$s_0$ $s_1$ ... $s_{N-1}$
```


Output:
```
$p_1$ $p_2$ ... $p_T$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'sharp_p_subset_sum'
    pass


if __name__ == "__main__":
    solve()