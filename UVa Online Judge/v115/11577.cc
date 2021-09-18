/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11577.cc
#  Description:     UVa Online Judge - 11577
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int freq[30];
string line;

int main() {
    int T;
    getline(cin, line);
    T = atoi(line.c_str());
    for (int i = 1; i <= T; i++) {
        getline(cin, line);

        int length = line.length();
        int max_freq = -1;
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < length; i++) {
            if (isalpha(line[i])) {
                freq[tolower(line[i]) - 'a']++;
                max_freq = max(max_freq, freq[tolower(line[i]) - 'a']);
            }
        }

        for (int i = 0; i < 26; i++)
            if (freq[i] == max_freq) printf("%c", 'a' + i);
        printf("\n");
    }
    return 0;
}