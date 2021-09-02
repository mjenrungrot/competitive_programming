# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        618.py
#  Description:     UVa Online Judge - 618
# =============================================================================
import math
from copy import deepcopy
from itertools import permutations


class Rectangle:
    def __init__(self, W, H):
        self.W = W
        self.H = H

    def rotate(self):
        self.W, self.H = self.H, self.W

    def small(self):
        gg = math.gcd(self.W, self.H)
        self.W //= gg
        self.H //= gg

    def __repr__(self):
        return "({},{})".format(self.W, self.H)


def case1(screen, windows, n):
    """
    -----------------
    | A | B | C | D |
    -----------------
    """
    total_width = 0
    for i in range(n):
        if screen.H % windows[i].H != 0:
            return False
        total_width += windows[i].W * (screen.H // windows[i].H)
    return total_width == screen.W


def case2(screen, windows, n):
    """
    -------------
    |     A     |
    -------------
    | B | C | D |
    -------------
    """
    if n <= 1:
        return False
    if screen.W % windows[0].W != 0:
        return False
    win0_height = (screen.W // windows[0].W) * windows[0].H
    if win0_height > screen.H:
        return False
    return check(Rectangle(screen.W, screen.H - win0_height), windows[1:], n - 1)


def case3(screen, windows, n):
    """
    ---------
    | A | B |
    ---------
    | C | D |
    ---------
    """
    if n <= 2:
        return False
    h_AB = windows[0].H * windows[1].H // math.gcd(windows[0].H, windows[1].H)
    if h_AB > screen.H:
        return False
    w_AB = h_AB // windows[0].H * windows[0].W + h_AB // windows[1].H * windows[1].W
    if screen.W % w_AB != 0:
        return False
    total_height = screen.W // w_AB * h_AB
    if total_height > screen.H:
        return False
    return check(Rectangle(screen.W, screen.H - total_height), windows[2:], n - 2)


def check_helper(screen, windows, n):
    if case1(screen, windows, n):
        return True

    if n > 1:
        for k in range(n):
            tmp_windows = deepcopy(windows)
            tmp_windows[0], tmp_windows[k] = tmp_windows[k], tmp_windows[0]
            if case2(screen, tmp_windows, n):
                return True

    if n >= 2:
        for perm in permutations(range(n)):
            tmp_windows = [windows[x] for x in perm]
            if case3(screen, tmp_windows, n):
                return True

    return False


def check(screen, windows, n):
    if n == 0:
        return True
    if check_helper(screen, windows, n):
        return True

    screen.rotate()
    for i in range(len(windows)):
        windows[i].rotate()
    return check_helper(screen, windows, n)


test_no = 0
while True:
    line = input()
    if line == "":
        continue
    line = list(map(int, line.split()))
    if line[0] == line[1] == 0:
        break

    W, H = line[:2]

    screen = Rectangle(W, H)
    windows = []
    for i in range(4):
        window = Rectangle(*line[2 * i + 2 : 2 * i + 4])
        window.small()
        windows.append(window)

    ans = check(screen, windows, 4)
    test_no += 1
    if ans:
        print("Set {}: Yes".format(test_no))
    else:
        print("Set {}: No".format(test_no))
