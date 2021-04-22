/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        860.cpp
#  Description:     UVa Online Judge - 860
=============================================================================*/
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

char str[1000];
string f(string ss) {
    for (int i = 0; i < ss.length(); i++) ss[i] = tolower(ss[i]);
    return ss;
}

int main() {
    // freopen("in","r",stdin);
    while (true) {
        int lambda = 0;
        map<string, int> M;
        string S;
        while (fgets(str, sizeof(str), stdin)) {
            if (str[0] == '*') break;

            char *p = strtok(str, " ,.:;!?\"()\n\t");
            while (p != NULL) {
                M[f(S = p)]++;
                lambda++;
                p = strtok(NULL, " ,.:;!?\"()\n\t");
            }
        }
        if (str[0] == '*' and str[11] == 'I') break;

        assert(lambda > 1);

        double val = 0.0;
        for (map<string, int>::iterator it = M.begin(); it != M.end(); it++) {
            double val1 = (double)(it->second);
            double val2 = log10((double)lambda) - log10((double)(it->second));
            val += val1 * val2;
            // printf("[%s] => [%d]\n",it->first.c_str(),it->second);
        }
        val /= (double)lambda;

        double percent = val / (double)log10(double(lambda)) * 100.0;
        printf("%d %.1lf %.0lf\n", lambda, val, percent);
    }
    return 0;
}