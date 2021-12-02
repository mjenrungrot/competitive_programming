/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        699.cc
#  Description:     UVa Online Judge - 699
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

struct node {
    int val;
    struct node *left, *right;
};

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;

int N;

void read_tree(struct node*& x) {
    int val;
    cin >> val;

    if (val == -1) {
        return;
    }

    x = new node;
    x->val = val;
    x->left = x->right = nullptr;
    read_tree(x->left);
    read_tree(x->right);
}

void dfs(struct node* x, int x_pos, map<int, int>& counter) {
    counter[x_pos] += x->val;
    if (x->left) dfs(x->left, x_pos - 1, counter);
    if (x->right) dfs(x->right, x_pos + 1, counter);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_test = 0;
    while (true) {
        struct node* root = nullptr;
        read_tree(root);

        if (root == nullptr) break;
        cout << "Case " << ++n_test << ":" << endl;

        map<int, int> counter;
        dfs(root, 0, counter);

        bool space = false;
        for (auto& kv : counter) {
            if (space) cout << " ";
            space = true;
            cout << kv.second;
        }
        cout << endl << endl;
    }

    return 0;
}