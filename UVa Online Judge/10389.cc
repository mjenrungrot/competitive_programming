/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10389.cc
#  Description:     UVa Online Judge - 10389
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
const int MAXN = 1005;
const double WALK = 10.0 / 60.0 * 1000.0;  // meter / min
const double TRAIN = 40.0 / 60.0 * 1000.0;
map<ii, int> to_idx;
ii pos[MAXN];
vector<pair<int, double>> V[MAXN];

int conv(ii x) {
    if (to_idx.count(x)) return to_idx[x];
    pos[to_idx.size()] = x;
    return to_idx[x] = to_idx.size();
}

double calc(ii x, ii y) {
    return hypot(x.first - y.first, x.second - y.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);
    int T = stoi(line);

    getline(cin, line);
    while (T--) {
        to_idx.clear();
        for (int i = 0; i < MAXN; i++) V[i].clear();

        getline(cin, line);
        vs tokens = split(line, regex("\\s"));
        vi nums;
        for (auto& token : tokens) nums.push_back(stoi(token));

        ii start = {nums[0], nums[1]};
        ii target = {nums[2], nums[3]};
        int st = conv(start);
        int en = conv(target);

        while (getline(cin, line)) {
            if (line == "") break;
            tokens = split(line, regex("\\s"));
            nums.clear();
            for (auto& token : tokens) nums.push_back(stoi(token));

            for (int i = 0; i < nums.size() - 2; i += 2) {
                if (nums[i] == -1) break;
                ii curr = {nums[i], nums[i + 1]};
                int curr_station = conv(curr);

                if (i + 2 < nums.size() - 2) {
                    ii next_node = {nums[i + 2], nums[i + 3]};
                    int next_station = conv(next_node);
                    V[curr_station].push_back(
                        {next_station, calc(curr, next_node) / TRAIN});
                    V[next_station].push_back(
                        {curr_station, calc(next_node, curr) / TRAIN});
                }
            }
        }

        for (int i = 0; i < to_idx.size(); i++)
            for (int j = i + 1; j < to_idx.size(); j++) {
                auto w = calc(pos[i], pos[j]) / WALK;
                V[i].push_back({j, w});
                V[j].push_back({i, w});
            }

        vd dist(MAXN, 1e9);
        dist[st] = 0.0;

        auto cmp = [](pair<double, int>& x, pair<double, int>& y) {
            return x.first > y.first;
        };
        priority_queue<pair<double, int>, vector<pair<double, int>>,
                       decltype(cmp)>
            pq(cmp);
        pq.push({dist[st], st});
        while (not pq.empty()) {
            auto u = pq.top();
            pq.pop();

            auto d = u.first;
            auto loc = u.second;

            if (d > dist[loc]) continue;
            for (auto& v : V[loc]) {
                if (dist[v.first] <= dist[loc] + v.second) continue;
                dist[v.first] = dist[loc] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }

        auto ans = (int)(dist[en] + 0.5);
        cout << ans << endl;
        if (T) cout << endl;
    }

    return 0;
}