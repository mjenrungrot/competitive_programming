# Title: Enumerate Palindromes
# URL: https://judge.yosupo.jp/problem/enumerate_palindromes
# Category: String

"""
Title: Enumerate Palindromes

Link: https://judge.yosupo.jp/problem/enumerate_palindromes

Category: String


Statement:
You are given a string $S$ of length $N$.

There are $2N-1$ positions for the center of a palindromic substring of $S$: at the character or at the middle of two adjacent characters.

For the $i$-th of them ($0$-based), define $L_i$ as the length of the maximum palindrome centered there (or $L_i = 0$ if such a palindrome does not exist). Calculate the array $L_0,L_1,\ldots,L_{2N-2}$.


Constraints:
- $1 \leq N \leq 500000$
- Each character of $S$ is a lowercase English letter.


Input:
```
$S$
```


Output:
```
$L_0$ $L_1$ ... $L_{2N-2}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'enumerate_palindromes'
    pass


if __name__ == "__main__":
    solve()