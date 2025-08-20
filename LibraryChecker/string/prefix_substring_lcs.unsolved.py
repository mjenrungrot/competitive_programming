# Title: Prefix-Substring LCS
# URL: https://judge.yosupo.jp/problem/prefix_substring_lcs
# Category: String

"""
Title: Prefix-Substring LCS

Link: https://judge.yosupo.jp/problem/prefix_substring_lcs

Category: String


Statement:
You are given a string $S$ of length $M$ and a string $T$ of length $N$.
Process the following $Q$ queries in order:

- `$a$ $b$ $c$`: Print the length of the longest common subsequence of $(S_0, S_1, \dots, S_{a-1})$ and $(T_b, T_{b+1}, \dots, T_{c-1})$.


Constraints:
- $1 \leq M \leq 1000$
- $1 \leq N \leq 1000$
- $1 \leq Q \leq 500000$
- $0 \leq a_i \leq M$
- $0 \leq b_i \leq c_i \leq N$
- Each character of $S$ and $T$ is lowercase English letters.


Input:
```
$Q$
$S$
$T$
$a_0$ $b_0$ $c_0$
$a_1$ $b_1$ $c_1$
$\vdots$
$a_{Q-1}$ $b_{Q-1}$ $c_{Q-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'prefix_substring_lcs'
    pass


if __name__ == "__main__":
    solve()