values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
sym_val_dict = dict(zip(symbols, values))

def toRoman(num):
    output = ""
    curr = 0
    while(num > 0):
        n_div = num // values[curr]
        num %= values[curr]
        output += "{}".format(symbols[curr]) * n_div
        curr += 1
    return output

def toInteger(string):
    output = 0
    i = 0
    while i < len(string):
        if i+1 < len(string) and string[i:i+2] in sym_val_dict:
            output += sym_val_dict[string[i:i+2]]
            i += 2
        else:
            output += sym_val_dict[string[i]]
            i += 1
    return output

if __name__ == '__main__':
    while True:
        try:
            line = input().strip()
        except EOFError:
            break

        val = toInteger(line)
        roman = toRoman(val)

        passed = True
        for i in range(3, len(roman)):
            if roman[i] == roman[i-1] == roman[i-2] == roman[i-3]:
                passed = False

        if not passed or roman != line:
            print("This is not a valid number")
        else:
            print(val)

