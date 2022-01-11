/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10238.cc
#  Description:     UVa Online Judge - 10238
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef tuple<long long, long long, long long> lll;
typedef tuple<double, double, double> ddd;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<dd> vdd;

// Debug Snippets

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V>& x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T& x) {
    int f = 0;
    cerr << '{';
    for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)

template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << " ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "[ " << p.first << ", " << p.second << "]";
}

// End Debug Snippets

vs split(string line) {
    vs output;
    istringstream iss(line);
    string tmp;
    while (iss >> tmp) {
        output.push_back(tmp);
    }
    return output;
}

vs split(string line, regex re) {
    vs output;
    sregex_token_iterator it(line.begin(), line.end(), re, -1), it_end;
    while (it != it_end) {
        output.push_back(it->str());
        it++;
    }
    return output;
}

namespace bignum {

class bignum {
   private:
    const int base = 1000 * 1000 * 1000;
    vector<int> a;

   public:
    bignum() {
        a.clear();
        a.resize(1, 0);
    }

    bignum(int n) {
        a.clear();
        a.resize(n, 0);
    }

    bignum(string num) {
        a.clear();

        for (int i = (int)num.length(); i > 0; i -= 9) {
            if (i < 9)
                a.push_back(atoi(num.substr(0, i).c_str()));
            else
                a.push_back(atoi(num.substr(i - 9, 9).c_str()));
        }

        while (a.size() > 1 && a.back() == 0) a.pop_back();
    }

    bignum& operator=(const bignum& other) {
        this->a = other.a;
        return *this;
    }

    bignum operator+(const bignum& other) {
        bignum c = *this;
        c += other;
        return c;
    }

    bignum& operator+=(const bignum& other) {
        int carry = 0;
        for (size_t i = 0; i < max(this->a.size(), other.a.size()) || carry;
             ++i) {
            if (i == (this->a).size()) (this->a).push_back(0);
            (this->a[i]) += carry + (i < other.a.size() ? other.a[i] : 0);
            carry = (this->a[i]) >= base;
            if (carry) (this->a[i]) -= base;
        }
        return *this;
    }

    bignum operator-(const bignum& other) {
        bignum c = *this;
        c -= other;
        return c;
    }

    bignum& operator-=(const bignum& other) {
        // results must be >= 0
        int carry = 0;
        for (size_t i = 0; i < other.a.size() || carry; ++i) {
            (this->a[i]) -= carry + (i < other.a.size() ? other.a[i] : 0);
            carry = (this->a[i]) < 0;
            if (carry) (this->a[i]) += base;
        }
        while ((this->a).size() > 1 && (this->a).back() == 0)
            (this->a).pop_back();
        return *this;
    }

    bignum operator*(const bignum& other) {
        bignum c(this->a.size() + other.a.size());
        for (size_t i = 0; i < this->a.size(); ++i)
            for (int j = 0, carry = 0; j < (int)other.a.size() || carry; ++j) {
                long long cur = c.a[i + j] +
                                this->a[i] * 1ll *
                                    (j < (int)other.a.size() ? other.a[j] : 0) +
                                carry;
                c.a[i + j] = int(cur % base);
                carry = int(cur / base);
            }
        while (c.a.size() > 1 && c.a.back() == 0) c.a.pop_back();
        return c;
    }

    bignum& operator*=(int other) {
        int carry = 0;
        for (size_t i = 0; i < this->a.size() || carry; ++i) {
            if (i == this->a.size()) this->a.push_back(0);
            long long cur = carry + this->a[i] * 1ll * other;
            this->a[i] = int(cur % base);
            carry = int(cur / base);
        }
        while (this->a.size() > 1 && this->a.back() == 0) this->a.pop_back();
        return *this;
    }

    bignum operator/(int other) {
        bignum c = *this;
        c /= other;
        return c;
    }

    bignum& operator/=(int other) {
        int carry = 0;
        for (int i = (int)this->a.size() - 1; i >= 0; --i) {
            long long cur = this->a[i] + carry * 1ll * base;
            this->a[i] = int(cur / other);
            carry = int(cur % other);
        }
        while (this->a.size() > 1 && this->a.back() == 0) this->a.pop_back();
        return *this;
    }

    int operator%(int other) {
        bignum c = *this;
        int carry = 0;
        for (int i = (int)c.a.size() - 1; i >= 0; --i) {
            long long cur = c.a[i] + carry * 1ll * base;
            c.a[i] = int(cur / other);
            carry = int(cur % other);
        }
        return carry;
    }

    friend ostream& operator<<(ostream& out, const bignum& c);
};

ostream& operator<<(ostream& out, const bignum& c) {
    out << (c.a.empty() ? 0 : c.a.back());
    for (int i = (int)c.a.size() - 2; i >= 0; i--) {
        out << setfill('0') << setw(9) << c.a[i];
    }
    return out;
}

};  // namespace bignum

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;
const int MAXN = 52;
const int MAXS = 4002;
int F, N, S;
bool done[MAXN][MAXS];
bignum::bignum memo[MAXN][MAXS];

bignum::bignum f(int n, int s) {
    if (n == 0) {
        if (s == 0)
            return bignum::bignum("1");
        else
            return bignum::bignum("0");
    }

    if (done[n][s]) return memo[n][s];

    bignum::bignum ans("0");
    for (int i = 1; i <= F; i++) {
        if (s - i < 0) continue;
        ans += f(n - 1, s - i);
    }

    done[n][s] = true;
    return memo[n][s] = ans;
}

void solve() {
    memset(done, false, sizeof(done));
    bignum::bignum ans = f(N, S);

    bignum::bignum denominator("1");
    for (int i = 1; i <= N; i++) denominator *= F;

    cout << ans << "/" << denominator << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> F >> N >> S) solve();

    return 0;
}