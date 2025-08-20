# Title: Multidimensional Convolution (Circular)
# URL: https://judge.yosupo.jp/problem/multivariate_convolution_cyclic
# Category: Convolution

"""
Title: Multidimensional Convolution (Circular)

Link: https://judge.yosupo.jp/problem/multivariate_convolution_cyclic

Category: Convolution


Statement:
A prime $p$, and polynomials in $K$ variables over $\mathbb{Z}/p\mathbb{Z}$, $f(x_1, x_2, ..., x_K)$ and $g(x_1, x_2, ..., x_K)$ are given.
Calculate a product of $f$ and $g$ with $\bmod (1-x_1^{N_1}, 1-x_2^{N_2}, ..., 1-x_K^{N_K})$.
Here, $N_i$ is a divisor of $p-1$.


Constraints:
- $2 \leq p \leq 1000000000$
- $p$ is a prime
- $0 \leq K \leq 18$
- $\prod N_i \leq 262144$
- $2 \leq N_i$
- $N_i$ is a divisor of $p-1$


Input:
$f$, $g$ is the integer array of length $\prod N_i$ consisting of integers between $0$ and $p-1$.
$i = i_1 + i_2 N_1 + ... + i_K N_1 N_2 ... N_{K-1}$-th element is corresponded to the coefficient of the $(x_1^{i_1}, x_2^{i_2}, ..., x_K^{i_K})$.


Output:
$fg$ is the integer array of length $\prod N_i$ consisting of integers between $0$ and $p-1$. 
As the same with input format, $i = i_1 + i_2 N_1 + ... + i_K N_1 N_2 ... N_{K-1}$-th element is corresponded to the coefficient of the $(x_1^{i_1}, x_2^{i_2}, ..., x_K^{i_K})$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'multivariate_convolution_cyclic'
    pass


if __name__ == "__main__":
    solve()