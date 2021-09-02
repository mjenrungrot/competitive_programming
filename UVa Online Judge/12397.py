# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12397.py
#  Description:     UVa Online Judge - 12397
# =============================================================================

values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
sym_val_dict = dict(zip(symbols, values))


def toRoman(num):
    output = ""
    curr = 0
    while num > 0:
        n_div = num // values[curr]
        num %= values[curr]
        output += "{}".format(symbols[curr]) * n_div
        curr += 1
    return output


def toInteger(string):
    output = 0
    i = 0
    while i < len(string):
        if i + 1 < len(string) and string[i : i + 2] in sym_val_dict:
            output += sym_val_dict[string[i : i + 2]]
            i += 2
        else:
            output += sym_val_dict[string[i]]
            i += 1
    return output


if __name__ == "__main__":
    while True:
        try:
            line = input()
        except EOFError:
            break

        roman = toRoman(int(line))

        ans = 0
        for ch in roman:
            if ch == "I":
                ans += 1
            elif ch == "D":
                ans += 3
            elif ch == "M":
                ans += 4
            else:
                ans += 2
        print(ans)
