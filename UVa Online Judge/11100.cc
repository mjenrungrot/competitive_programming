/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11100.cc
#  Description:     UVa Online Judge - 11100
=============================================================================*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    bool space = false;
    while (cin >> N) {
        if (N == 0) break;

        vector<int> A(N), used(N);
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            A[i] = tmp;
        }

        sort(A.begin(), A.end());

        int n_bags = 0;
        int counter = 0, last = -1;
        for (int i = 0; i < N; i++) {
            if (A[i] == last)
                counter++;
            else
                counter = 1;
            n_bags = max(n_bags, counter);
            last = A[i];
        }

        int curr = 0;
        vector<vector<int> > bags(n_bags);
        for (int i = 0; i < N; i++) {
            bags[curr].push_back(A[i]);
            curr = (curr + 1) % n_bags;
        }

        if (space) cout << endl;
        space = true;

        cout << bags.size() << endl;
        for (auto bag : bags) {
            for (int i = 0; i < bag.size(); i++) {
                if (i) cout << " ";
                cout << bag[i];
            }
            cout << endl;
        }
    }
    return 0;
}