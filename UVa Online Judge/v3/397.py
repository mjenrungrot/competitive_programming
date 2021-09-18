# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        397.py
#  Description:     UVa Online Judge - 397
# =============================================================================


def parse_number(x, offset):
    output = ""

    curr = offset
    while curr < len(x):
        if x[curr] == " ":
            curr += 1
            continue

        if len(output) == 0 and x[curr] in "-+":
            output += x[curr]
            curr += 1
        elif x[curr].isdigit():
            output += x[curr]
            curr += 1
        else:
            break

    return str(int(output)), curr


def parse_operand(x, offset):
    output = ""

    curr = offset
    while curr < len(x):
        if x[curr] == " ":
            curr += 1
            continue

        output += x[curr]
        curr += 1
        break

    return output, curr


newline = False
while True:
    try:
        line = input()
    except EOFError:
        break

    if newline:
        print("")
    newline = True
    eqs, var = line.split("=")

    # Parsing
    parsed_eqs = []
    curr = 0
    x, curr = parse_number(eqs, curr)
    parsed_eqs.append(x)
    while curr < len(eqs):
        if eqs[curr] == " ":
            curr += 1
            continue

        x, curr = parse_operand(eqs, curr)
        parsed_eqs.append(x)

        x, curr = parse_number(eqs, curr)
        parsed_eqs.append(x)

    # Run
    while True:
        print("{} = {}".format(" ".join(parsed_eqs), var))
        if len(parsed_eqs) == 1:
            break

        # check * /
        passed = False
        for i, token in enumerate(parsed_eqs):
            if token in "*/":
                lhs = int(parsed_eqs[i - 1])
                rhs = int(parsed_eqs[i + 1])

                if token == "*":
                    val = str(lhs * rhs)
                else:
                    val = str(lhs // rhs)

                del parsed_eqs[i - 1 : i + 2]
                parsed_eqs.insert(i - 1, val)
                passed = True
                break

        if passed:
            continue

        # check + -
        for i, token in enumerate(parsed_eqs):
            if token in "+-":
                lhs = int(parsed_eqs[i - 1])
                rhs = int(parsed_eqs[i + 1])

                if token == "+":
                    val = str(lhs + rhs)
                else:
                    val = str(lhs - rhs)

                del parsed_eqs[i - 1 : i + 2]
                parsed_eqs.insert(i - 1, val)
                passed = True
                break
