# Title: Multiplication of Hex Big Integers
# URL: https://judge.yosupo.jp/problem/multiplication_of_hex_big_integers
# Category: Big Integer

"""
Title: Multiplication of Hex Big Integers

Link: https://judge.yosupo.jp/problem/multiplication_of_hex_big_integers

Category: Big Integer


Statement:
This problem has $T$ cases.  
Given hexadecimal integers $A$ and $B$, print hexadecimal integer $AB$.


Constraints:
- $1 \leq T \leq 160000$
- $0 \leq |A|, |B| < 16^{1600000}$
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
$AB$
 $\vdots$
$AB$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'multiplication_of_hex_big_integers'
    pass


if __name__ == "__main__":
    solve()