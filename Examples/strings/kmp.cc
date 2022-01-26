#include <bits/stdc++.h>
using namespace std;

/**
 * Source: https://cp-algorithms.com/string/prefix-function.html
 * Time: O(N)
 * Description: \texttt{f[i]} is length of the longest proper suffix
 * of the $i$-th prefix of $s$ that is a prefix of $s$
 */
vector<int> prefix_function(string s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

/**
 * Search for a substring in a string. The Knuth-Morris-Pratt algorithm
 *
 * Consider a string: s + # + t
 * Ignore the first n+1 characters. If at some position i we have pi[i] = n,
 * then at the position i in the combined string the string s appears.
 *
 * String ending at location i (s.t. i >= s.length() + 1) has an index of
 * i - (s.length() + 1) in the original t.
 */
vector<int> getOccurences(string a, string b) {  // find occurences of a in b
    vector<int> pi = prefix_function(a + "#" + b);
    vector<int> ret;
    for (int i = a.length() + 1; i < a.length() + b.length() + 1; i++) {
        if (pi[i] == a.length()) {
            ret.push_back(i - (a.length() + 1) - a.length() + 1);
        }
    }
    return ret;
}

int main() {
    vector<int> prefix1 = prefix_function("abcabcd");
    assert(prefix1 == vector<int>({0, 0, 0, 1, 2, 3, 0}));

    vector<int> prefix2 = prefix_function("aabaaab");
    assert(prefix2 == vector<int>({0, 1, 0, 1, 2, 2, 3}));

    vector<int> search1 = getOccurences("aba", "ababababac");
    vector<int> search2 = getOccurences("bab", "ababababac");
    assert(search1 == vector<int>({0, 2, 4, 6}));
    assert(search2 == vector<int>({1, 3, 5}));

    return 0;
}
