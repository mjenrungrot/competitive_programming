while True:
    try:
        line = input()
    except EOFError:
        break

    mapping = {}
    counter = 1
    for ch in line:
        if ch not in mapping:
            mapping[ch] = counter
            counter += 1

    line_num = list(map(lambda x: mapping[x], line))
    conveter = lambda x: \
        5 if x == 2 else \
        2 if x == 5 else \
        9 if x == 6 else \
        6 if x == 9 else \
        15 if x == 12 else \
        12 if x == 15 else \
        19 if x == 16 else \
        16 if x == 19 else \
        50 if x == 20 else \
        51 if x == 21 else \
        55 if x == 22 else \
        53 if x == 23 else \
        54 if x == 24 else \
        52 if x == 25 else \
        59 if x == 26 else \
        x
    line_num_converted = list(map(conveter, line_num))
    for x in line_num_converted:
        print(x, end="")
    print("")