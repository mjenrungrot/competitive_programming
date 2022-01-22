/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10058.cc
#  Description:     UVa Online Judge - 10058
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
int idx;
string line;
vector<string> tokens;
set<string> ARTICLE = {"a", "the"};
set<string> NOUN = {"tom",   "jerry", "goofy", "mickey",
                    "jimmy", "dog",   "cat",   "mouse"};
set<string> VERB = {"hate",  "love",  "know",  "like",
                    "hates", "loves", "knows", "likes"};

string peek(int pos) {
    if (pos < tokens.size()) return tokens[pos];
    return "";
}

ii consume_verb(int pos) {
    if (pos >= tokens.size()) return {1, -1};
    if (VERB.count(tokens[pos])) return {0, pos + 1};
    return {1, -1};
}

ii consume_noun(int pos) {
    if (pos >= tokens.size()) return {1, -1};
    if (NOUN.count(tokens[pos])) return {0, pos + 1};
    return {1, -1};
}

ii consume_article(int pos) {
    if (pos >= tokens.size()) return {1, -1};
    if (ARTICLE.count(tokens[pos])) return {0, pos + 1};
    return {1, -1};
}

ii consume_actor(int pos) {
    ii article = consume_article(pos);
    if (article.first == 0)
        return consume_noun(article.second);
    else
        return consume_noun(pos);
}

ii consume_active_list(int pos) {
    ii actor = consume_actor(pos);
    if (actor.first) return {1, -1};
    if (peek(actor.second) == "and")
        return consume_active_list(actor.second + 1);
    else
        return actor;
}

ii consume_action(int pos) {
    ii act1 = consume_active_list(pos);
    if (act1.first) return {1, -1};
    ii v = consume_verb(act1.second);
    if (v.first) return {1, -1};
    ii act2 = consume_active_list(v.second);
    return act2;
}

ii consume_statement(int pos) {
    ii c1 = consume_action(pos);
    if(c1.first) return {1, -1};

    if (c1.first == 0 and c1.second == tokens.size()) {
        return c1;
    } else {
        if(peek(c1.second) != ",") return {1, -1};
        return consume_statement(c1.second+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (getline(cin, line)) {
        for(int i=0;i<line.length();i++){
            if(line[i] == ','){
                line.replace(i, 1, " , ");
                i+=2;
            }
        }

        tokens = split(line);
        ii out = consume_statement(0);
        if (out == ii(0, tokens.size()))
            cout << "YES I WILL" << endl;
        else
            cout << "NO I WON'T" << endl;
    }

    return 0;
}