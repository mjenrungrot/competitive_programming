/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10166.cc
#  Description:     UVa Online Judge - 10166
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
const int MAXN = 105;

int N, n_trains;
string names[MAXN];
map<string, int> name_to_idx;
vii trains[MAXN];
vii G[MAXN];
ii best_time[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> N){
        if(N == 0) break;

        name_to_idx.clear();
        for(int i=0;i<N;i++){
            G[i].clear();
            cin >> names[i];
            name_to_idx[names[i]] = i;
        }

        cin >> n_trains;
        for(int i=0;i<n_trains;i++){
            trains[i].clear();

            int n_stops;
            cin >> n_stops;
            for(int j=0;j<n_stops;j++){
                int tt;
                string name;
                cin >> tt >> name;
                trains[i].emplace_back(tt, name_to_idx[name]);
            }

            for(int j=0;j<n_stops-1;j++){
                G[trains[i][j].second].emplace_back(trains[i][j+1].second, trains[i][j+1].first);
            }
        }

        int start_time;
        cin >> start_time;

        string tmp;
        cin >> tmp;
        int start = name_to_idx[tmp];

        cin >> tmp;
        int target = name_to_idx[tmp];

        for(int i=0;i<MAXN;i++) best_time[i] = ii(INF_INT, INF_INT);
        best_time[start] = ii(start_time, start_time);

        auto cmp = [](iii x, iii y){ 
            if(get<0>(x) != get<0>(y)) return get<0>(x) > get<0>(y); // late arrival leaves later
            return get<1>(x) < get<1>(y); // early departure leaves later
        };
        priority_queue<iii, vector<iii>, decltype(cmp)> pq(cmp); // (arrival, depart, node)
        pq.push({0, })


        for(int i=0;i<n_trains;i++){
            for(auto j=0;j<trains[i].size();j++){
                if(start_time <= trains[i][j].first and trains[i][j].second == start){
                    pq.push({trains[i][j].first, trains[i][j].first, start});
                }
            }
        }

        while(not pq.empty()){
            auto curr_time = get<0>(pq.top());
            auto depart_time = get<1>(pq.top());
            auto u = get<2>(pq.top());
            pq.pop();

            cout << curr_time << " " << depart_time << " " << names[u] << endl;

            if(u != start and curr_time > best_time[u].first) continue;
            if(u == target) break;

            for(auto &x: G[u]){
                auto v = x.first;
                auto arrival_time = x.second;
                if(arrival_time < curr_time) continue;
                if(arrival_time < best_time[v].first or (arrival_time == best_time[v].first and depart_time > best_time[v].second)){
                    best_time[v] = ii(arrival_time, depart_time);
                    cout << "best : " << names[v] << " : " << best_time[v] << endl;
                    pq.push({arrival_time, depart_time, v});
                }
            }
        }

        if(best_time[target].first == INF_INT) cout << "No connection" << endl;
        else cout << setw(4) << setfill('0') << best_time[target].second << " " << setw(4) << setfill('0') << best_time[target].first << endl;
    }
    
    return 0;
}