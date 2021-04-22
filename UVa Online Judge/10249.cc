/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10249.cc
#  Description:     UVa Online Judge - 10249
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n_teams, n_tables;
    while (cin >> n_teams >> n_tables) {
        if (n_teams == 0 and n_tables == 0) break;

        vector<ii> teams, tables;
        vector<int> fills;
        for (int i = 0; i < n_teams; i++) {
            int tmp;
            cin >> tmp;
            teams.push_back(ii(tmp, i + 1));
        }
        for (int i = 0; i < n_tables; i++) {
            int tmp;
            cin >> tmp;
            tables.push_back(ii(tmp, i + 1));
            fills.push_back(0);
        }

        auto cmp = [](ii a, ii b) { return a.first > b.first; };
        sort(teams.begin(), teams.end(), cmp);
        sort(tables.begin(), tables.end(), cmp);

        bool possible = true;
        int curr_table = 0;
        vector<int> assignments[100];
        for (int i = 0; i < n_teams and possible; i++) {
            int start_table = curr_table;
            for (int j = 1; j <= teams[i].first and possible; j++) {
                while (fills[curr_table] == tables[curr_table].first) {
                    curr_table = (curr_table + 1) % n_tables;
                    if (curr_table == start_table) {
                        possible = false;
                        break;
                    }
                }
                if (not possible) break;

                if (fills[curr_table] < tables[curr_table].first) {
                    assignments[teams[i].second].push_back(
                        tables[curr_table].second);
                    // cout << "assign " << teams[i].second << " to table " <<
                    // tables[curr_table].second << endl;

                    fills[curr_table]++;
                    curr_table = (curr_table + 1) % n_tables;
                }
                if (j < teams[i].first and curr_table == start_table) {
                    possible = false;
                }
            }
        }

        if (possible) {
            cout << 1 << endl;
            for (int i = 1; i <= n_teams; i++) {
                for (int j = 0; j < assignments[i].size(); j++) {
                    if (j) cout << " ";
                    cout << assignments[i][j];
                }
                cout << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}