# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13047.py
#  Description:     UVa Online Judge - 13047
# =============================================================================

import re

def run():
    line = input()

    t1 = max(list(map(lambda x: len(x[0]), re.findall(r"(\<(\-)*)", line))), default=-1)
    t2 = max(list(map(lambda x: len(x[0]), re.findall(r"(\<(\=)*)", line))), default=-1)
    t3 = max(list(map(lambda x: len(x[0]), re.findall(r"((\-)*\>)", line))), default=-1)
    t4 = max(list(map(lambda x: len(x[0]), re.findall(r"((\=)*\>)", line))), default=-1)
    print(max(t1, t2, t3, t4))

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print("Case {}: ".format(i+1), end="")
        run()