# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        245.py
#  Description:     UVa Online Judge - 245
# =============================================================================
from collections import deque

words = deque()

while True:
    try:
        line = input()
    except EOFError:
        break
    if line == "0": break

    word = ""
    num = 0
    curr = 0
    while curr < len(line):
        if line[curr].isalpha():
            word += line[curr]
        elif line[curr].isdigit():
            num *= 10
            num += int(line[curr])
        else:
            if len(word) > 0:
                print(word, end="")
                if word in words: words.remove(word)
                words.appendleft(word)
            elif num > 0:
                tmp = words[num - 1]
                print(tmp, end="")
                del words[num - 1]
                words.appendleft(tmp)
            print(line[curr], end="")
            word = ""
            num = 0
        curr += 1

    if len(word) > 0:
        print(word)
        if word in words: words.remove(word)
        words.appendleft(word)
    elif num > 0:
        tmp = words[num - 1]
        print(tmp)
        del words[num - 1]
        words.appendleft(tmp)
    else:
        print("")