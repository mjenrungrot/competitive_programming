/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11284.cc
#  Description:     UVa Online Judge - 11284
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
const int MAXN = 52;
const int MAXP = 14;
const int MAXMASK = (1<<14);

int N, M, P;
int dist[MAXN][MAXN];
int loc[MAXN];
int saving[MAXN];

int valid[MAXMASK][MAXP];
int dp[MAXMASK][MAXP], ans; // best-saving

int f(int mask, int u){
    if(mask == 0) return -dist[loc[u]][loc[0]];

    if(valid[mask][u]) return dp[mask][u];

    int curr_ans = -dist[loc[u]][loc[0]];
    int curr_mask = mask;
    while(curr_mask > 0){
        int curr_idx = curr_mask & -curr_mask;
        int curr_idx_pos = __builtin_ctz(curr_idx);
        int val_go_buy = f(mask - curr_idx, curr_idx_pos) + saving[curr_idx_pos] - dist[loc[u]][loc[curr_idx_pos]];
        curr_ans = max(curr_ans, val_go_buy);
        curr_mask -= curr_idx;
    }

    valid[mask][u] = true;
    return dp[mask][u] = curr_ans;
}

void run(){
    for(int i=0;i<MAXN;i++) for(int j=0;j<MAXN;j++) dist[i][j] = (i == j ? 0 : INF_INT);

    cin >> N >> M;
    for(int i=1;i<=M;i++){
        int u,v;
        double w;
        cin >> u >> v >> w;
        int val = (int)round(w * 100.0);

        dist[u][v] = min(dist[u][v], val);
        dist[v][u] = min(dist[v][u], val);
    }

    for(int k=0;k<=N;k++) for(int i=0;i<=N;i++) for(int j=0;j<=N;j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    cin >> P;
    for(int i=1;i<=P;i++){
        double tmp;
        cin >> loc[i] >> tmp;
        saving[i] = (int)round(tmp * 100.0);
    }

    memset(valid, 0, sizeof(valid));
    int ans = f((1<<(P+1))-1, 0);

    if(ans > 0){
        cout << "Daniel can save $" << ans/100 << "." << setw(2) << setfill('0') << ans % 100 << endl;
    }else{
        cout << "Don't leave the house" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        run();
    }
    return 0;
}