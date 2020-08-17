mark_up = True
while True:
    try:
        line = input()
    except EOFError:
        break

    curr = 0
    length = len(line)
    while curr < length:
        if line[curr] == '\\':
            if mark_up:
                if line[curr+1] == 'b':
                    curr += 2
                elif line[curr+1] == 'i':
                    curr += 2
                elif line[curr+1] == 's':
                    k = 2
                    while curr+k < length and ord('0') <= ord(line[curr+k]) <= ord('9'):
                        k += 1
                    if curr+k < length and line[curr+k] == '.': k += 1
                    while curr+k < length and ord('0') <= ord(line[curr+k]) <= ord('9'):
                        k += 1
                    curr += k
                elif line[curr+1] == '*':
                    mark_up = not mark_up
                    curr += 2
                else:
                    print(line[curr+1], end="")
                    curr += 2
            else:
                if curr+1 < length and line[curr+1] == '*':
                    mark_up = not mark_up
                    curr += 2
                else:
                    print(line[curr], end="")
                    curr += 1
        else:
            print(line[curr], end="")
            curr += 1

    print("")