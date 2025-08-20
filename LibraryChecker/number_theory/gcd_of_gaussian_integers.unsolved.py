# Title: Gcd of Gaussian Integers
# URL: https://judge.yosupo.jp/problem/gcd_of_gaussian_integers
# Category: Number Theory

"""
Title: Gcd of Gaussian Integers

Link: https://judge.yosupo.jp/problem/gcd_of_gaussian_integers

Category: Number Theory


Statement:
In this problem, $i$ represents the imaginary unit.

Given Gaussian integers $a_1+b_1i$ and $a_2+b_2i$, find one of their greatest common divisors.

Please refer to the following definitions for Gaussian integers and their greatest common divisors:

- An element of $\mathbb{Z}[i] = \lbrace a+bi\mid a,b\in \mathbb{Z}\rbrace$ is called a Gaussian integer.

- For $x, y \in \mathbb{Z}[i]$, we define $x\mid y$ if there exists a $z$ in $\mathbb{Z}[i]$ such that $y = xz$.

- A Gaussian integer $g$ is a greatest common divisor of $x, y\in \mathbb{Z}[i]$ if, for any $z$ in $\mathbb{Z}[i]$, the condition $z\mid g$ is equivalent to $z\mid x$ and $z\mid y$. Such a $g$ is uniquely determined except for multiples of $\pm 1$ and $\pm i$.

You have $T$ test cases to solve.


Constraints:
- $1 \leq T \leq 100000$
- $-1000000000 \leq a_1, b_1, a_2, b_2 \leq 1000000000$


Input:
```
$T$
$a_1$ $b_1$ $a_2$ $b_2$
$\vdots$
$a_1$ $b_1$ $a_2$ $b_2$
```


Output:
When $a+bi$ is a greatest common divisor of $a_1+b_1i$ and $a_2+b_2i$, output $a$ and $b$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'gcd_of_gaussian_integers'
    pass


if __name__ == "__main__":
    solve()