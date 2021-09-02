# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12820.py
#  Description:     UVa Online Judge - 12820
# =============================================================================

from collections import Counter

T = 0
while True:
    try:
        N = int(input())
    except EOFError:
        break

    ans = 0
    for i in range(N):
        counter = Counter(input())
        set_counter = set()
        passing = len(counter) >= 2
        if passing:
            for ch in counter:
                if counter[ch] in set_counter:
                    passing = False
                    break
                set_counter.add(counter[ch])
        if passing:
            ans += 1

    T += 1
    print("Case {}: {}".format(T, ans))
