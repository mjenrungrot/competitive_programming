# Title: Multidimensional Convolution (Truncated)
# URL: https://judge.yosupo.jp/problem/multivariate_convolution
# Category: Convolution

"""
Title: Multidimensional Convolution (Truncated)

Link: https://judge.yosupo.jp/problem/multivariate_convolution

Category: Convolution


Statement:
The polynomials in $K$ variables over $\mathbb{Z}/998244353\mathbb{Z}$, $f(x_1, x_2, ..., x_K)$ and $g(x_1, x_2, ..., x_K)$ are given.
Calculate a product of $f$ and $g$ with $\bmod (x_1^{N_1}, x_2^{N_2}, ..., x_K^{N_K})$.


Constraints:
- $0 \leq K \leq 18$
- $\prod N_i \leq 262144$
- $2 \leq N_i$


Input:
$f$, $g$ is the integer array of length $\prod N_i$ consisting of integers between $0$ and $998244352$.
$i = i_1 + i_2 N_1 + ... + i_K N_1 N_2 ... N_{K-1}$-th element is corresponded to the coefficient of the $(x_1^{i_1}, x_2^{i_2}, ..., x_K^{i_K})$.


Output:
$fg$ is the integer array of length $\prod N_i$ consisting of integers between $0$ and $998244352$. 
As the same with input format, $i = i_1 + i_2 N_1 + ... + i_K N_1 N_2 ... N_{K-1}$-th element is corresponded to the coefficient of the $(x_1^{i_1}, x_2^{i_2}, ..., x_K^{i_K})$.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'multivariate_convolution'
    pass


if __name__ == "__main__":
    solve()