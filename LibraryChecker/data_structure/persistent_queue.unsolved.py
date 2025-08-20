# Title: Persistent Queue
# URL: https://judge.yosupo.jp/problem/persistent_queue
# Category: Data Structure

"""
Title: Persistent Queue

Link: https://judge.yosupo.jp/problem/persistent_queue

Category: Data Structure


Statement:
Let $S_{-1}$ be an empty sequence.
Process the following $Q$ queries.
The $i$-th query is given in the following form.

- `0 $t_i$ $x_i$`: Define $S_i$ as the sequence obtained by adding $x_i$ to the end of $S_{t_i}$.
- `1 $t_i$`: Define $S_i$ as the sequence obtained by deleting the front element of $S_{t_i}$. Print the deleted element.


Constraints:
- $1 \leq Q \leq 500000$
- $-1 \leq t_i < i$
- $0 \leq x_i \leq 1000000000$
- In query 1, $S_{t_i}$ is not empty.


Input:
~~~
$Q$
$\textrm{Query}_0$
$\textrm{Query}_1$
:
$\textrm{Query}_{Q-1}$
~~~
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'persistent_queue'
    pass


if __name__ == "__main__":
    solve()