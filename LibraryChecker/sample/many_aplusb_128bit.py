# Title: Many A + B (128 bit)
# URL: https://judge.yosupo.jp/problem/many_aplusb_128bit
# Category: Sample

"""
Title: Many A + B (128 bit)

Link: https://judge.yosupo.jp/problem/many_aplusb_128bit

Category: Sample


Statement:
There are $T$ cases.
For each case, you are given integers $A$ and $B$. Print $A + B$.


Constraints:
- $1 \leq T \leq 500000$
- $-10^{37} \leq A, B \leq 10^{37}$


Input:
```
$T$
$A$ $B$
 $\vdots$
$A$ $B$
```


Output:
```
$A + B$
 $\vdots$
$A + B$
```
"""


def solve():
    T = int(input())
    for _ in range(T):
        A, B = map(int, input().split())
        print(A + B)


if __name__ == "__main__":
    solve()
