# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12626.py
#  Description:     UVa Online Judge - 12626
# =============================================================================

from collections import Counter

T = int(input())

for i in range(T):
    line = input()
    counter = Counter(line)
    ans = min(counter['M'], counter['A'] // 3, counter['R'] // 2, counter['G'], counter['I'], counter['T'])
    print(ans)