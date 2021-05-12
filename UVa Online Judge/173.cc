/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        173.cc
#  Description:     UVa Online Judge - 173
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<dd> vdd;

template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << " ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "[ " << p.first << ", " << p.second << "]";
}

vs split(string line, regex re) {
    vs output;
    sregex_token_iterator it(line.begin(), line.end(), re, -1), it_end;
    while (it != it_end) {
        output.push_back(it->str());
        it++;
    }
    return output;
}

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int MAXN = 300;

vi V[MAXN], visited;
bool space, print_paskill, print_lisper;

void dfs(int lisper, int paskill, int& done) {
    if (done) return;
    visited[paskill] |= (1 << 0);
    visited[lisper] |= (1 << 1);

    // Currently at the same location
    if (paskill == lisper) {
        done = true;
        cout << "Both annihilated in node " << (char)paskill;
        return;
    }

    int order;
    int next_lisper = -1, order_lisper = -1;
    int next_paskill = -1, order_paskill = -1;

    for (auto& node : V[paskill]) {
        if (visited[node] & (1 << 0)) continue;
        if (visited[node] & (1 << 1)) continue;
        if (node > paskill)
            order = node - paskill;
        else
            order = MAXN + node;

        if (next_paskill == -1 or order < order_paskill) {
            next_paskill = node;
            order_paskill = order;
        }
    }

    for (auto& node : V[lisper]) {
        if (visited[node] & (1 << 1)) continue;
        if (node > lisper)
            order = MAXN + (MAXN - node);
        else
            order = lisper - node;

        if (next_lisper == -1 or order < order_lisper) {
            next_lisper = node;
            order_lisper = order;
        }
    }
    if (next_paskill == -1) next_paskill = paskill;
    if (next_lisper == -1) next_lisper = lisper;

    // Cannot move paskill
    if (next_paskill == paskill) {
        if (not print_paskill) {
            if (space) cout << " ";
            space = true;
            cout << "Paskill trapped in node " << (char)paskill;
            print_paskill = true;
        }
    }

    // Cannot move lisper
    if (next_lisper == lisper) {
        if (not print_lisper) {
            if (space) cout << " ";
            space = true;
            cout << "Lisper trapped in node " << (char)lisper;
            print_lisper = true;
        }
    }

    // Can move both and to the same location
    if (next_paskill == next_lisper and next_paskill != -1) {
        if (space) cout << " ";
        space = true;
        cout << "Both annihilated in node " << (char)next_paskill;
        done = true;
        return;
    }

    // Move lisper into the nodes visited by paskill
    if (visited[next_lisper] & (1 << 0)) {
        if (space) cout << " ";
        space = true;
        cout << "Lisper destroyed in node " << (char)next_lisper;
        done = true;
        return;
    }

    if (next_lisper == lisper or next_paskill == paskill) {
        done = true;
        return;
    }

    dfs(next_lisper, next_paskill, done);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while (true) {
        getline(cin, line);

        if (line == "#") break;

        for (int i = 0; i < MAXN; i++) V[i].clear();
        visited = vi(MAXN);

        vs tokens = split(line, regex("(\\.\\s|\\s|\\.)"));
        int lisper, paskill;
        if (tokens.size() == 3) {
            lisper = tokens[1][0];
            paskill = tokens[2][0];
        } else if (tokens.size() == 2) {
            lisper = tokens[1][0];
            paskill = tokens[1][1];
        }

        for (auto& edges : split(tokens[0], regex(";"))) {
            vs nodes = split(edges, regex(":"));
            for (auto& node : nodes[1]) {
                V[nodes[0][0]].push_back(node);
                V[node].push_back(nodes[0][0]);
            }
        }

        int done = 0;
        space = print_paskill = print_lisper = false;
        dfs(paskill, lisper, done);
        cout << endl;
    }

    return 0;
}