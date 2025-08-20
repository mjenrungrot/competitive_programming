# Title: Run Enumerate
# URL: https://judge.yosupo.jp/problem/runenumerate
# Category: String

"""
Title: Run Enumerate

Link: https://judge.yosupo.jp/problem/runenumerate

Category: String


Statement:
Given a length $N$ string $S$. Please enumerate the runs of $S$. In other words, please enumerate tuples $(t, l, r)$ that satisfy the following conditions.

- The minimum period of the $S[l..r-1]$ is $t$, and $r - l \geq 2t$ is satisfied.
- $l$ and $r$ are maximal. In other words, $(t, l - 1, r)$ and $(t, l, r + 1)$ do not satisfy the above condition.


Constraints:
- $1 \leq N \leq 200,000$
- Each character of $S$ is lowercase English letters.


Input:
```
$S$
```


Output:
Here, $M$ is the number of runs, and runs are printed as $(t, l, r)$ tuples in lexicographical order.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'runenumerate'
    pass


if __name__ == "__main__":
    solve()