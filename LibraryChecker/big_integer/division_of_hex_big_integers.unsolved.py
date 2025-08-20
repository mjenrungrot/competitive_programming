# Title: Division of Hex Big Integers
# URL: https://judge.yosupo.jp/problem/division_of_hex_big_integers
# Category: Big Integer

"""
Title: Division of Hex Big Integers

Link: https://judge.yosupo.jp/problem/division_of_hex_big_integers

Category: Big Integer


Statement:
This problem has $T$ cases.  
Given a hexadecimal non-negative integer $A$ and a hexadecimal positive integer $B$, print hexadecimal integers $q, r$ satisfying the following equation:


Constraints:
- $1 \leq T \leq 1600000$
- $0 \leq A < 16^{1600000}$
- $1 \leq B < 16^{1600000}$
- The sum of (the number of characters in $A$) $+$ (the number of characters in $B$) over all test cases does not exceed $3200002$.


Input:
```
$T$
$A$ $B$
 $\vdots$
$A$ $B$
```


Output:
```
$q$ $r$
 $\vdots$
$q$ $r$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'division_of_hex_big_integers'
    pass


if __name__ == "__main__":
    solve()