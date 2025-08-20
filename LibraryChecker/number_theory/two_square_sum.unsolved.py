# Title: Represent A Number As Two Square Sum
# URL: https://judge.yosupo.jp/problem/two_square_sum
# Category: Number Theory

"""
Title: Represent A Number As Two Square Sum

Link: https://judge.yosupo.jp/problem/two_square_sum

Category: Number Theory


Statement:
Given $Q$ cases. 

For each case, you are given an integer $N_i$. Find all pairs of non-negative integers (a,b) statisfying $N_i=a^2+b^2$.


Constraints:
- $1 \leq Q \leq 100$
- $0 \leq N_i \leq 1000000000000000000$


Input:
```
$Q$
$N_0$
$N_1$
$\vdots$
$N_{Q - 1}$
```


Output:
For each test case, let $n$ be the number of pairs $(a,b)$ that satisfy the condition. Output a total of $n+1$ lines in the following format. The output order can be arbitrary.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'two_square_sum'
    pass


if __name__ == "__main__":
    solve()