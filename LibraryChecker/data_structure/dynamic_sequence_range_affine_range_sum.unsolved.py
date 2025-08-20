# Title: Dynamic Sequence Range Affine Range Sum
# URL: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
# Category: Data Structure

"""
Title: Dynamic Sequence Range Affine Range Sum

Link: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum

Category: Data Structure


Statement:
You are given a sequence $a_0, a_1, ..., a_{N - 1}$, consisting of $N$ integers.

Process $Q$ queries of the following types in order :

 - `0 $i$ $x$` :  
    - If $i < |a|$, insert $x$ immediately before $a_i$  
    - If $i = |a|$, insert $x$ after $a_{|a| - 1}$  
 - `1 $i$` : Remove $a_i$ (remaining elements will be concatenated)  
 - `2 $l$ $r$` : Reverse $a_l, a_{l + 1}, a_{l + 2}, \dots, a_{r - 1}$  
 - `3 $l$ $r$ $b$ $c$` : For each $i = l, l + 1, l + 2, \dots, {r - 1}$, $a_i \gets b \times a_i + c$  
 - `4 $l$ $r$` : Print $\sum_{i = l}^{r - 1} a_i \bmod 998244353$


Constraints:
- $1 \le N, Q \le 500000$
 - $0 \le a_i \lt 998244353$
 - For the format `0 $i$ $x$` :  
    - $0 \le i \le (|a|$ at the time$)$
    - $0 \le x \lt 998244353$
 - For the format `1 $i$` :  
    - $0 \le i \lt (|a|$ at the time$)$
 - For the format `2 $l$ $r$` :  
    - $0 \le l \lt r \le (|a|$ at the time$)$
 - For the format `3 $l$ $r$ $b$ $c$` :  
    - $0 \le l \lt r \le (|a|$ at the time$)$
    - $0 \le b \lt 998244353$
    - $0 \le c \lt 998244353$
 - For the format `4 $l$ $r$` :  
    - $0 \le l \lt r \le (|a|$ at the time$)$


Input:
~~~
$N$ $Q$
$a_0$ $a_1$ ... $a_{N - 1}$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q - 1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'dynamic_sequence_range_affine_range_sum'
    pass


if __name__ == "__main__":
    solve()