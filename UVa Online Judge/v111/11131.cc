/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11131.cc
#  Description:     UVa Online Judge - 11131
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
const int MAXN = 5005;

struct node {
    int idx;
    vector<struct node*> children;

    node() {
        idx = -1;
        children.clear();
    }
};

string names[MAXN];
struct node* pointer[MAXN];
map<string, int> to_idx;

int f(string name) {
    if (to_idx.count(name)) return to_idx[name];
    return to_idx[name] = to_idx.size();
}

void post(struct node* x, vi& output, int type) {
    if (type == 0) {
        for (int i = 0; i < x->children.size(); i++)
            post(x->children[i], output, type);
    } else {
        for (int i = x->children.size() - 1; i >= 0; i--)
            post(x->children[i], output, type);
    }
    output.push_back(x->idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while (getline(cin, line)) {
        vs tokens = split(line, regex(","));

        for (auto& token : tokens) f(token);

        int node1 = f(tokens[0]);
        if (pointer[node1] == nullptr) {
            pointer[node1] = new node;
            pointer[node1]->idx = node1;
            names[node1] = tokens[0];
        }

        for (int i = 1; i < tokens.size(); i++) {
            int node2 = f(tokens[i]);
            if (pointer[node2] == nullptr) {
                pointer[node2] = new node;
                pointer[node2]->idx = node2;
                names[node2] = tokens[i];
            }
            pointer[node1]->children.push_back(pointer[node2]);
        }
    }

    vi output1, output2;
    post(pointer[0], output1, 0);
    post(pointer[0], output2, 1);

    bool flag = true;
    for (int i = 0; i < output1.size(); i++)
        if (output1[i] != output2[i]) {
            flag = false;
            break;
        }

    if (flag)
        cout << 1 << endl << endl;
    else
        cout << 2 << endl << endl;

    for (auto& x : output1) cout << names[x] << endl;
    cout << endl;
    for (auto& x : output2) cout << names[x] << endl;

    return 0;
}