# Title: Static Convex Hull
# URL: https://judge.yosupo.jp/problem/static_convex_hull
# Category: Geometry

"""
Title: Static Convex Hull

Link: https://judge.yosupo.jp/problem/static_convex_hull

Category: Geometry


Statement:
This problem has $T$ cases.

Given $N$ 2D points $(x _ i , y _ i)$ ($0\leq i\leq N - 1$), let $P$ be the convex hull of them. Output the coordinates of the vertices of $P$ in counterclockwise order.

For a more detailed definition, please see the following note.

Note:

- For a (multi-)set of 2D points $S$, denote the convex hull of $S$ as $\mathrm{conv}(S)$.
- Define $P$ as $P=\mathrm{conv}(\lbrace (x _ i, y _ i) \mid 0\leq i\leq N - 1\rbrace)$.
- We can prove that there exists the minimum set $S'$ satisfying $\mathrm{conv}(S')=P$. The vertices of $P$ are defined as the elements of $S'$.
- When $|S'|\leq 2$, output the points of $S'$ in any order. When $|S'|\geq 3$, we can prove that $P$ is a convex polygon and $S'$ are its vertices, and we can define its counterclockwise order. We can rotate the order, and any of them is accepted if it is counterclockwise.
- According to the above definitions, you should not output a point of $S$ on an edge of $P$ if it is not a vertex.
- The input may contain multiple points with the same coordinates, but your output should not contain multiple points with the same coordinates.


Constraints:
- $1\leq T\leq 10^5$
- $0 \leq N \leq 500000$
- $|x_i|, |y_i| \leq 1000000000$
- $x_i, y_i$ are integers.
- The sum of $N$ over all test cases does not exceed $500000$


Input:
```
$T$
$N$
$x_0$ $y_0$
$x_1$ $y_1$
:
$x_{N - 1}$ $y_{N - 1}$
$N$
$x_0$ $y_0$
$x_1$ $y_1$
:
$x_{N - 1}$ $y_{N - 1}$
$\vdots$
```


Output:
For each testcase, print the coordinates in the following format.
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'static_convex_hull'
    pass


if __name__ == "__main__":
    solve()