# Title: Intersection of $\mathbb{F}_{2}$ vector spaces
# URL: https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces
# Category: Linear Algebra

"""
Title: Intersection of $\mathbb{F}_{2}$ vector spaces

Link: https://judge.yosupo.jp/problem/intersection_of_f2_vector_spaces

Category: Linear Algebra


Statement:
Find a basis of the intersection of two $\mathbb{F} _ 2$-vector spaces $X = \langle u_0, \ldots, u_{n-1}\rangle, Y = \langle v_0, \ldots, v_{m-1}\rangle$. Specifically, find a set of vectors $B = \lbrace w_0, \ldots, w_{k-1} \rbrace$ that:
- is linearly independent (for any subset $S = \lbrace s_0, \ldots, s_{l-1}\rbrace\subseteq B$, $s_0 \oplus \cdots \oplus s_{l-1} = 0$ implies $S = \emptyset$.)
- spans $X \cap Y$ (for any $a \in X \cap Y$, there exists a subset $S = \lbrace s_0, \ldots, s_{l-1}\rbrace \subseteq B$ such that $s_0 \oplus \cdots \oplus s_{l-1} = a$ holds. Besides, $B \subseteq X \cap Y$ holds.)

Each test consists of $T$ cases.


Constraints:
- $u_0, \ldots, u_{n-1}$ are linearly independent with respect to xor.
- $v_0, \ldots, v_{m-1}$ are linearly independent with respect to xor.


Input:
```
$T$
$n$ $u_0$ $u_1$ $\cdots$ $u_{n - 1}$
$m$ $v_0$ $v_1$ $\cdots$ $v_{m - 1}$
$\vdots$
$n$ $u_0$ $u_1$ $\cdots$ $u_{n - 1}$
$m$ $v_0$ $v_1$ $\cdots$ $v_{m - 1}$
```


Output:
```
$k$ $w_0$ $w_1$ $\cdots$ $w_{k - 1}$
$\vdots$
$k$ $w_0$ $w_1$ $\cdots$ $w_{k - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'intersection_of_f2_vector_spaces'
    pass


if __name__ == "__main__":
    solve()