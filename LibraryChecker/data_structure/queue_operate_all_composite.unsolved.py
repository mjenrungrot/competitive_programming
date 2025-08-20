# Title: Queue Operate All Composite
# URL: https://judge.yosupo.jp/problem/queue_operate_all_composite
# Category: Data Structure

"""
Title: Queue Operate All Composite

Link: https://judge.yosupo.jp/problem/queue_operate_all_composite

Category: Data Structure


Statement:
There is an initially empty sequence of linear functions $f = ()$. Process $Q$ queries.

- `0 $a$ $b$`: Add a linear function $\lambda x. ax + b$ to the end of the sequence $f$.
- `1`: Remove the linear function at the beginning of the sequence $f$.
- `2 $x$`: Let $f = (f_{l}, \dots, f_{r - 1})$, output $f _ {r - 1}(f _ {r - 2}(\dots (f _ l(x)) \dots)) \bmod 998244353$. Output $x$ if $f = ()$.


Constraints:
- $1 \leq Q \leq 500,000$
- $1 \leq a \lt 998244353$
- $0 \leq b, x \lt 998244353$
- The sequence $f$ is not empty when query $1$ comes.


Input:
~~~
$Q$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'queue_operate_all_composite'
    pass


if __name__ == "__main__":
    solve()