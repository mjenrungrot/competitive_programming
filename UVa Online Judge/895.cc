/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        895.cc
#  Description:     UVa Online Judge - 895
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

int n_word;
int freq[1005][30], freq_query[30];
string line, token;

int main() {
    while (getline(cin, line)) {
        if (line == "#") break;
        n_word++;
        int length = line.length();
        for (int i = 0; i < length; i++) freq[n_word][line[i] - 'a']++;
    }

    while (getline(cin, line)) {
        if (line == "#") break;
        memset(freq_query, 0, sizeof(freq_query));
        istringstream tokenStream(line);
        while (getline(tokenStream, token, ' ')) {
            freq_query[token[0] - 'a']++;
        }

        int ans = 0;
        for (int i = 1; i <= n_word; i++) {
            bool pass = true;
            for (int j = 0; j < 26 && pass; j++)
                if (freq_query[j] < freq[i][j]) pass = false;
            if (pass) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}