/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        603.cpp
#  Description:     UVa Online Judge - 603
=============================================================================*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
vector<ii> move(vector<ii> now) {
    vector<ii> ans;
    for (int i = 0; i < now.size(); i++) {
        int next = now[i].first;
        next = (next < 20) ? (next + 1) : 1;
        ans.push_back(ii(next, now[i].second));
    }
    return ans;
}

char str[100];
int answer[30];
vector<ii> car;
vector<int> initial;

void print(vector<ii> now) {
    for (int i = 0; i < now.size(); i++) printf("[%d]", now[i].first);
    printf("\n");
}

int main() {
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    fgets(str, sizeof(str), stdin);
    fgets(str, sizeof(str), stdin);
    bool line = false;
    while (T--) {
        if (line) printf("\n");
        line = true;

        car.clear();
        initial.clear();
        while (fgets(str, sizeof(str), stdin)) {
            if (str[0] == '\n' or str[0] == ' ') break;
            int val = atoi(str);
            if (val == 99) break;
            car.push_back(ii(val, val));
            initial.push_back(val);
        }
        memset(answer, -1, sizeof answer);
        int now = 0;
        while (fgets(str, sizeof(str), stdin)) {
            if (str[0] == '\n' or str[0] == ' ') break;
            int val = atoi(str);
            now++;
            if (now > (int)initial.size()) continue;

            bool found = false;
            while (true) {
                for (int i = 0; i < car.size(); i++)
                    if (answer[car[i].second] == -1 and car[i].first == val) {
                        answer[car[i].second] = val;
                        found = true;
                        break;
                    }
                if (found) break;
                car = move(car);
                // print(car);
            }
        }
        for (int i = 0; i < initial.size(); i++) {
            if (answer[initial[i]] == -1)
                printf("Original position %d did not park\n", initial[i]);
            else
                printf("Original position %d parked in %d\n", initial[i],
                       answer[initial[i]]);
        }
    }
    return 0;
}