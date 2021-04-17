#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> dd;

const double INF = 1e9;
const int MAXN = 10;
const int MAXMASK = (1 << 10) + 5;

vector<dd> A;
bool visited[MAXN][MAXMASK];
double memo[MAXN][MAXMASK];
int next_val[MAXN][MAXMASK];

double dist(dd x, dd y) {
    return sqrt((x.first - y.first) * (x.first - y.first) +
                (x.second - y.second) * (x.second - y.second));
}

double dp(int curr, int mask) {
    if (mask == 0) return 0.0;
    if (visited[curr][mask]) return memo[curr][mask];

    double ans = INF, best_next = -1;
    int curr_mask = mask;
    while (curr_mask) {
        int v = __builtin_ctz(curr_mask & -curr_mask);
        double d = dist(A[curr], A[v]) + 16.0;

        double subprob = d + dp(v, mask - (1 << v));
        if (subprob < ans) {
            ans = subprob;
            best_next = v;
        }
        curr_mask -= (1 << v);
    }

    next_val[curr][mask] = best_next;
    visited[curr][mask] = true;
    return memo[curr][mask] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, n_case = 0;
    while (cin >> N) {
        if (N == 0) break;

        A.clear();
        for (int i = 0; i < N; i++) {
            double tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            A.push_back(dd(tmp1, tmp2));
        }

        int best_start = -1;
        double best_ans = INF;
        for (int i = 0; i < N; i++) {
            memset(visited, 0, sizeof(visited));
            double val = dp(i, (1 << N) - 1 - (1 << i));

            if (val < best_ans) {
                best_ans = val;
                best_start = i;
            }
        }
        double ans = dp(best_start, (1 << N) - 1 - (1 << best_start));

        cout << "**********************************************************"
             << endl;
        cout << "Network #" << ++n_case << endl;

        int curr = best_start, curr_mask = (1 << N) - 1 - (1 << best_start);
        for (int i = 1; i <= N - 1; i++) {
            int next_pos = next_val[curr][curr_mask];

            cout << "Cable requirement to connect ";
            cout << "(" << fixed << setprecision(0) << A[curr].first << ","
                 << fixed << setprecision(0) << A[curr].second << ")";
            cout << " to ";
            cout << "(" << fixed << setprecision(0) << A[next_pos].first << ","
                 << fixed << setprecision(0) << A[next_pos].second << ")";
            cout << " is " << fixed << setprecision(2)
                 << dist(A[curr], A[next_pos]) + 16.0 << " feet." << endl;

            curr = next_pos;
            curr_mask -= (1 << next_pos);
        }

        cout << "Number of feet of cable required is " << fixed
             << setprecision(2) << ans << "." << endl;
    }
    return 0;
}