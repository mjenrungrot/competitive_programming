import sys
import math


if __name__ == '__main__':
    counter = 1
    while True:
        N, *A = list(map(int, input().split()))
        if N == 0:
            break

        print("Case {}:".format(counter))
        counter += 1

        numerator = sum(A)
        denominator = N
        negative = numerator < 0
        numerator = abs(numerator)

        if numerator % denominator == 0:
            if negative: print("- ", end="")
            print(numerator // denominator)
            continue

        gg = math.gcd(numerator, denominator)
        numerator //= gg
        denominator //= gg

        n = numerator // denominator
        rem = numerator % denominator

        if n:
            n_digit = len(str(n))
        else:
            n_digit = 0
        rem_digit = len(str(rem))
        denominator_digit = len(str(denominator))

        top_space = n_digit + max(rem_digit, denominator_digit) - rem_digit
        bottom_space = n_digit + max(rem_digit, denominator_digit) - denominator_digit

        if negative:
            top_space += 2
            bottom_space += 2

        print("{}{}".format(" " * top_space, rem))
        if negative: print("- ", end="")
        if n: print("{}".format(n), end="")
        print("-" * max(rem_digit, denominator_digit))
        print("{}{}".format(" " * bottom_space, denominator))