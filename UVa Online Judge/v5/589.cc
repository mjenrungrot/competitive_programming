/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        589.cc
#  Description:     UVa Online Judge - 589
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef tuple<long long, long long, long long> lll;
typedef tuple<double, double, double> ddd;
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

// Debug Snippets

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V>& x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T& x) {
    int f = 0;
    cerr << '{';
    for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)

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

// End Debug Snippets

class union_find {
    vi parent, sizes;

   public:
    union_find(int n) {
        parent.resize(n);
        sizes.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    int find_set(int a) {
        if (a == parent[a]) return a;
        return parent[a] = find_set(parent[a]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sizes[a] < sizes[b]) swap(a, b);
            parent[b] = a;
            sizes[a] += sizes[b];
        }
    }
};

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
const int MAXR = 25;
const int MAXC = 25;

int R, C;
int state[MAXR][MAXC][MAXR][MAXC];
char parent[MAXR][MAXC][MAXR][MAXC];
string A[MAXR];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int maze_id = 0;
    while (cin >> R >> C) {
        if (R == 0 and C == 0) break;

        for (int i = 0; i < R; i++) cin >> A[i];

        ii box, me, target;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                if (A[i][j] == 'B') box = ii(i, j);
                if (A[i][j] == 'S') me = ii(i, j);
                if (A[i][j] == 'T') {
                    target = ii(i, j);
                    A[i][j] = '.';
                }
            }

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                for (int i2 = 0; i2 < R; i2++)
                    for (int j2 = 0; j2 < C; j2++) {
                        state[i][j][i2][j2] = INF_INT;
                        parent[i][j][i2][j2] = 0;
                    }
            }

        state[box.first][box.second][me.first][me.second] = 0;
        auto cmp = [](tuple<int, int, int, int, int> x,
                      tuple<int, int, int, int, int> y) {
            return get<0>(x) > get<0>(y);
        };
        priority_queue<tuple<int, int, int, int, int>,
                       vector<tuple<int, int, int, int, int>>, decltype(cmp)>
            pq(cmp);
        pq.push({0, box.first, box.second, me.first, me.second});

        bool found = false;
        tuple<int, int, int, int> curr;

        while (not pq.empty()) {
            auto top_node = pq.top();
            pq.pop();

            auto curr_d = get<0>(top_node);
            auto u_box = ii(get<1>(top_node), get<2>(top_node));
            auto u_me = ii(get<3>(top_node), get<4>(top_node));

            // cout << u_box << " " << u_me << endl;

            if (u_box == target) {
                found = true;
                curr = {u_box.first, u_box.second, u_me.first, u_me.second};
                break;
            }
            if (state[u_box.first][u_box.second][u_me.first][u_me.second] <
                curr_d)
                continue;

            for (auto dy : {-1, 0, 1}) {
                if (u_me.first + dy < 0 or u_me.first > dy >= R) continue;
                for (auto dx : {-1, 0, 1}) {
                    if (u_me.second + dx < 0 or u_me.second + dx >= C) continue;
                    if (abs(dx) + abs(dy) != 1) continue;
                    auto v_me = ii(u_me.first + dy, u_me.second + dx);
                    if (A[v_me.first][v_me.second] == '#') continue;

                    if (v_me == u_box) {
                        auto v_box =
                            ii(u_me.first + 2 * dy, u_me.second + 2 * dx);

                        if (v_box.first < 0 or v_box.first >= R or
                            v_box.second < 0 or v_box.second >= C)
                            continue;

                        if (curr_d + 10000 < state[v_box.first][v_box.second]
                                                  [v_me.first][v_me.second]) {
                            char par_val;
                            if (dy == -1)
                                par_val = 'N';
                            else if (dy == 1)
                                par_val = 'S';
                            else if (dx == -1)
                                par_val = 'W';
                            else
                                par_val = 'E';

                            state[v_box.first][v_box.second][v_me.first]
                                 [v_me.second] = curr_d + 10000;
                            parent[v_box.first][v_box.second][v_me.first]
                                  [v_me.second] = par_val;
                            pq.push({curr_d + 10000, v_box.first, v_box.second,
                                     v_me.first, v_me.second});
                        }

                    } else {
                        auto v_box = u_box;
                        if (curr_d + 1 < state[v_box.first][v_box.second]
                                              [v_me.first][v_me.second]) {
                            char par_val;
                            if (dy == -1)
                                par_val = 'n';
                            else if (dy == 1)
                                par_val = 's';
                            else if (dx == -1)
                                par_val = 'w';
                            else
                                par_val = 'e';

                            state[v_box.first][v_box.second][v_me.first]
                                 [v_me.second] = curr_d + 1;
                            parent[v_box.first][v_box.second][v_me.first]
                                  [v_me.second] = par_val;
                            pq.push({curr_d + 1, v_box.first, v_box.second,
                                     v_me.first, v_me.second});
                        }
                    }
                }
            }
        }

        cout << "Maze #" << ++maze_id << endl;

        if (not found) {
            cout << "Impossible." << endl << endl;
            continue;
        }

        string ans;
        while (parent[get<0>(curr)][get<1>(curr)][get<2>(curr)][get<3>(curr)] !=
               0) {
            char par_val =
                parent[get<0>(curr)][get<1>(curr)][get<2>(curr)][get<3>(curr)];
            ans += par_val;
            if (par_val == 'e') {
                curr = {get<0>(curr), get<1>(curr), get<2>(curr),
                        get<3>(curr) - 1};
            } else if (par_val == 'n') {
                curr = {get<0>(curr), get<1>(curr), get<2>(curr) + 1,
                        get<3>(curr)};
            } else if (par_val == 's') {
                curr = {get<0>(curr), get<1>(curr), get<2>(curr) - 1,
                        get<3>(curr)};
            } else if (par_val == 'w') {
                curr = {get<0>(curr), get<1>(curr), get<2>(curr),
                        get<3>(curr) + 1};
            } else if (par_val == 'E') {
                curr = {get<0>(curr), get<1>(curr) - 1, get<2>(curr),
                        get<3>(curr) - 1};
            } else if (par_val == 'N') {
                curr = {get<0>(curr) + 1, get<1>(curr), get<2>(curr) + 1,
                        get<3>(curr)};
            } else if (par_val == 'S') {
                curr = {get<0>(curr) - 1, get<1>(curr), get<2>(curr) - 1,
                        get<3>(curr)};
            } else if (par_val == 'W') {
                curr = {get<0>(curr), get<1>(curr) + 1, get<2>(curr),
                        get<3>(curr) + 1};
            }
        }
        for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
        cout << endl << endl;
    }

    return 0;
}