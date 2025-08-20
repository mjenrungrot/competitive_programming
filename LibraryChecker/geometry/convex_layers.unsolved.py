# Title: Convex Layers
# URL: https://judge.yosupo.jp/problem/convex_layers
# Category: Geometry

"""
Title: Convex Layers

Link: https://judge.yosupo.jp/problem/convex_layers

Category: Geometry


Statement:
You are given $N$ distinct 2D-points $(x_0, y_0), (x_1, y_1), \dots, (x_{N - 1}, y_{N - 1})$. While there are points remaining, remove all points on the boundary of the convex hull of the remaining points.
For each point, determine which iteration it was removed in.

Note:

- Points may be collinear


Constraints:
- $1 \leq N \leq 200000$
- $0 \leq x_i, y_i \leq 1000000$
- $x_i, y_i$ are integers.


Input:
```
$N$
$x_0$ $y_0$
$x_1$ $y_1$
:
$x_{N - 1}$ $y_{N - 1}$
```


Output:
For each point, output which iteration it was removed in.

```
$l_0$
$l_1$
:
$l_{N - 1}$
```

$l_i$ represents the iteration the $i$th point was removed.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'convex_layers'
    pass


if __name__ == "__main__":
    solve()