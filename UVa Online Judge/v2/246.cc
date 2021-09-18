/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        246.cc
#  Description:     UVa Online Judge - 246
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

struct state {
    int v[100];
    state() { memset(v, 0, sizeof(v)); }
    bool operator<(const state &x) const {
        return memcmp(v, x.v, sizeof(state)) < 0;
    }
};

deque<int> pile[7];
queue<int> hand;
set<state> record;
int x;

void reduce(deque<int> &nums) {
    while (nums.size() >= 3) {
        int n = nums.size();
        int front1 = nums[0];
        int front2 = nums[1];
        int back1 = nums[n - 1];
        int back2 = nums[n - 2];
        int back3 = nums[n - 3];

        if ((front1 + front2 + back1) % 10 == 0) {
            hand.push(front1), hand.push(front2), hand.push(back1);
            nums.pop_front(), nums.pop_front(), nums.pop_back();
        } else if ((front1 + back1 + back2) % 10 == 0) {
            hand.push(front1), hand.push(back2), hand.push(back1);
            nums.pop_front(), nums.pop_back(), nums.pop_back();
        } else if ((back1 + back2 + back3) % 10 == 0) {
            hand.push(back3), hand.push(back2), hand.push(back1);
            nums.pop_back(), nums.pop_back(), nums.pop_back();
        } else
            break;
    }
}

int main() {
    while (scanf("%d", &x) == 1) {
        if (x == 0) break;
        for (int i = 0; i < 7; i++) pile[i].clear();
        while (not hand.empty()) hand.pop();
        record.clear();

        hand.push(x);
        for (int i = 1; i <= 51; i++) {
            scanf("%d", &x);
            hand.push(x);
        }

        for (int i = 0; i < 7; i++) pile[i].push_back(hand.front()), hand.pop();
        for (int i = 0; i < 7; i++) pile[i].push_back(hand.front()), hand.pop();

        bool end = false;
        int n_cards = 14;
        while (not end) {
            for (int i = 0; i < 7; i++) {
                if (pile[i].size() == 0) continue;
                n_cards++;
                pile[i].push_back(hand.front()), hand.pop();
                reduce(pile[i]);
                if (hand.size() == 52) {
                    printf("Win : %d\n", n_cards);
                    end = true;
                    break;
                }
                if (hand.size() == 0) {
                    printf("Loss: %d\n", n_cards);
                    end = true;
                    break;
                }

                state s;
                int m = 0;
                for (int pile_no = 0; pile_no < 7; pile_no++) {
                    for (int k = 0; k < pile[pile_no].size(); k++)
                        s.v[m++] = pile[pile_no][k];
                    s.v[m++] = 15;
                }
                queue<int> q = hand;
                while (not q.empty()) {
                    s.v[m++] = q.front(), q.pop();
                }
                s.v[m++] = 15;

                if (record.find(s) != record.end()) {
                    printf("Draw: %d\n", n_cards);
                    end = true;
                    break;
                }
                record.insert(s);
            }
        }
    }
    return 0;
}