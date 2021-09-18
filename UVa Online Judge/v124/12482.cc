/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12482.cc
#  Description:     UVa Online Judge - 12482
=============================================================================*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, L, C;
    while (cin >> N >> L >> C) {
        int curr_page = 1;
        int curr_line = 1;
        int curr_characters = 0;

        for (int i = 0; i < N; i++) {
            string word;
            cin >> word;

            if (curr_characters == 0) {
                curr_characters += word.length();
            } else {
                if (curr_characters + 1 + word.length() <= C) {
                    curr_characters += 1 + word.length();
                } else {
                    curr_characters = word.length();
                    curr_line++;
                    if (curr_line > L) {
                        curr_line = 1;
                        curr_page++;
                    }
                }
            }
        }
        cout << curr_page << endl;
    }
    return 0;
}