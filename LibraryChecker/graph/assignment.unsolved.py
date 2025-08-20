# Title: Assignment Problem
# URL: https://judge.yosupo.jp/problem/assignment
# Category: Graph

"""
Title: Assignment Problem

Link: https://judge.yosupo.jp/problem/assignment

Category: Graph


Statement:
Given $N \times N$ matrix $a_{ij}$.
Calculate a permutation $p_i$ that minimize $\sum_{i = 0}^{N - 1} a_{ip_i}$.

If there is multiple solutions, print any of them.


Constraints:
- $1 \leq N \leq 500$
- $|a_{ij}| \leq 1000000000$


Input:
~~~
$N$
$a_{00}$ $a_{01}$ ... $a_{0,{N-1}}$
$a_{10}$ $a_{11}$ ... $a_{1,{N-1}}$
:
$a_{ {N-1}, 0 }$ $a_{ {N-1}, 1 }$ ... $a_{ {N-1}, {N-1} }$
~~~


Output:
~~~
$X$
$p_0$ $p_1$ ... $p_{N-1}$
~~~

$X = \sum_{i = 0}^{N - 1} a_{ip_i}$
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'assignment'
    pass


if __name__ == "__main__":
    solve()