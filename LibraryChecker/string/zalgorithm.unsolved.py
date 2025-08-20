# Title: Z Algorithm
# URL: https://judge.yosupo.jp/problem/zalgorithm
# Category: String

"""
Title: Z Algorithm

Link: https://judge.yosupo.jp/problem/zalgorithm

Category: String


Statement:
Given a length $N$ string $S$. Calculate array $a_0, a_1, ..., a_{N - 1}$ as follows:

- $a_i$ is the LCP(longest common prefix) of $S$ and $S.substr(i)$.


Constraints:
- $1 \leq N \leq 500000$
- Each character of $S$ is lowercase English letters.


Input:
~~~
$S$
~~~


Output:
~~~
$a_0$ $a_1$ $a_2$ ... $a_{N-1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'zalgorithm'
    pass


if __name__ == "__main__":
    solve()