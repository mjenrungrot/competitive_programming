/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12319.cc
#  Description:     UVa Online Judge - 12319
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
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

int N, d1[MAXN][MAXN], d2[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    while (true) {
        getline(cin, line);
        N = stoi(line);
        if (N == 0) break;

        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                d1[i][j] = d2[i][j] = (i == j ? 0 : INF_INT);

        for (int i = 1; i <= N; i++) {
            getline(cin, line);
            vs tokens = split(line, regex("\\s"));
            vi nums(tokens.size());
            transform(tokens.begin(), tokens.end(), nums.begin(),
                      [](string& num) { return stoi(num); });

            for (int j = 1; j < nums.size(); j++) {
                d1[nums[0]][nums[j]] = min(d1[nums[0]][nums[j]], 1);
            }
        }

        for (int i = 1; i <= N; i++) {
            getline(cin, line);
            vs tokens = split(line, regex("\\s"));
            vi nums(tokens.size());
            transform(tokens.begin(), tokens.end(), nums.begin(),
                      [](string& num) { return stoi(num); });
            for (int j = 1; j < nums.size(); j++) {
                d2[nums[0]][nums[j]] = min(d2[nums[0]][nums[j]], 1);
            }
        }

        getline(cin, line);
        vs nums = split(line, regex("\\s"));

        int A, B;
        A = stoi(nums[0]);
        B = stoi(nums[1]);

        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++) {
                    d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
                    d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
                }

        bool check = true;
        for (int i = 1; i <= N and check; i++)
            for (int j = 1; j <= N and check; j++) {
                if (A * d1[i][j] + B < d2[i][j]) {
                    check = false;
                }
            }

        cout << (check ? "Yes" : "No") << endl;
    }
    return 0;
}