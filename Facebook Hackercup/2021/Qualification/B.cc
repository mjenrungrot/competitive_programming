/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        B.cc
#  Description:     Facebook hackercup 2021 - Qualification - B
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

void run() {
    int N;
    cin >> N;

    vs A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int min_val = INF_INT;
    int min_count = 0;
    for (int sw = 0; sw < 2; sw++) {
        for (int i = 0; i < N; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                int k1 = sw ? i : j;
                int k2 = sw ? j : i;
                if (A[k1][k2] == '.')
                    count++;
                else if (A[k1][k2] == 'O') {
                    count = INF_INT;
                    break;
                }
            }

            if (min_val == count) {
                min_count++;
            } else if (count < min_val) {
                min_val = count;
                min_count = 1;
            }
        }
    }

    // special case
    if (min_val == 1) {
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++) {
                if (A[r][c] == '.') {
                    bool rr = true;
                    for (int k1 = 0; k1 < N; k1++) {
                        if (k1 == c) continue;
                        if (A[r][k1] == '.' or A[r][k1] == 'O') {
                            rr = false;
                            break;
                        }
                    }

                    bool cc = true;
                    for (int k1 = 0; k1 < N; k1++) {
                        if (k1 == r) continue;
                        if (A[k1][c] == '.' or A[k1][c] == 'O') {
                            cc = false;
                            break;
                        }
                    }

                    if (rr and cc) min_count--;
                }
            }
    }

    if (min_val == INF_INT) {
        cout << "Impossible" << endl;
    } else {
        cout << min_val << " " << min_count << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case #" << tt << ": ";
        run();
    }

    return 0;
}