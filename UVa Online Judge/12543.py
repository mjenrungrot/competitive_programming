# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12543.py
#  Description:     UVa Online Judge - 12543
# =============================================================================

import re

best_word = ""

while True:
    try:
        line = input()
    except EOFError:
        break

    terminate = False
    all_words = list(map(lambda x: x[0], re.findall(r"([a-zA-Z]+(\-[a-zA-Z]+)*)", line)))
    for word in all_words:
        if word == 'E-N-D':
            terminate = True
            break
        if len(word) > len(best_word):
            best_word = word
    
    if terminate:
        break

print(best_word.lower())