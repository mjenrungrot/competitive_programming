#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
const int INF = 1e9 + 7;
const int MAXLIMIT = 100005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<ii>> V(N + 1);
        vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

        for (int i = 1; i <= M; i++) {
            int u, v, cost;
            cin >> u >> v >> cost;
            V[u].push_back(ii(v, cost));
            V[v].push_back(ii(u, cost));
            dist[u][v] = dist[v][u] = cost;
        }
        for (int i = 1; i <= N; i++) dist[i][i] = 0;

        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }

        int n_questions;
        cin >> n_questions;
        while (n_questions--) {
            int source, target, cost;
            cin >> source >> target >> cost;

            // Find node before v
            vector<bool> visited(N + 1);
            vector<int> parent(N + 1, -1);
            queue<iii> Q;
            Q.push(iii(ii(source, 0), 0));
            parent[source] = -1;

            int node_before_target = -1, n_steps_to_before_target = -1;
            vector<int> accessible_nodes;

            while (not Q.empty()) {
                iii u = Q.front();
                Q.pop();

                if (u.first.first == target) {
                    node_before_target = 1;
                    n_steps_to_before_target = 0;
                    break;
                }
                if (visited[u.first.first]) continue;
                visited[u.first.first] = true;
                accessible_nodes.push_back(u.first.first);

                for (auto v : V[u.first.first]) {
                    if (visited[v.first]) continue;
                    if (v.first == target) {
                        node_before_target = u.first.first;
                        n_steps_to_before_target = u.second;
                        break;
                    }
                    parent[v.first] = u.first.first;
                    Q.push(iii(ii(v.first, u.first.second + v.second),
                               u.second + 1));
                }
                if (node_before_target != -1) break;
            }
            cost -= dist[source][target];

            vector<long long> dp(MAXLIMIT, INF);
            dp[0] = n_steps_to_before_target + 1;

            int curr = node_before_target;
            while (parent[curr] != -1) {
                int denominator = dist[parent[curr]][curr] * 2;
                for (int j = denominator; j < MAXLIMIT; j++) {
                    dp[j] = min(dp[j], dp[j - denominator] + 2);
                }
                curr = parent[curr];
            }

            if (cost < 0 or dp[cost] == INF) {
                cout << "No" << endl;
            } else {
                cout << "Yes " << dp[cost] << endl;
            }
        }
        if (T) cout << endl;
    }
    return 0;
}