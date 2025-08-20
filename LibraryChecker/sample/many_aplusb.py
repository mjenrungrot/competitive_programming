# Title: Many A + B
# URL: https://judge.yosupo.jp/problem/many_aplusb
# Category: Sample

"""
Title: Many A + B

Link: https://judge.yosupo.jp/problem/many_aplusb

Category: Sample


Statement:
There are $T$ cases.
For each case, you are given integers $A$ and $B$. Print $A + B$.


Constraints:
- $1 \leq T \leq 1000000$
- $0 \leq A, B \leq 1000000000000000000$


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
