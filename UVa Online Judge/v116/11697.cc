/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11697.cc
#  Description:     UVa Online Judge - 11697
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
char table[5][5];
set<char> char_used;
int rows[26], cols[26];
string key, text;

void solve() {
    char_used.clear();
    getline(cin, key);
    getline(cin, text);

    int pos = 0;
    for (int i = 0; i < key.length(); i++) {
        if (key[i] == ' ') continue;
        if (char_used.count(key[i])) continue;
        table[pos / 5][pos % 5] = toupper(key[i]);
        rows[key[i] - 'a'] = pos / 5;
        cols[key[i] - 'a'] = pos % 5;
        pos++;
        char_used.insert(key[i]);
    }

    char ch = 'a';
    for (; pos < 25; pos++) {
        while (ch == 'q' or char_used.count(ch)) ch++;
        table[pos / 5][pos % 5] = toupper(ch);
        rows[ch - 'a'] = pos / 5;
        cols[ch - 'a'] = pos % 5;
        char_used.insert(ch);
    }

    text.erase(remove(text.begin(), text.end(), ' '), text.end());
    text.erase(remove(text.begin(), text.end(), 'q'), text.end());

    for (int i = 0; i < text.length(); i += 2) {
        char c1 = text[i];
        char c2;
        if(i+1 >= text.length() or c1 == text[i+1]){
            c2 = 'x';
            i--;
        }else c2 = text[i+1];
        
        if (rows[c1 - 'a'] == rows[c2 - 'a']) {
            cout << table[rows[c1 - 'a']][(cols[c1 - 'a'] + 1) % 5]
                 << table[rows[c2 - 'a']][(cols[c2 - 'a'] + 1) % 5];
        } else if (cols[c1 - 'a'] == cols[c2 - 'a']) {
            cout << table[(rows[c1 - 'a'] + 1) % 5][cols[c1 - 'a']]
                 << table[(rows[c2 - 'a'] + 1) % 5][cols[c2 - 'a']];
        } else {
            cout << table[rows[c1 - 'a']][cols[c2 - 'a']]
                 << table[rows[c2 - 'a']][cols[c1 - 'a']];
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    cin.get();
    while (T--) solve();

    return 0;
}