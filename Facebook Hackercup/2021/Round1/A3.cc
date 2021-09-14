/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        A3.cc
#  Description:     Facebook Hacker Cup 2021 - Round1 - A3
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
const int MAXN = 8000005;

const long long MOD = 1e9+7;
int N;

long long len[MAXN];
long long L[MAXN], R[MAXN];
char left_ch[MAXN], right_ch[MAXN];
long long n_pairs[MAXN], sum_left[MAXN], sum_right[MAXN];
long long ans[MAXN];

string commands;

/*
Define

G(S) = sum_{(a,b) in S} (a + 1) * (|S| - b)

By definition, it follows that

G(S1 S2) = sum_{(a,b) in S1 S2} (a + 1) * (|S1 S2| - b)
         = sum_{(a,b) in S1} (a + 1) * (|S1 S2| - b) + sum_{(a,b) in S2} (a + 1) * (|S1 S2| - b) + sum_{a in S1 and b in S2} (a + 1) * (|S1 S2| - b)
         = sum_{(a,b) in S1} (a + 1) * (|S1| - b) + sum_{(a,b) in S1} (a + 1) * |S2| + 
                sum_{(a,b) in S2} (a - |S1| + 1) * (|S1 S2| - b) + sum_{(a,b) in S2} (|S1 S2| - b) * |S1| + 
                (right[S1] + 1) * (|S1 S2| - (|S1| + left[S2]))
         = G(S1) + |S2| sum_{(a,b) in S1} (a+1) +
                G(S2) + |S1| sum_{(a,b) in S2} (|S1 S2| - b) + 
                (right[S1] + 1) * (|S1 S2| - (|S1| + left[S2]))
         = G(S1) + |S2| (sum_left(S1) + n_pairs(S1)) + 
           G(S2) + |S1| (|S1 S2| n_pairs(S2) - (|S1| * n_pairs(S2) + sum_right(S2))) +
           (right(S1) + 1) * (|S1 S2| - (|S1| + left(S2)))

given that
sum_left(S) = sum_{(a,b) in S} a
sum_right(S) = sum_((a,b) in S) b
n_pairs(S) = sum_{(a,b) in S} 1
*/

void run(){
    cin >> N;
    cin >> commands;

    len[0] = 0;
    L[0] = R[0] = -1;
    left_ch[0] = right_ch[0] = 0;
    n_pairs[0] = 0;
    sum_left[0] = sum_right[0] = ans[0] = 0;

    for(int i=0;i<commands.length();i++){
        if(commands[i] == '.'){
            // update length
            len[i+1] = len[i] * 2;

            if(left_ch[i] == 0){
                assert(right_ch[i] == 0);
                L[i+1] = R[i+1] = -1;
                left_ch[i+1] = right_ch[i+1] = 0;
                sum_left[i+1] = sum_right[i+1] = 0;
                n_pairs[i+1] = 0;
                ans[i+1] = 0;
            }else{
                L[i+1] = L[i];
                left_ch[i+1] = left_ch[i];
                R[i+1] = len[i] + R[i];
                right_ch[i+1] = right_ch[i];
                sum_left[i+1] = 2 * sum_left[i] + n_pairs[i] * len[i] + (left_ch[i] == right_ch[i] ? 0LL : R[i]);
                sum_right[i+1] = 2 * sum_right[i] + n_pairs[i] * len[i] + (left_ch[i] == right_ch[i] ? 0LL : L[i] + len[i]);
                n_pairs[i+1] = n_pairs[i] * 2 + (left_ch[i] == right_ch[i] ? 0LL : 1LL);
                
                ans[i+1] = 0;
                ans[i+1] += ans[i] + len[i] * (sum_left[i] + n_pairs[i]);
                ans[i+1] = (ans[i+1] % MOD + MOD) % MOD;
                ans[i+1] += ans[i];
                ans[i+1] += len[i] * ((len[i+1] * n_pairs[i]) % MOD - (len[i] * n_pairs[i] + sum_right[i]) % MOD + MOD) % MOD;
                ans[i+1] = (ans[i+1] % MOD + MOD) % MOD;
                ans[i+1] += (left_ch[i] == right_ch[i] ? 0LL : (R[i] + 1) * (len[i+1] - len[i] - L[i]));
            }
        }else{
            // update length
            len[i+1] = len[i] + 1;

            if(left_ch[i] == 0){
                assert(right_ch[i] == 0);
                if(commands[i] == 'X' or commands[i] == 'O'){
                    L[i+1] = R[i+1] = len[i+1] - 1;
                    left_ch[i+1] = right_ch[i+1] = commands[i];
                    sum_left[i+1] = sum_right[i+1] = 0;
                    n_pairs[i+1] = 0;
                    ans[i+1] = 0;
                }else{
                    L[i+1] = R[i+1] = -1;
                    left_ch[i+1] = right_ch[i+1] = 0;
                    sum_left[i+1] = sum_right[i+1] = 0;
                    n_pairs[i+1] = 0;
                    ans[i+1] = 0;
                }
            }else{
                L[i+1] = L[i];
                left_ch[i+1] = left_ch[i];
                if(commands[i] == 'X' or commands[i] == 'O'){
                    R[i+1] = len[i+1] - 1;
                    right_ch[i+1] = commands[i];

                    sum_left[i+1] = sum_left[i] + ((right_ch[i] == commands[i]) ? 0LL : R[i]);
                    sum_right[i+1] = sum_right[i] + ((right_ch[i] == commands[i]) ? 0LL : R[i+1]);
                    n_pairs[i+1] = n_pairs[i] + ((right_ch[i] == commands[i]) ? 0LL : 1LL);
                    ans[i+1] = ans[i] + (sum_left[i] + n_pairs[i]) + ((right_ch[i] == commands[i]) ? 0LL : R[i] + 1);
                }else{
                    R[i+1] = R[i];
                    right_ch[i+1] = right_ch[i];
                    sum_left[i+1] = sum_left[i];
                    sum_right[i+1] = sum_right[i];
                    n_pairs[i+1] = n_pairs[i];
                    ans[i+1] = ans[i] + (sum_left[i] + n_pairs[i]);
                }
            }
         
        }

        L[i+1] = ((L[i+1] % MOD) + MOD) % MOD;
        R[i+1] = ((R[i+1] % MOD) + MOD) % MOD;
        len[i+1] = ((len[i+1] % MOD) + MOD) % MOD;
        n_pairs[i+1] = ((n_pairs[i+1] % MOD) + MOD) % MOD;
        sum_left[i+1] = ((sum_left[i+1] % MOD) + MOD) % MOD;
        sum_right[i+1] = ((sum_right[i+1] % MOD) + MOD) % MOD;
        ans[i+1] = ((ans[i+1] % MOD) + MOD) % MOD;

        // if(i == commands.length()-1){
        //     debug(i, L[i+1], R[i+1], len[i+1], n_pairs[i+1], sum_left[i+1], sum_right[i+1], ans[i+1]);
        // }
    }

    cout << ans[commands.length()] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": ";
        run();
    }

    return 0;
}