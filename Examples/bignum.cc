#include <bits/stdc++.h>
using namespace std;

namespace bignum {

class bignum {
   private:
    const int base = 1000 * 1000 * 1000;
    vector<int> a;

   public:
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

int main() {
    bignum::bignum num1 = bignum::bignum("555");
    ostringstream out1;
    out1 << num1;
    assert(out1.str() == "555");

    bignum::bignum num2 = bignum::bignum("413254523346877890132");
    ostringstream out2;
    out2 << num2;
    assert(out2.str() == "413254523346877890132");

    bignum::bignum num3 =
        bignum::bignum("00000000000000000000000413254523346877890132");
    ostringstream out3;
    out3 << num3;
    assert(out3.str() == "413254523346877890132");

    bignum::bignum num4_1 = bignum::bignum("2131233312312321312333123123");
    bignum::bignum num4_2 = bignum::bignum("568790569075806967894758954");
    ostringstream out4_add1, out4_add2, out4_add3;
    num4_1 += num4_2;
    out4_add1 << num4_1;
    out4_add2 << num4_2;
    out4_add3 << bignum::bignum("2131233312312321312333123123") +
                     bignum::bignum("568790569075806967894758954");
    assert(out4_add1.str() == "2700023881388128280227882077");
    assert(out4_add2.str() == "568790569075806967894758954");
    assert(out4_add3.str() == "2700023881388128280227882077");

    bignum::bignum num5_1 = bignum::bignum("2131233312312321312333123123");
    bignum::bignum num5_2 = bignum::bignum("2131233312312321312333123100");
    ostringstream out5_sub1, out5_sub2;
    num5_1 -= num5_2;
    out5_sub1 << num5_1;
    out5_sub2 << num5_2;
    assert(out5_sub1.str() == "23");
    assert(out5_sub2.str() == "2131233312312321312333123100");

    bignum::bignum num6_1 = bignum::bignum("2131233312312321312333123123");
    bignum::bignum num6_2 = bignum::bignum("568790569075806967894758954");
    ostringstream out6;
    out6 << num6_1 * num6_2;
    assert(out6.str() ==
           "1212225408543442280235484743350188683327290486088693342");

    bignum::bignum num7_1 = bignum::bignum("2131233312312321312333123123");
    int num7_2 = 30;
    ostringstream out7;
    num7_1 *= num7_2;
    out7 << num7_1;
    assert(out7.str() == "63936999369369639369993693690");

    bignum::bignum num8_1 = bignum::bignum("63936999369369639369993693690");
    int num8_2 = 30;
    ostringstream out8;
    num8_1 /= num8_2;
    out8 << num8_1;
    assert(out8.str() == "2131233312312321312333123123");

    bignum::bignum num9_1 = bignum::bignum("63936999369369639369993693690");
    int num9_2 = 30;
    ostringstream out9, out9_check;
    out9 << num9_1 / num9_2;
    out9_check << num9_1;
    assert(out9.str() == "2131233312312321312333123123");
    assert(out9_check.str() == "63936999369369639369993693690");

    bignum::bignum num10_1 = bignum::bignum("63936999369369639369993693690");
    int num10_2 = 30;
    ostringstream out10, out10_check;
    out10 << num10_1 % num10_2;
    out10_check << num10_1;
    assert(out10.str() == "0");
    assert(out10_check.str() == "63936999369369639369993693690");

    bignum::bignum num11_1 = bignum::bignum("63936999369369639369993693695");
    int num11_2 = 30;
    ostringstream out11;
    out11 << num11_1 % num11_2;
    assert(out11.str() == "5");
    
    return 0;
}