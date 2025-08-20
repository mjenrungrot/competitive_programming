# Title: Set Xor-Min
# URL: https://judge.yosupo.jp/problem/set_xor_min
# Category: Data Structure

"""
Title: Set Xor-Min

Link: https://judge.yosupo.jp/problem/set_xor_min

Category: Data Structure


Statement:
Let $S$ be an empty integer set.
Process the following $Q$ queries :

 - `0 x` : insert $x$ into $S$ if it is not in $S$
 - `1 x` : remove $x$ from $S$ if it is in $S$
 - `2 x` : find $\min_{i \in S}(i \oplus x)$ where $\oplus$ denotes bitwise-xor.


Constraints:
- $1 \leq Q \leq 500000$
 - $0 \le x \lt 2^{30}$
 - $S$ is not empty when processing queries of type `2 x`.


Input:
```
$Q$
$\mathrm{Query}_0$
$\mathrm{Query}_1$
$\mathrm{Query}_2$
$\hspace{15pt} \vdots$
$\mathrm{Query}_{Q - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'set_xor_min'
    pass


if __name__ == "__main__":
    solve()