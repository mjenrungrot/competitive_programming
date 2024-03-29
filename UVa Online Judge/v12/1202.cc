/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1202.cc
#  Description:     UVa Online Judge - 1202
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
const int MAXR = 202;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int cost[MAXR][MAXR][4];
int dist[MAXR][MAXR];
int visited[MAXR][MAXR];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int A, B;
    while(cin >> A >> B){
        if(A == -1 and B == -1) break;

        for(int i=0;i<MAXR;i++) for(int j=0;j<MAXR;j++) for(int k=0;k<4;k++){
            if(i + dy[k] < 0 or i + dy[k] >= MAXR or j + dx[k] < 0 or j + dx[k] >= MAXR){
                cost[i][j][k] = INF_INT;
            }else{   
                cost[i][j][k] = 0;
            }
        }

        // obstacles
        for(int i=1;i<=A;i++){
            int x,y,d,t;
            cin >> x >> y >> d >> t;

            if(d == 0){
                // x-axis
                for(int j=x;j<x+t;j++){
                    cost[y][j][0] = INF_INT; // can't go down
                    cost[y-1][j][2] = INF_INT; // can't go up
                }

            }else{
                // y-axis
                for(int j=y;j<y+t;j++){
                    cost[j][x-1][1] = INF_INT; // can't go right
                    cost[j][x][3] = INF_INT; // can't go left
                }
            } 
        }

        // obstacles
        for(int i=1;i<=B;i++){
            int x,y,d;
            cin >> x >> y >> d;

            if(d == 0){
                cost[y][x][0] = 1;
                cost[y-1][x][2] = 1;
            }else{
                cost[y][x-1][1] = 1;
                cost[y][x][3] = 1;
            } 
        }

        double xx, yy;
        cin >> xx >> yy;

        int rx = (int)floor(xx);
        int ry = (int)floor(yy);

        rx = min(rx, MAXR-1);
        ry = min(ry, MAXR-1);
        rx = max(rx, 0);
        ry = max(ry, 0);

        memset(visited, 0, sizeof(visited));
        for(int i=0;i<MAXR;i++) for(int j=0;j<MAXR;j++) dist[i][j] = INF_INT;
        dist[ry][rx] = 0;

        auto cmp = [](iii &x, iii &y){ return get<0>(x) > get<0>(y); };
        priority_queue<iii, vector<iii>, decltype(cmp)> pq(cmp);
        pq.push({dist[ry][rx], ry, rx});

        while(not pq.empty()){
            iii u = pq.top();
            pq.pop();

            if(visited[get<1>(u)][get<2>(u)]) continue;
            visited[get<1>(u)][get<2>(u)] = true;

            if(get<0>(u) > dist[get<1>(u)][get<2>(u)]) continue;
            if(get<1>(u) == 0 and get<2>(u) == 0) break;
            
            // cout << get<0>(u) << ": " << get<1>(u) << "," << get<2>(u) << endl;

            auto curr_d = get<0>(u);
            for(int k=0;k<4;k++){
                ii new_v = {get<1>(u) + dy[k], get<2>(u) + dx[k]};
                if(new_v.first < 0 or new_v.first >= MAXR or new_v.second < 0 or new_v.second >= MAXR) continue;
                if(curr_d + cost[get<1>(u)][get<2>(u)][k] < dist[new_v.first][new_v.second]){
                    dist[new_v.first][new_v.second] = curr_d + cost[get<1>(u)][get<2>(u)][k];
                    pq.push({dist[new_v.first][new_v.second], new_v.first, new_v.second});
                }
            }
        }
        if(dist[0][0] == INF_INT) cout << -1 << endl;
        else cout << dist[0][0] << endl;
    }

    return 0;
}