/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        117.cc
#  Description:     UVa Online Judge - 117
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

vs split(string line) {
    vs output;
    istringstream iss(line);
    string tmp;
    while (iss >> tmp) {
        output.push_back(tmp);
    }
    return output;
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
const int MAXN = 30;

int in_deg[MAXN];
vii V[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        memset(in_deg, 0, sizeof(in_deg));
        for (int i = 0; i < MAXN; i++) V[i].clear();

        int ans = 0;
        string line;
        while (getline(cin, line)) {
            if (line == "deadend") break;

            int L = line.length();
            V[line[0] - 'a'].emplace_back(line[L - 1] - 'a', L);
            V[line[L - 1] - 'a'].emplace_back(line[0] - 'a', L);
            in_deg[line[0] - 'a']++;
            in_deg[line[L - 1] - 'a']++;
            ans += L;
        }

        int u = -1, v = -1;
        for (int i = 0; i < MAXN; i++) {
            if (in_deg[i] % 2) {
                if (u == -1)
                    u = i;
                else
                    v = i;
            }
        }

        if (u != -1 and v != -1) {
            // high weight = low priority
            auto cmp = [](ii& x, ii& y) { return x.first > y.first; };
            priority_queue<ii, vii, decltype(cmp)> pq(cmp);

            vi dist(MAXN, INF_INT);
            dist[u] = 0;
            pq.push({dist[u], u});

            while (not pq.empty()) {
                auto uu = pq.top();
                pq.pop();

                if (dist[uu.second] < uu.first) continue;
                if (uu.second == v) break;

                for (auto& vw : V[uu.second]) {
                    if (uu.first + vw.second < dist[vw.first]) {
                        dist[vw.first] = uu.first + vw.second;
                        pq.push({dist[vw.first], vw.first});
                    }
                }
            }

            ans += dist[v];
        }
        cout << ans << endl;

        cin.peek();
        if (cin.eof()) break;
    }
    return 0;
}