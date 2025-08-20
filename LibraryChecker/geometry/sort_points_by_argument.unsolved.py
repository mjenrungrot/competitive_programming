# Title: Sort Points by Argument
# URL: https://judge.yosupo.jp/problem/sort_points_by_argument
# Category: Geometry

"""
Title: Sort Points by Argument

Link: https://judge.yosupo.jp/problem/sort_points_by_argument

Category: Geometry


Statement:
Given $N$ 2D-points $(x_0, y_0), (x_1, y_1), \dots, (x_{N - 1}, y_{N - 1})$, please sort them by $\mathrm{atan2}(x, y)$. 
In other words, sort the points in counterclockwise order that starts from the half line $x \le 0, y = 0$.

Note:

- $\mathrm{atan2}(x < 0, y = 0) = \pi$.
- $\mathrm{atan2}(0, 0) = 0$.
- Points with the same argument can be ordered arbitrarily.
- The precision of the 64bit floating-point type(C++: double) may not be enough. Please use an integer-type or the 80bit floating-point type(C++: long double).


Constraints:
- $1 \leq N \leq 200000$
- $|x_i|, |y_i| \leq 1000000000$
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
```
$x_0$ $y_0$
$x_1$ $y_1$
:
$x_{N - 1}$ $y_{N - 1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'sort_points_by_argument'
    pass


if __name__ == "__main__":
    solve()