# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10921.py
#  Description:     UVa Online Judge - 10921
# =============================================================================

source = list("-1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ")
target = list("-123456789022233344455566677778889999")
mapping = dict(zip(source, target))

while True:
    try:
        line = input()
    except EOFError:
        break

    print("".join(list(map(lambda x: mapping[x], line))))
