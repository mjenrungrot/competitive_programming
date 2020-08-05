from collections import deque

def check(x):
    if len(x) == 0: return False, []
    if x[0] == 'N':
        x.popleft()
        return check(x)
    elif x[0] in "CDEI":
        x.popleft()
        valid, rem = check(x)
        if valid: return check(rem)
        else: return False, []
    elif ord('p') <= ord(x[0]) <= ord('z'):
        x.popleft()
        return True, x
    else:
        return False, []

while True:
    try:
        line = input()
    except EOFError:
        break

    data = deque(line)
    valid, rem = check(data)

    if valid and len(rem) == 0: print("YES")
    else: print("NO")


