# Title: Wildcard Pattern Matching
# URL: https://judge.yosupo.jp/problem/wildcard_pattern_matching
# Category: String

"""
Title: Wildcard Pattern Matching

Link: https://judge.yosupo.jp/problem/wildcard_pattern_matching

Category: String


Statement:
Given strings $S$ and $T$ consisting of lowercase English letters and asterisks (`*`).

We say that strings $S'$ and $T'$ are matched if $|S'|=|T'|$ and they satisfy one of:

* $S'_i$ = $T'_i$
* $S'_i$ = `*`
* $T'_i$ = `*`

for each $0\leq i<|S'|$.

For each $0\leq i\leq|S|-|T|$, find if $S[i,i+|T|)$ and $T$ are matched.


Constraints:
- $1 \leq |T| \leq |S| \leq 524288$
- Each character of $S$ and $T$ is lowercase English letters or asterisks.


Input:
```
$S,T$
```


Output:
```
$W_0, W_1, \dots, W_{|S|-|T|}$
```
Here, $W_i$ is $1$ if $S[i,i+|T|)$ and $T$ are matched, $0$ otherwise.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'wildcard_pattern_matching'
    pass


if __name__ == "__main__":
    solve()