import sys

foundCenter = False
counter = 0

def test(x, y):
    global counter
    print("{} {}".format(x, y))
    sys.stdout.flush()
    r = input()
    counter += 1
    # print("[{}] Test {} {} with result {}".format(counter,x,y,r), file=sys.stderr)
    return r

def findStart():
    for x in range(-1000000000, 1000000000, 1000000000 // 4):
        for y in range(-1000000000, 1000000000, 1000000000 // 4):
            r = test(x, y)
            if r == "CENTER":
                global foundCenter
                foundCenter = True
                return -1, -1
            elif r == "HIT":
                return x, y
            else:
                continue

def go(x, y, amount, axis, d):
    if axis == 'x' and d == '+': return (x+amount, y)
    elif axis == 'x' and d == '-': return (x-amount, y)
    elif axis == 'y' and d == '+': return (x, y+amount)
    elif axis == 'y' and d == '-': return (x, y-amount)
    else:
        print("BUG", file=sys.stderr)

def check(x, y):
    return (-1000000000 <= x <= 1000000000 and -1000000000 <= y <= 1000000000)

def find(x, y, axis='x', d='+'):
    l = 1
    r = 2000000001

    while l < r:
        m = (l + r) // 2
        x2, y2 = go(x, y, m, axis, d)
        if not check(x2, y2):
            r = m
            continue
        if test(x2, y2) == "MISS":
            r = m
        elif test(x2, y2) == "CENTER":
            global foundCenter
            foundCenter = True
            return -1
        else:
            l = m + 1

    return r - 1

def run():
    global foundCenter, counter
    counter = 0
    foundCenter = False
    x, y = findStart()
    # print("start = {},{}".format(x, y), file=sys.stderr)
    if foundCenter: return

    topmost_y = bottommost_y = leftmost_x = rightmost_x = 0

    rightmost_x = x + find(x, y, 'x', '+')
    # print("rightmost = {}".format(rightmost_x), file=sys.stderr)
    if foundCenter: return
    leftmost_x = x - find(x, y, 'x', '-')
    # print("leftmost = {}".format(leftmost_x), file=sys.stderr)
    if foundCenter: return
    topmost_y = y + find(x, y, 'y', '+')
    # print("topmost = {}".format(topmost_y), file=sys.stderr)
    if foundCenter: return
    bottommost_y = y - find(x, y, 'y', '-')
    # print("bottommost = {}".format(bottommost_y), file=sys.stderr)
    if foundCenter: return

    cx = (leftmost_x + rightmost_x) // 2
    cy = (topmost_y + bottommost_y) // 2

    # print("{}-{} {}-{}".format(leftmost_x, rightmost_x, topmost_y,bottommost_y), file=sys.stderr)
    for x in range(cx-3, cx+4):
        for y in range(cy-3, cy+4):
            if not check(x, y):
                continue
            r = test(x, y)
            if r == "CENTER":
                return
            else:
                continue
                # print("BUG", file=sys.stderr)

if __name__ == '__main__':
    T, A, B = list(map(int, input().split()))
    for i in range(T):
        run()