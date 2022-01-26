#include <bits/stdc++.h>
using namespace std;

/**
 * Suffix Array
 *
 * Source:  https://cp-algorithms.com/string/suffix-array.html
 */

/**
 * Construction O(n log n)
 *
 * Idea: Order by cyclic shift
 *
 * String: dabbb
 *      1: abbb$d       abbb
 *      4: b$dabb       b
 *      3: bb$dab       bb
 *      2: bbb$da       bbb
 *      0: dabbb$       dabbb
 *
 * Algorithm: We sort the n cyclic substrings of s of length 2^k for
 *  ceil(log n) + 1 iterations,
 *
 * p[i] = the index of the i-th substring (starting at i with length 2^k)
 * c[i] = equivalence class to which the substring belongs
 */
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;

    // 0-th iteration, sort cyclic of length 1
    // counting sort
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) classes++;
        c[p[i]] = classes - 1;
    }

    // iteration step: to compare two substrings of length 2^k starting at i and
    // j we need to know (c[i], c[i+2^(k-1)]) and (c[j], c[j+2^(k-1)])
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev) ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

/**
 * Finding the smallest cyclic shift
 *
 * Sol: p[0]
 */

/**
 * Finding a substring in a string
 *
 * Sol: binary search on prefix
 */

int main() {
    auto sa = suffix_array_construction("aaba");
    assert(sa == vector<int>({3, 0, 1, 2}));
    return 0;
}