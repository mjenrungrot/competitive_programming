# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12143.py
#  Description:     UVa Online Judge - 12143
# =============================================================================
import math


class Frac:
    def __init__(self, a, b):
        self.a = a
        self.b = b
        self.reduce()

    def reduce(self):
        gg = math.gcd(self.a, self.b)
        self.a //= gg
        self.b //= gg

    def __add__(self, other):
        out_a = self.a * other.b + self.b * other.a
        out_b = self.b * other.b
        return Frac(out_a, out_b)

    def __sub__(self, other):
        out_a = self.a * other.b - self.b * other.a
        out_b = self.b * other.b
        return Frac(out_a, out_b)

    def __mul__(self, other):
        out_a = self.a * other.a
        out_b = self.b * other.b
        return Frac(out_a, out_b)

    def __floordiv__(self, other):
        out_a = self.a * other.b
        out_b = self.b * other.a
        return Frac(out_a, out_b)

    def __repr__(self):
        return "{}/{}".format(self.a, self.b)


def gauss(degree=11):
    A = [[0 for i in range(degree + 2)] for i in range(degree + 2)]
    for n in range(1, degree + 1):
        sum_val = 0
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                for k in range(1, n + 1):
                    for l in range(1, n + 1):
                        for m in range(1, n + 1):
                            sum_val += (
                                abs(i - j)
                                * abs(j - k)
                                * abs(k - l)
                                * abs(l - m)
                                * abs(m - i)
                            )
        A[n][degree + 1] = Frac(sum_val, 1)
        for i in range(1, degree + 1):
            A[n][i] = Frac(n ** (i - 1), 1)

    for i in range(1, degree + 1):
        k = i
        for j in range(i + 1, degree + 1):
            if A[j][i].a > A[k][i].a:
                k = j

        if A[k][i].a == 0:
            continue
        if k != i:
            for j in range(1, degree + 2):
                A[k][j], A[i][j] = A[i][j], A[k][j]

        for j in range(1, degree + 1):
            if i == j:
                continue
            for k in range(degree + 1, i - 1, -1):
                A[j][k] = A[j][k] - A[j][i] // A[i][i] * A[i][k]

    out = []
    for i in range(1, degree + 1):
        out.append(A[i][degree + 1] // A[i][i])
    return out


if __name__ == "__main__":
    out = gauss()

    while True:
        n = int(input())
        if n == 0:
            break
        ans = Frac(0, 1)
        for i, factor in enumerate(out):
            ans += Frac((n ** i), 1) * factor

        ans = ans.a // ans.b
        ans %= 10007
        print(ans)
