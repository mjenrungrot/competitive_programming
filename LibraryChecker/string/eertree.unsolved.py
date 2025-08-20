# Title: Eertree
# URL: https://judge.yosupo.jp/problem/eertree
# Category: String

"""
Title: Eertree

Link: https://judge.yosupo.jp/problem/eertree

Category: String


Statement:
A string $S$ consisting of lowercase English letters is given. Output the information of the eertree (also known as palindromic tree, or palindrome tree) of $S$ according to the following description.

- Let $P$ be the set of non-empty palindromic substrings of $S$, and let $n = |P|$.
- The eertree of $S$ consists of $2$ trees, which include $n$ vertices corresponding to the elements of $P$ and two special vertices called `ODD` and `EVEN`.
- Number the vertices of the eertree as follows:
    - The number of ODD is $-1$, and the number of EVEN is $0$.
    - Each other vertex $v$ corresponds to some $\mathrm{str}(v) \in P$. For $\mathrm{str}(v) = S_i \cdots S_{j-1}$, assign numbers $1, 2, \ldots, n$ to the vertices in ascending order of $j$, where $(i,j)$ is chosen such that $j$ is minimal.
    - For each vertex $v$ ($1 \leq v \leq n$), let $p_v$ be the number of its parent vertex. That is, $p_v$ is the number of the vertex corresponding to the palindrome obtained by removing the first and last characters of $\mathrm{str}(v)$. However, if $|\mathrm{str}(v)| = 2$, the parent is `EVEN` (number $0$), and if $|\mathrm{str}(v)| = 1$, the parent is `ODD` (number $-1$).
- For each vertex $v$ ($1 \leq v \leq n$), let $s_v$ be the destination of the suffix link from $v$. That is, $s_v$ is the number of the vertex corresponding to the largest non-empty palindromic suffix of $\mathrm{str}(v)$ that is shorter than $\mathrm{str}(v)$. If no such palindromic suffix exists, the suffix link destination is defined as `EVEN` (number $0$).

Output $n$ and $p_v, s_v$ for each $v$ ($1 \leq v \leq n$).

Additionally, for each $i = 1, 2, \ldots, |S|$, output the number of the vertex corresponding to the largest palindromic suffix of the prefix $S_0 \cdots S_{i-1}$ of length $i$.


Constraints:
- $1 \leq |S| \leq 1000000$
- Each character of $S$ is a lowercase English letter.


Input:
```
$S$
```


Output:
```
$n$
$p_1$ $s_1$
$\vdots$
$p_n$ $s_n$
$v_1$ $\ldots$ $v_{|S|}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'eertree'
    pass


if __name__ == "__main__":
    solve()