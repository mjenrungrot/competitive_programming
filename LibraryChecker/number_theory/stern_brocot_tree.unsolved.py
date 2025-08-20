# Title: Stern–Brocot Tree
# URL: https://judge.yosupo.jp/problem/stern_brocot_tree
# Category: Number Theory

"""
Title: Stern–Brocot Tree

Link: https://judge.yosupo.jp/problem/stern_brocot_tree

Category: Number Theory


Statement:
The following are true for all problems.

- Positive rational number in input/output is represented by irreducible fraction $a/b$.
- Positive rational numbers are identified with nodes in Stern–Brocot Tree (SBT). 
- If a node $a/b$ of SBT appears in **input**, $a, b$ satisfies following constraints: $1\leq a \leq 1000000000$ , $1\leq b \leq 1000000000$ , $a$ and $b$ are coprime.


Constraints:
- $c_i\neq c_{i+1}$
- $1\leq n_i\leq 10^9$
- It is guaranteed that the answer satisfies $1\leq a\leq 10^9$ and $1\leq b\leq 10^9$.


Input:
The path from $1/1$ to $a/b$ is given in the format of ENCODE_PATH. 
Print $a, b$.


Output:
The path from $1/1$ to $a/b$ is given in the format of ENCODE_PATH. 
Print $a, b$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'stern_brocot_tree'
    pass


if __name__ == "__main__":
    solve()