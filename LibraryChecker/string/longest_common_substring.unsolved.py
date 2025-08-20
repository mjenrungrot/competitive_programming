# Title: Longest Common Substring
# URL: https://judge.yosupo.jp/problem/longest_common_substring
# Category: String

"""
Title: Longest Common Substring

Link: https://judge.yosupo.jp/problem/longest_common_substring

Category: String


Statement:
Strings $S$ and $T$ is given. Find a longest common substring of $S$ and $T$.


Constraints:
- $1 \leq |S|, |T| \leq 500000$
- Each character of $S$, $T$ is lowercase English letters.


Input:
```
$S$
$T$
```


Output:
Output $a,b,c,d$ when a longest common substring can be taken as $(S_a, \ldots, S_{b-1})$ and $(T_c, \ldots, T_{d-1})$.

```
$a$ $b$ $c$ $d$
```

Here, $S_i$ represents the $(1+i)$-th character of $S$, and $T_j$ represents the $(j+1)$-th character of $T$.

If the longest common substring is empty, print: 

```
$0$ $0$ $0$ $0$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'longest_common_substring'
    pass


if __name__ == "__main__":
    solve()