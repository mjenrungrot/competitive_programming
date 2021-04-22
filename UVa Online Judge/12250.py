# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12250.py
#  Description:     UVa Online Judge - 12250
# =============================================================================

import sys

lines = sys.stdin.readlines()

for i, line in enumerate(lines):
    text = line.strip()
    if text == '#':
        break

    if text == "HELLO":
        ans = 'ENGLISH'
    elif text == "HOLA":
        ans = 'SPANISH'
    elif text == "HALLO":
        ans = "GERMAN"
    elif text == "BONJOUR":
        ans = "FRENCH"
    elif text == "CIAO":
        ans = "ITALIAN"
    elif text == "ZDRAVSTVUJTE":
        ans = "RUSSIAN"
    else:
        ans = "UNKNOWN"

    print("Case {}: {}".format(i+1, ans))