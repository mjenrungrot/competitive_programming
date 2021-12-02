/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12644.cc
#  Description:     UVa Online Judge - 12644
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

vector<string> vocabs, challenges;
vvi Vleft;
vi visited, matchR;
int V, C;

int possible(int i, int j) {
    int counter1[30], counter2[30];
    memset(counter1, 0, sizeof(counter1));
    memset(counter2, 0, sizeof(counter2));

    for (auto& ch : vocabs[i]) counter1[ch - 'a']++;
    for (auto& ch : challenges[j]) counter2[ch - 'a']++;

    for (int k = 0; k < 26; k++) {
        if (counter2[k] > 0 and counter1[k] < counter2[k]) return false;
    }
    return true;
}

int MCBM(int L) {
    if (visited[L]) return 0;
    visited[L] = 1;

    for (auto& R : Vleft[L]) {
        if (matchR[R] == -1 or MCBM(matchR[R])) {
            matchR[R] = L;
            return 1;
        }
    }

    return 0;
}

void solve() {
    vocabs.clear();
    challenges.clear();

    for (int i = 0; i < V; i++) {
        string x;
        cin >> x;
        vocabs.push_back(x);
    }

    for (int i = 0; i < C; i++) {
        string x;
        cin >> x;
        challenges.push_back(x);
    }

    Vleft.assign(V, vi());
    for (int i = 0; i < V; i++)
        for (int j = 0; j < C; j++) {
            if (possible(i, j)) {
                Vleft[i].push_back(j);
            }
        }

    matchR.assign(C, -1);
    int n_pairs = 0;
    for (int i = 0; i < V; i++) {
        visited.assign(V, 0);
        n_pairs += MCBM(i);
    }
    cout << n_pairs << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> V >> C) solve();

    return 0;
}