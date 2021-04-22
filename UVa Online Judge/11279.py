# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11279.py
#  Description:     UVa Online Judge - 11279
# =============================================================================

import sys
import math

QWERTY = ["`1234567890-=",
          " qwertyuiop[]\\",
          " asdfghjkl;'",
          " zxcvbnm,./"]

DVORAK = ["`123qjlmfp/[]",
          " 456.orsuyb;=\\",
          " 789aehtdck-",
          " 0zx,inwvg'"]

QWERTY_2_home = 'asdfjkl;'
QWERTY_1_home = 'fghj'
DVORAK_home = 'ehtd'

def locate(keyboard_layout, ch):
    for i in range(len(keyboard_layout)):
        for j in range(len(keyboard_layout[i])):
            if keyboard_layout[i][j] == ch:
                return (i,j)
    return (-1,-1)

def compute(keyboard_layout, home_chs, ch):
    if ch == ' ':
        return 0

    best = math.inf
    ch = ch.lower()
    unshift = {
        '!': '1', '@': '2', '#': '3', '$': '4', '%': '5',
        '^': '6', '&': '7', '*': '8', '(': '9', ')': '0',
        '?': '/', '<': ',', '>': '.', ':': ';', '"': "'",
        '{': '[', '}': ']', '|': '\\', '~': '`', '_': '-', '+': '=',
    }
    if ch in unshift:
        ch = unshift[ch]

    (r, c) = locate(keyboard_layout, ch)
    for home_ch in home_chs:
        (r_home, c_home) = locate(keyboard_layout, home_ch)
        dist = 2*math.sqrt((r_home-r)*(r_home-r) + (c_home-c)*(c_home-c))
        if dist < best:
            best = dist
    # print(home_chs, ch, best)
    return best

if __name__ == '__main__':
    lines = sys.stdin.readlines()

    for line in lines:
        total_QWERTY2 = 0.0
        total_QWERTY1 = 0.0
        total_DVORAK = 0.0

        line = line.strip()
        for ch in line:
            total_QWERTY2 += compute(QWERTY, QWERTY_2_home, ch)
            total_QWERTY1 += compute(QWERTY, QWERTY_1_home, ch)
            total_DVORAK += compute(DVORAK, DVORAK_home, ch)

        print("{:.2f} {:.2f} {:.2f}".format(total_QWERTY2, total_QWERTY1, total_DVORAK))

