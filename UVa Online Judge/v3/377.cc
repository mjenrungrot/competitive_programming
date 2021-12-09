/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        377.cc
#  Description:     UVa Online Judge - 377
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

int eval(char ch) {
    if (ch == 'V') return 0;
    if (ch == 'U') return 1;
    if (ch == 'C') return 2;
    if (ch == 'D') return 3;
    return 0;
}

char add(char x, char y, char& carry) {
    int res = eval(x) + eval(y) + eval(carry);

    if (res >= 4)
        carry = 'U', res -= 4;
    else
        carry = 0;

    switch (res) {
        case 0:
            return 'V';
        case 1:
            return 'U';
        case 2:
            return 'C';
        case 3:
            return 'D';
    }
    return 0;
}

void perform(vector<char>& num1, vector<char>& num2, char op) {
    if (op == 'N') {
        return;
    } else if (op == 'L') {
        num2.insert(num2.begin(), 'V');
    } else if (op == 'R') {
        num2.push_back('V');
        num2.erase(num2.begin());
    } else if (op == 'A') {
        int pos = 0;

        char res, carry = 0;
        while (pos < num2.size()) {
            res = add((pos < num1.size() ? num1[pos] : 'V'), num2[pos], carry);
            num2[pos] = res;
            pos++;
        }

        if (carry != 0) {
            num2.push_back(carry);
            carry = 0;
        }
    }
}

void solve() {
    string line;
    vector<char> num1, num2, res;

    cin >> line;
    for (int i = line.length() - 1; i >= 0; i--) num1.push_back(line[i]);

    cin >> line;
    for (int i = line.length() - 1; i >= 0; i--) num2.push_back(line[i]);

    cin >> line;
    assert(line.length() == 1);
    perform(num1, num2, line[0]);

    cin >> line;
    assert(line.length() == 1);
    perform(num1, num2, line[0]);

    cin >> line;
    assert(line.length() == 1);
    perform(num1, num2, line[0]);

    while (num2.size() < 8) num2.push_back('V');

    cin >> line;
    for (int i = line.length() - 1; i >= 0; i--) res.push_back(line[i]);

    bool check = true;
    if (num2.size() != res.size())
        check = false;
    else {
        for (int i = 0; i < num2.size(); i++) {
            if (num2[i] != res[i]) {
                check = false;
                break;
            }
        }
    }

    if (check)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    cout << "COWCULATIONS OUTPUT" << endl;
    while (T--) solve();
    cout << "END OF OUTPUT" << endl;

    return 0;
}