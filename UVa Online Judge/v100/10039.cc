/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10039.cc
#  Description:     UVa Online Judge - 10039
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
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

const int MAXN = 105;
const int MAXTIME = 1450;

map<string, int> to_idx;
string names[MAXN];
vector<vii> trains;
vector<ii> edges[MAXN];

int dp[MAXN][MAXTIME];
int backtrack[MAXN][MAXTIME];
int check[MAXN];
int best_arrival;

int f(int start, int tt, int target) {
    if (start == target) {
        return dp[start][tt] = tt;
    }
    if (tt >= best_arrival) return INF_INT;

    if (dp[start][tt] != -1) return dp[start][tt];

    int ans = INF_INT;
    int best_leave = -1;
    for (auto edge : edges[start]) {
        int curr_train = edge.first;
        int curr_station = edge.second;
        int curr_time = trains[curr_train][curr_station].first;

        if (curr_time < tt) continue;
        for (int j = curr_station + 1; j < trains[curr_train].size(); j++) {
            int leave_time = curr_time;
            int val = f(trains[curr_train][j].second,
                        trains[curr_train][j].first, target);
            if (val < ans) {
                ans = val;
                best_leave = leave_time;
            } else if (val == ans and leave_time > best_leave) {
                best_leave = leave_time;
            }
            dp[start][tt] = max(dp[start][tt], ans);
        }
    }

    backtrack[start][tt] = best_leave;
    best_arrival = min(best_arrival, ans);
    return dp[start][tt] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n_test = 0;
    cin >> T;
    while (T--) {
        cout << "Scenario " << ++n_test << endl;

        int N;
        cin >> N;
        to_idx.clear();
        for (int i = 0; i < N; i++) {
            cin >> names[i];
            to_idx[names[i]] = i;
            edges[i].clear();
        }

        int M;
        cin >> M;
        trains.clear();
        for (int i = 0; i < M; i++) {
            vii train;

            int n_station;
            cin >> n_station;
            while (n_station--) {
                int tt;
                string name;
                cin >> tt >> name;
                tt = (tt / 100) * 60 + (tt % 100);
                train.push_back(ii(tt, to_idx[name]));
            }
            sort(train.begin(), train.end(),
                 [](ii x, ii y) { return x.first < y.first; });

            trains.push_back(train);

            for (int j = 0; j < train.size(); j++) {
                // (train_idx, station_idx)
                edges[train[j].second].push_back(ii(i, j));
            }
        }

        int start_time;
        string start_name, target_name;
        cin >> start_time >> start_name >> target_name;
        start_time = (start_time / 100) * 60 + start_time % 100;

        int start = to_idx[start_name];
        int target = to_idx[target_name];

        memset(dp, -1, sizeof(dp));
        best_arrival = INF_INT;
        int arrival = f(start, start_time, target);
        int leave_time = backtrack[start][start_time];

        arrival = (arrival / 60) * 100 + arrival % 60;
        leave_time = (leave_time / 60) * 100 + leave_time % 60;

        if (arrival > 24 * 60) {
            cout << "No connection" << endl;
            cout << endl;
        } else {
            cout << "Departure " << setfill('0') << setw(4) << leave_time << " "
                 << start_name << endl;
            cout << "Arrival   " << setfill('0') << setw(4) << arrival << " "
                 << target_name << endl;
            cout << endl;
        }
    }

    return 0;
}