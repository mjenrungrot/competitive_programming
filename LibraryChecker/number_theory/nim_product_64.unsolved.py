# Title: Nim Product ($\mathbb{F}_{2^{64}}$)
# URL: https://judge.yosupo.jp/problem/nim_product_64
# Category: Number Theory

"""
Title: Nim Product ($\mathbb{F}_{2^{64}}$)

Link: https://judge.yosupo.jp/problem/nim_product_64

Category: Number Theory


Statement:
There are $T$ test cases.

For each test case, you are given two nonnegative integers $A$ and $B$.
Calculate the nim product $A \otimes B$.

The nim sum and the nim product for nonnegative integers are defined recursively as follows:

- $a \oplus b = \operatorname{mex}(\lbrace a' \oplus b \mid a' < a \rbrace \cup \lbrace a \oplus b' \mid b' < b \rbrace)$
- $a \otimes b = \operatorname{mex}\lbrace (a' \otimes b) \oplus (a \otimes b') \oplus (a' \otimes b') \mid a' < a,\thinspace b' < b \rbrace$


Constraints:
- $1 \le T \le 1000000$
- $0 \le A < 2^{64}$
- $0 \le B < 2^{64}$


Input:
~~~
$T$
$A_0$ $B_0$
 $\vdots$
$A_{T-1}$ $B_{T-1}$
~~~


Output:
~~~
$\mathit{answer}_0$
 $\vdots$
$\mathit{answer}_{T-1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'nim_product_64'
    pass


if __name__ == "__main__":
    solve()