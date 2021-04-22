/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11423.cc
#  Description:     UVa Online Judge - 11423
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int MAXN = 1e7 + 10;
const int INF = 1e9 + 7;

int fw_data[MAXN] = {};
void add(int x, int val) {
    for (; x < MAXN; x += x & -x) fw_data[x] += val;
}
int query(int x) {
    int sum = 0;
    for (; x > 0; x -= x & -x) sum += fw_data[x];
    return sum;
}

int N;
int caches[35];
int misses[35];
string command;
int params[10];
map<int, int> vis;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> caches[i];

    // init
    queue<ii> Q;
    int fw_counter = 1;  // prevent 0-index
    int queue_counter = 1;

    while (cin >> command) {
        if (command == "END") break;

        if (command == "RANGE") {
            cin >> params[0] >> params[1] >> params[2];
            for (int i = 0, curr = params[0]; i < params[2];
                 i++, curr += params[1]) {
                int prev_loc = (vis.count(curr) ? vis[curr] : 0);
                Q.push(ii(curr, prev_loc));
                vis[curr] = queue_counter++;
            }
        } else if (command == "ADDR") {
            cin >> params[0];
            int curr = params[0];
            int prev_loc = (vis.count(curr) ? vis[curr] : 0);
            Q.push(ii(curr, prev_loc));
            vis[curr] = queue_counter++;
        } else if (command == "STAT") {
            memset(misses, 0, sizeof(misses));
            while (not Q.empty()) {
                ii front = Q.front();
                Q.pop();
                add(fw_counter, 1);  // add Q.front().first to the cache

                int dist;
                if (front.second <= 0)
                    dist = INF;
                else
                    dist = query(fw_counter) -
                           query(front.second);  // if dist >= cache_size, it
                                                 // will miss.

                for (int i = 1; i <= N; i++) {
                    if (dist > caches[i])
                        misses[i]++;
                    else
                        break;
                }
                if (front.second > 0) add(front.second, -1);
                fw_counter++;
            }
            for (int i = 1; i <= N; i++)
                cout << (i > 1 ? " " : "") << misses[i];
            cout << endl;
        }
    }
    return 0;
}