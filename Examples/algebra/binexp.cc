#include <bits/stdc++.h>
using namespace std;

// Binary Exponentiation
//
// Time: O(log(N))
// Space: O(1)
//
// See:
//  - https://cp-algorithms.com/algebra/euclid-algorithm.html
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
//
template <class T>
inline T binexp(
    T const& a, uint64_t n, T const& id,
    function<T(T const& lhs, T const& rhs)> const& op = multiplies<T>()) {
    auto ans = id;
    auto p = a;
    while (n > 0) {
        if (n & 1) ans = op(ans, p);
        p = op(p, p);
        n >>= 1;
    }
    return ans;
}

int main() {
    // power
    int64_t a1 = 13230125;
    int b1 = 2;
    auto ans1 = binexp<int64_t>(a1, b1, 1);
    cout << ans1 << endl;

    // power-mod
    int64_t a2 = 13230125;
    int b2 = 123123;
    auto ans2 =
        binexp<int64_t>(a2, b2, 1, [&](const int64_t& lhs, const int64_t& rhs) {
            return (lhs * rhs) % 1000000007;
        });
    cout << ans2 << endl;

    // mul-mod
    int64_t a3 = 13230125;
    int64_t b3 = 123123;
    auto ans3 =
        binexp<int64_t>(a3, b3, 0, [&](const int64_t& lhs, const int64_t& rhs) {
            return (lhs + rhs) % 1000000007;
        });
    cout << ans3 << endl;

    // fibonacci
    using vec = vector<int64_t>;
    using mat = vector<vec>;
    auto id = [=](int N) {
        mat ans(N, vec(N, 0));
        for (int i = 0; i < N; ++i) ans[i][i] = 1;
        return ans;
    };
    auto mul = [&](const mat& lhs, const mat& rhs) {
        const int N = lhs.size(), M = rhs.size();
        mat ans(N, vec(N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < M; ++k) {
                    ans[i][j] += lhs[i][k] * rhs[k][j];
                }
            }
        }
        return ans;
    };
    mat a4 = {{0, 1}, {1, 1}};
    int n = 10;
    mat f = binexp<mat>(a4, n - 2, id(a4.size()), mul);
    mat b = mul(f, mat{{1}, {1}});
    auto ans4 = b[1][0];
    cout << ans4 << endl;

    return 0;
}