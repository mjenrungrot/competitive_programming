/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        1281.cc
#  Description:     UVa Online Judge - 1281
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

const int MAXN = 20;
const int MAXMASK = (1 << 18) + 5;
const int INF = 1e9;

int N, M, dist[MAXN][MAXN];
long long dp1[MAXN][MAXMASK];  // (n, mask) ==> visiting all in mask and
                               // starting/ending at n, then go to HQ
long long dp2[MAXN][MAXMASK];  // (n, mask) ==> visiting all in mask and
                               // starting/ending at n, then go to attraction

long long f1(int curr, int mask) {
    if (mask == 0) return dist[curr][0];
    if (dp1[curr][mask] != -1) return dp1[curr][mask];

    long long ans = INF_LL;
    int curr_mask = mask;
    while (curr_mask) {
        int last_bit = curr_mask & -curr_mask;
        int last_bit_pos = __builtin_ctz(last_bit) + 1;
        ans = min(ans,
                  dist[curr][last_bit_pos] + f1(last_bit_pos, mask - last_bit));
        curr_mask -= last_bit;
    }

    return dp1[curr][mask] = ans;
}

long long f2(int curr, int mask) {
    if (mask == 0) return dist[curr][N - 1];
    if (dp2[curr][mask] != -1) return dp2[curr][mask];

    long long ans = INF_LL;
    int curr_mask = mask;
    while (curr_mask) {
        int last_bit = curr_mask & -curr_mask;
        int last_bit_pos = __builtin_ctz(last_bit) + 1;
        ans = min(ans,
                  dist[curr][last_bit_pos] + f2(last_bit_pos, mask - last_bit));
        curr_mask -= last_bit;
    }

    return dp2[curr][mask] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_case = 0;
    while (cin >> N >> M) {
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) {
                dist[i][j] = (i == j) ? 0 : INF;
            }

        for (int i = 1; i <= M; i++) {
            int u, v, cost;
            cin >> u >> v >> cost;
            dist[u][v] = dist[v][u] = cost;
        }

        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }

        long long ans = -1;
        if (N == 3) {
            ans = dist[0][1] + dist[1][2] + dist[2][1] + dist[1][0];
        } else {
            memset(dp1, -1, sizeof(dp1));
            memset(dp2, -1, sizeof(dp2));

            vector<int> all_group1_masks, all_group2_masks;
            for (int i = 0; i < (1 << (N - 2)); i++) {
                if (__builtin_popcount(i) == (N - 2) / 2) {
                    all_group1_masks.push_back(i);
                }
                if (__builtin_popcount(i) == (N - 2) - (N - 2) / 2) {
                    all_group2_masks.push_back(i);
                }
            }

            for (auto mask : all_group1_masks) {
                int curr_mask = mask;
                while (curr_mask) {
                    int last_bit = curr_mask & -curr_mask;
                    int last_bit_pos = __builtin_ctz(last_bit) + 1;
                    dp1[last_bit_pos][mask] = f1(last_bit_pos, mask - last_bit);
                    dp2[last_bit_pos][mask] = f2(last_bit_pos, mask - last_bit);
                    curr_mask -= last_bit;
                }
            }
            for (auto mask : all_group2_masks) {
                int curr_mask = mask;
                while (curr_mask) {
                    int last_bit = curr_mask & -curr_mask;
                    int last_bit_pos = __builtin_ctz(last_bit) + 1;
                    dp1[last_bit_pos][mask] = f1(last_bit_pos, mask - last_bit);
                    dp2[last_bit_pos][mask] = f2(last_bit_pos, mask - last_bit);
                    curr_mask -= last_bit;
                }
            }

            const int all_bits = (1 << (N - 2)) - 1;
            ans = INF_LL;
            for (auto mask : all_group1_masks) {
                int group1 = mask;
                int group2 = all_bits - mask;

                long long cost_trip1 = INF_LL, cost_trip2 = INF_LL;
                for (int pos1 = group1; pos1; pos1 -= pos1 & -pos1) {
                    for (int pos2 = group2; pos2; pos2 -= pos2 & -pos2) {
                        int p1 = __builtin_ctz(pos1) + 1;
                        int p2 = __builtin_ctz(pos2) + 1;

                        // HQ -> (group1 -> p1) -> (p2 -> group2) -> Destt
                        cost_trip1 =
                            min(cost_trip1, dp1[p1][group1] + dist[p1][p2] +
                                                dp2[p2][group2]);

                        // Dest -> (group1 -> p1) -> (p2 -> group2) -> HQ
                        cost_trip2 =
                            min(cost_trip2, dp2[p1][group1] + dist[p1][p2] +
                                                dp1[p2][group2]);
                    }
                }
                ans = min(ans, cost_trip1 + cost_trip2);
            }
        }
        cout << "Case " << ++n_case << ": " << ans << endl;
    }
    return 0;
}