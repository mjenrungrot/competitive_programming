#include <bits/stdc++.h>
using namespace std;

long long compute_hash(string const& s, const int p = 31,
                       const int m = 1e9 + 9) {
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

/**
 * Search for duplicate strings in an array of strings
 *
 * Problem: Given a list of n strings s_i, each no longer than m characters,
 * find all the duplicate strings and divide them into groups.
 *
 * Sorting: O(nm log n) [O(m) per comparison]
 * Hash: O(nm + n log n)
 */
vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++) hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 or hashes[i].first != hashes[i - 1].first) {
            groups.emplace_back();
        }
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

/**
 * Fast hash calculation of substrings of given string
 *
 * Problem: Given a string s and indices i and j, find the hash of the substring
 * s[i..j].
 *
 *  hash(s[i..j]) * p^i = [ hash(s[0..j]) - hash(s[0..(i-1)]) ] % m
 *
 *  Computing hash(s[i..j]) requries multiplicative inverse of p^i mod m
 */

/**
 * Determine the number of different substrings in a string
 *
 * Problem: Given a string s of length n, consisting only of lowercase English
 * letters, find the number of different substrings in this string.
 *
 */
int count_unique_substrings(string const& s) {
    int n = s.size();
    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; ++i) p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; ++i)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; ++l) {
        set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n - i - 1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}

int main() {
    auto hash = compute_hash("asedf", 31, 1e9 + 9);
    assert(hash == 5665685);

    auto identical =
        group_identical_strings({"aaaa", "bb", "aaaa", "bc", "bb"});
    assert(identical == vector<vector<int>>({{1, 4}, {3}, {0, 2}}));

    auto n = count_unique_substrings("aaba");
    assert(n == 8);  // a, b, aa, ab, ba, aab, aba, aaba

    return 0;
}