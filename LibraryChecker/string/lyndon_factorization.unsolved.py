# Title: Lyndon Factorization
# URL: https://judge.yosupo.jp/problem/lyndon_factorization
# Category: String

"""
Title: Lyndon Factorization

Link: https://judge.yosupo.jp/problem/lyndon_factorization

Category: String


Statement:
For a string $X = X _ 0 X _ 1 X _ 2 \cdots $ , we denote its substring $X _ a X _ {a+1} \cdots X _ {b-1}$ as $X[a,b)$ .

Given a string $S = S _ 0 S _ 1 S _ 2 \cdots S _ {N-1}$ of length $N$ . Find an array of integers $0 = a _ 0 \lt a _ 1 \lt a _ 2 \lt \ldots \lt a _ k = N$ so that $S[a _ 0 , a _ 1) , S[a _ 1 , a _ 2) , \ldots , S[a _ {k-1} , a _ k)$ is the Lyndon Factorization of $S$ .


Constraints:
- $1 \leq N \leq 500000$
- Each character of $S$ is a lowercase English letter.


Input:
~~~
$S$
~~~


Output:
~~~
$a _ 0$ $a _ 1$ $a _ 2$ $\cdots$ $a _ k$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'lyndon_factorization'
    pass


if __name__ == "__main__":
    solve()