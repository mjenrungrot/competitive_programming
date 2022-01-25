/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10848.cc
#  Description:     UVa Online Judge - 10848
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
string line;

void solve() {
    int n_spaces = 0;
    for (int i = 0; i < line.length(); i++)
        if (line[i] == ' ') ++n_spaces;

    int N;
    vs tokens = split(line, regex("\\s"));

    if (tokens.size() == 2 and line.back() == ' ') tokens.emplace_back("");
    if (tokens.size() != 3 or
        (line.length() !=
         tokens[0].length() + tokens[1].length() + tokens[2].length() + 2)) {
        cout << "FFFFFFF The solution is not accepted" << endl;
        return;
    }

    bool check = true;

    check = check and (tokens[0].length() <= 1000);
    for (int i = 0; i < tokens[0].length() and check; i++) {
        if (tokens[0][i] < 'a' or tokens[0][i] > 'z') {
            check = false;
            break;
        }
    }

    check = check and (tokens[1].length() <= 4);
    check = check and (tokens[1].length() > 0 and tokens[1][0] >= '0' and
                       tokens[1][0] <= '9');
    for (int i = 0; i < tokens[1].length() and check; i++) {
        if (tokens[1][i] < '0' or tokens[1][i] > '9') {
            check = false;
            break;
        }
    }
    if (check) {
        N = stoi(tokens[1]);
        check = check and (N <= 1000);
    }

    check = check and (tokens[2].length() <= 2000);
    for (int i = 0; i < tokens[2].length() and check; i++) {
        if (tokens[2][i] < 'a' or tokens[2][i] > 'z') {
            check = false;
            break;
        }
    }

    if (not check) {
        cout << "FFFFFFF The solution is not accepted" << endl;
        return;
    }

    vector<char> ans(7, 'T');

    // [2]
    check = true;
    for (int i = 0, j = tokens[2].length() - 1; i < j; ++i, --j) {
        if (tokens[2][i] == tokens[2][j])
            continue;
        else {
            check = false;
            break;
        }
    }
    ans[1] = check ? 'T' : 'F';

    // [3]
    vector<int> count1(26), count2(26);
    for (int i = 0; i < tokens[0].length(); i++) count1[tokens[0][i] - 'a']++;
    for (int i = 0; i < tokens[2].length(); i++) count2[tokens[2][i] - 'a']++;

    check = true;
    for (int i = 0; i < 26; i++) {
        if (count1[i] > 0 and count2[i] == 0) {
            check = false;
            break;
        }
    }
    ans[2] = check ? 'T' : 'F';

    // [4]
    check = true;
    for (int i = 0; i < 26; i++) {
        if (count2[i] < count1[i]) {
            check = false;
            break;
        }
    }
    ans[3] = check ? 'T' : 'F';

    // [5]
    int n_change = 0, i1 = 0, i2 = 0;
    while (i2 < tokens[2].length()) {
        if (i1 < tokens[0].length() and tokens[2][i2] == tokens[0][i1])
            ++i1, ++i2;
        else
            ++i2, ++n_change;
    }
    check = (i1 == tokens[0].length());
    ans[4] = check ? 'T' : 'F';

    // [6]
    check = (tokens[2].length() == tokens[0].length() + N);
    ans[5] = check ? 'T' : 'F';

    // [7]
    check = (N < tokens[0].length());
    ans[6] = check ? 'T' : 'F';

    // ans
    int counter = 0;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        counter += (ans[i] == 'T');
    }
    cout << " The solution is " << (counter == 7 ? "accepted" : "not accepted")
         << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (getline(cin, line)) solve();

    return 0;
}