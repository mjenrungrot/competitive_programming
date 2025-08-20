# Title: A + B
# URL: https://judge.yosupo.jp/problem/aplusb
# Category: Sample

"""
Title: A + B

Link: https://judge.yosupo.jp/problem/aplusb

Category: Sample


Statement:
You are given integers $A$ and $B$. Print $A + B$.


Constraints:
- $0 \leq A, B \leq 1000000000$


Input:
```
$A$ $B$
```


Output:
```
$A + B$
```
"""

import sys


def solve():
    data = sys.stdin.buffer.read().split()
    A, B = int(data[0]), int(data[1])
    print(A + B)


if __name__ == "__main__":
    solve()
