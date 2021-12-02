/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        548.cc
#  Description:     UVa Online Judge - 548
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
const int MAXN = 10005;

struct node {
    int val;
    struct node *left, *right;
};

int N, in_ord[MAXN], post_ord[MAXN];

void build_tree(int l_in, int r_in, int l_post, int r_post, struct node*& x) {
    struct node* newx = new node;
    newx->val = post_ord[r_post];
    newx->left = newx->right = nullptr;
    x = newx;

    if (l_in != r_in) {
        for (int i = l_in; i <= r_in; i++) {
            if (post_ord[r_post] == in_ord[i]) {
                int left_size = i - l_in;
                int right_size = r_in - i;
                if (left_size > 0)
                    build_tree(l_in, i - 1, l_post, l_post + left_size - 1,
                               x->left);
                if (right_size > 0)
                    build_tree(i + 1, r_in, l_post + left_size, r_post - 1,
                               x->right);
                break;
            }
        }
    }
}

void f(struct node* x, int sum, int& best_path, int& best_val) {
    if (x->left == nullptr and x->right == nullptr) {
        if (sum + x->val < best_path or
            (sum + x->val == best_path and x->val < best_val)) {
            best_path = sum + x->val;
            best_val = x->val;
        }
        return;
    }
    if (x->left) f(x->left, sum + x->val, best_path, best_val);
    if (x->right) f(x->right, sum + x->val, best_path, best_val);
}

void solve() {
    struct node* root;
    build_tree(1, N, 1, N, root);

    int best_path = INF_INT;
    int best_val = INF_INT;
    f(root, 0, best_path, best_val);
    cout << best_val << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int num;
        N = 0;
        while (iss >> num) {
            N++;
            in_ord[N] = num;
        }
        iss.clear();
        getline(cin, line);
        iss.str(line);
        for (int i = 1; i <= N; i++) iss >> post_ord[i];

        solve();
    }
    return 0;
}