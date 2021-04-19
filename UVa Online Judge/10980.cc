/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10980.cc
#  Description:     UVa 10980
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<dd> vdd;

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;

const int MAX_ITEMS = 105;
double dp[MAX_ITEMS];
bool visited[MAX_ITEMS];
vd prices;
vi n_items;

double f(int k) {
    if (k <= 0) return 0.0;

    if (visited[k]) return dp[k];
    visited[k] = true;

    double ans = 1e9;
    for (int i = 0; i < prices.size(); i++) {
        ans = min(ans, f(k - n_items[i]) + prices[i]);
    }
    return dp[k] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_case = 0;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);

        double price;
        int M;
        iss >> price >> M;

        prices.clear();
        n_items.clear();
        prices.push_back(price);
        n_items.push_back(1);

        for (int i = 1; i <= M; i++) {
            int n_item;
            getline(cin, line);
            iss.clear();
            iss.str(line);
            iss >> n_item >> price;
            prices.push_back(price);
            n_items.push_back(n_item);
        }

        cout << "Case " << ++n_case << ":" << endl;
        memset(visited, 0, sizeof(visited));

        getline(cin, line);
        iss.clear();
        iss.str(line);
        string token;
        while (getline(iss, token, ' ')) {
            int num = stoi(token);
            cout << "Buy " << num << " for $" << fixed << setprecision(2)
                 << f(num) << endl;
        }
    }
    return 0;
}