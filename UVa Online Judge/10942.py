from itertools import permutations

def run():
    c, x, y, z = list(map(int, input().split()))

    best_ans = (-1, -1, -1)
    for perm in permutations([x, y, z]):
        YY = 100*c + perm[0]
        MM = perm[1]
        DD = perm[2]

        leap_year = None
        if YY % 400 == 0: leap_year = True
        elif YY % 100 == 0: leap_year = False
        elif YY % 4 == 0: leap_year = True
        else: leap_year = False

        if DD == 0: continue
        if MM == 0: continue
        if MM > 12: continue
        if MM in [1, 3, 5, 7, 8, 10, 12] and DD > 31: continue
        if MM in [4, 6, 9, 11] and DD > 30: continue
        if MM == 2 and leap_year and DD > 29: continue
        if MM == 2 and (not leap_year) and DD > 28: continue

        if best_ans[0] == -1 or (perm[0], MM, DD) < best_ans:
            best_ans = (perm[0], MM, DD)

    if best_ans[0] == -1: print("-1")
    else: print("{:02d} {:02d} {:02d}".format(*best_ans))

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()