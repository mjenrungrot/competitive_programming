/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        122.cc
#  Description:     UVa Online Judge - 122
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
const int MAXN = 260;

struct node {
    int val;
    int valid;
    struct node *left, *right;

    node() {
        val = 0;
        valid = 0;
        left = right = nullptr;
    }
};

void build(int num, string& pos, struct node*& root) {
    if (root == nullptr) root = new node;

    struct node* curr = root;
    for (int i = 0; i < pos.length(); i++) {
        if (pos[i] == 'L') {
            if (curr->left == nullptr) curr->left = new node;
            curr = curr->left;
        } else {
            if (curr->right == nullptr) curr->right = new node;
            curr = curr->right;
        }
    }
    curr->val = num;
    curr->valid += 1;
}
void check_all(struct node* x, int& flag) {
    if (flag) return;
    if (x == nullptr) return;

    if (x->valid != 1) {
        flag = true;
        return;
    }
    check_all(x->left, flag);
    check_all(x->right, flag);
}

void print_all(struct node* x, int d, vi node_by_depth[MAXN]) {
    if (x == nullptr) return;
    node_by_depth[d].emplace_back(x->val);
    print_all(x->left, d + 1, node_by_depth);
    print_all(x->right, d + 1, node_by_depth);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    char ch, next_ch;
    struct node* root;
    while (true) {
        root = nullptr;

        while (cin >> ch) {
            cin >> next_ch;
            if (next_ch == ')') {
                int flag = false;
                check_all(root, flag);

                if (flag) {
                    cout << "not complete" << endl;
                } else {
                    vi node_by_depth[MAXN];
                    print_all(root, 1, node_by_depth);

                    bool space = false;
                    for (int d = 1; d < MAXN; d++) {
                        for (auto& x : node_by_depth[d]) {
                            if (space) cout << " ";
                            space = true;
                            cout << x;
                        }
                    }
                    cout << endl;
                }
                break;
            }

            cin.putback(next_ch);

            cin >> num;
            cin >> ch;  // ,

            string pos = "";
            while (cin >> ch) {
                if (ch == ')') break;
                pos += ch;
            }

            build(num, pos, root);
        }

        if (cin.eof()) break;
    }

    return 0;
}