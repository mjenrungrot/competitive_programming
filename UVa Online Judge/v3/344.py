# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        344.py
#  Description:     UVa Online Judge - 344
# =============================================================================


def toRoman(num):
    output = ""
    while num > 0:
        if num >= 100:
            num -= 100
            output += "c"
        elif num >= 90:
            num -= 90
            output += "xc"
        elif num >= 50:
            num -= 50
            output += "l"
        elif num >= 40:
            num -= 40
            output += "xl"
        elif num >= 10:
            num -= 10
            output += "x"
        elif num >= 9:
            num -= 9
            output += "ix"
        elif num >= 5:
            num -= 5
            output += "v"
        elif num >= 4:
            num -= 4
            output += "iv"
        elif num >= 1:
            num -= 1
            output += "i"
    return output


if __name__ == "__main__":
    while True:
        N = int(input())
        if N == 0:
            break

        keys = list("ivxlc")
        values = [0 for i in range(len(keys))]
        counter = dict(zip(keys, values))

        for i in range(1, N + 1):
            roman = toRoman(i)
            for ch in roman:
                counter[ch] += 1

        print(
            "{}: {} i, {} v, {} x, {} l, {} c".format(
                N, counter["i"], counter["v"], counter["x"], counter["l"], counter["c"]
            )
        )
