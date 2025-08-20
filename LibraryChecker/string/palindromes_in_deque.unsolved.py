# Title: Palindromes in Deque
# URL: https://judge.yosupo.jp/problem/palindromes_in_deque
# Category: String

"""
Title: Palindromes in Deque

Link: https://judge.yosupo.jp/problem/palindromes_in_deque

Category: String


Statement:
There is an initially empty string $s$. Process $Q$ queries.

- `0 $c$`: Add a character $c$ to the beginning of the string $s$.
- `1 $c$`: Add a character $c$ to the end of the string $s$.
- `2`: Remove the character at the beginning of the string $s$.
- `3`: Remove the character at the end of the string $s$.

After processing each query, output the following $3$ parameters in order.

* Number of distinct non-empty palindromic substring of $s$
* Length of the longest palindromic prefix of $s$
* Length of the longest palindromic suffix of $s$

If $s$ is a empty string, output `0 0 0` instead.


Constraints:
- $1 \leq Q \leq 500000$
- $c$ is a lowercase English letter.
- The string $s$ is not empty when query $2$ or query $3$ comes.


Input:
```
$Q$
$\textrm{Query}_0$
$\textrm{Query}_1$
$\vdots$
$\textrm{Query}_{Q - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'palindromes_in_deque'
    pass


if __name__ == "__main__":
    solve()