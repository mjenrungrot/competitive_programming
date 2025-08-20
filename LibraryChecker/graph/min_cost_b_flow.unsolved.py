# Title: Minimum Cost b-flow
# URL: https://judge.yosupo.jp/problem/min_cost_b_flow
# Category: Graph

"""
Title: Minimum Cost b-flow

Link: https://judge.yosupo.jp/problem/min_cost_b_flow

Category: Graph


Statement:
You are given a directed graph with $n$ vertices and $m$ edges, amount of supply/demand associated with each vertex, and flow lower/upper bound associated with each edge.
The $v$-th vertex has $b_v$ amount of supply if $b_v$ was positive, and $-b_v$ amount of demand otherwise.
The $e$-th edge is directed from vertex $s_e$ to $t_e$ and has flow lower bound $l_e$, flow upper bound $u_e$, and cost per a unit of flow $c_e$.

Your task is to find and print the minimum cost $\mathbf{b}$-flow value $z$, the flow $\mathbf{f}$ and its dual $\mathbf{p}$ that achives the minimum, that is, $z$, $\mathbf{f} = \lbrace f_e\rbrace _ {e = 0 \dots m-1}$, and $\mathbf{p} = \lbrace p_v\rbrace _ {v = 0 \dots n-1}$ that satisfies following constraints;

- $z = \sum_{e} c_e f_e$
- $l_e \leq f_e \leq u_e$ (Capacity constraints)
- $\sum_{e \in \delta^+(v)} f_e - \sum_{e \in \delta^-(v)} f_e = b_v$ (Flow conservation constraints)
- $f_e \gt l_e \Rightarrow c_e + p_{s_e} - p_{t_e} \le 0$ (Complementary slackness conditions)
- $f_e \lt u_e \Rightarrow c_e + p_{s_e} - p_{t_e} \ge 0$ (Complementary slackness conditions)
- $|p_v| \le 1000000000000000$

where $\delta^+(v)$ is the set of edges leaving vertex $v$ and $\delta^-(v)$ is the set of edges entering vertex $v$, i.e. $\delta^+(v) = \left\lbrace e \relmiddle| s_e = v \right\rbrace$ and $\delta^-(v) = \left\lbrace e \relmiddle| t_e = v \right\rbrace$.

If there's no such values, output "infeasible" instead.


Constraints:
- $0 \le n \leq 100$
- $0 \le m \leq 1000$
- $0 \le s_e \lt n$
- $0 \le t_e \lt n$
- $|b_v| \le 1000000000$
- $|l_e| \le 1000000000$
- $|u_e| \le 1000000000$
- $|c_e| \le 1000000000$
- $l_e \le u_e$
- All of the values are integral

Note that

- the input graph may contain self loops,
- and the result value may exceed $2^{64}$.


Input:
```
$n$ $m$
$b_0$
 $\vdots$
$b_{n-1}$
$s_0$ $t_0$ $l_0$ $u_0$ $c_0$
 $\vdots$
$s_{m-1}$ $t_{m-1}$ $l_{m-1}$ $u_{m-1}$ $c_{m-1}$
```


Output:
If the problem was infeasible output a single line
```
infeasible
```
. Otherwise,
```
$z$
$p_0$
 $\vdots$
$p_{n-1}$
$f_0$
 $\vdots$
$f_{m-1}$
```
"""


import sys


def solve():
    data = sys.stdin.buffer.read().split()
    # TODO: implement solution for 'min_cost_b_flow'
    pass


if __name__ == "__main__":
    solve()