# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        327.py
#  Description:     UVa Online Judge - 327
# =============================================================================
def run(exp):
    print("Expression: {}".format(exp))
    exp = exp.replace(" ", "")

    values = {}
    for i in range(26):
        ch = chr(ord("a") + i)
        if "++{}".format(ch) in exp:
            values[ch] = (i + 1) + 1
            exp = exp.replace("++{}".format(ch), "{}".format(values[ch]))
        elif "--{}".format(ch) in exp:
            values[ch] = (i + 1) - 1
            exp = exp.replace("--{}".format(ch), "{}".format(values[ch]))
        elif "{}++".format(ch) in exp:
            values[ch] = (i + 1) + 1
            exp = exp.replace("{}++".format(ch), "{}".format(i + 1))
        elif "{}--".format(ch) in exp:
            values[ch] = (i + 1) - 1
            exp = exp.replace("{}--".format(ch), "{}".format(i + 1))
        elif "{}".format(ch) in exp:
            values[ch] = i + 1
            exp = exp.replace("{}".format(ch), "{}".format(i + 1))

    eval_val = eval(exp)
    print("    value = {}".format(eval_val))
    for ch in values:
        print("    {} = {}".format(ch, values[ch]))


while True:
    try:
        line = input()
    except EOFError:
        break

    run(line)
