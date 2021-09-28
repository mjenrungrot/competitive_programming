/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        A.cc
#  Description:     Facebook Hackercup 2021 - Round2 - A
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


class union_find {
    vi parent, sizes;

   public:
    union_find(int n) {
        parent.resize(n);
        sizes.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    int find_set(int a) {
        if (a == parent[a]) return a;
        return parent[a] = find_set(parent[a]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sizes[a] < sizes[b]) swap(a, b);
            parent[b] = a;
            sizes[a] += sizes[b];
        }
    }
};


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

int N, M;

void solve(){
    cin >> N >> M;
    
    int ans = 0;
    auto pair_hash = [](const ii &p){ return p.first + (1e9+7) * p.second; };
    auto pair_equal = [](const ii &p1, const ii &p2){ return (p1.first == p2.first and p1.second == p2.second); };
    vi style(M), new_style(M);
    unordered_multiset<ii, decltype(pair_hash)> S(0, pair_hash);
    unordered_multiset<ii, decltype(pair_hash)> newS(0, pair_hash); // (style_id, free_change?)

    for(int i=0;i<M;i++){
        cin >> style[i];
        S.insert(ii(style[i], 1));
    }

    for(int r=0;r<N;r++){
        vi to_change;
        for(int i=0;i<M;i++){
            cin >> new_style[i];
            auto same_already_change = S.find(ii(new_style[i], 0));
            if(same_already_change == S.end()){
                auto same_unchange = S.find(ii(new_style[i], 1));
                if(same_unchange == S.end()){
                    to_change.push_back(new_style[i]);
                }else{
                    // do nothing (keep the same)
                    newS.insert(ii(new_style[i], 1));
                    S.erase(same_unchange);
                }
            }else{
                // do nothing (keep the same)
                newS.insert(ii(new_style[i], 0));
                S.erase(same_already_change);
            }
        }

        for(auto &x: S){
            newS.insert(ii(to_change.back(), 0));
            to_change.pop_back();
            if(x.second == 0){
                ans++;
            }
        }

        S.clear();
        for(auto &x: newS){
            S.insert(x);
        }
        newS.clear();
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}