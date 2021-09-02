# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10028.py
#  Description:     UVa Online Judge - 10028
# =============================================================================

import math


def read_date(x):
    yyyy = x[:4]
    mm = x[4:6]
    dd = x[6:]
    return int(yyyy), int(mm), int(dd)


def run():
    line = input()
    yyyy, mm, dd = read_date(line)
    print("{:04d}-{:02d}-{:02d} No merit or demerit points.".format(yyyy, mm, dd))

    points = 0
    while True:
        try:
            line = input()
        except EOFError:
            break
        if len(line) == 0:
            break

        line = line.split()
        new_yyyy, new_mm, new_dd = read_date(line[0])
        val = int(line[1])

        while points < 0 and (yyyy + 1, mm, dd) <= (new_yyyy, new_mm, new_dd):
            yyyy += 1
            points = min(0, max(points + 2, (points + 1) // 2))
            if points < 0:
                print(
                    "{:04d}-{:02d}-{:02d} {} demerit point(s).".format(
                        yyyy, mm, dd, -points
                    )
                )
            elif points == 0:
                print(
                    "{:04d}-{:02d}-{:02d} No merit or demerit points.".format(
                        yyyy, mm, dd
                    )
                )

        while (
            points >= 0
            and points + 1 <= 5
            and (yyyy + 2, mm, dd) <= (new_yyyy, new_mm, new_dd)
        ):
            yyyy += 2
            points += 1
            print(
                "{:04d}-{:02d}-{:02d} {} merit point(s).".format(yyyy, mm, dd, points)
            )

        yyyy, mm, dd = new_yyyy, new_mm, new_dd
        if points > 0 and val > 2 * points:
            val -= 2 * points
            points = -val
            print(
                "{:04d}-{:02d}-{:02d} {} demerit point(s).".format(
                    yyyy, mm, dd, -points
                )
            )
        elif points > 0 and val <= 2 * points:
            points = math.floor(points - val / 2)
            if points > 0:
                print(
                    "{:04d}-{:02d}-{:02d} {} merit point(s).".format(
                        yyyy, mm, dd, points
                    )
                )
            else:
                print(
                    "{:04d}-{:02d}-{:02d} No merit or demerit points.".format(
                        yyyy, mm, dd
                    )
                )
        else:
            points -= val
            print(
                "{:04d}-{:02d}-{:02d} {} demerit point(s).".format(
                    yyyy, mm, dd, -points
                )
            )

    while points < 0:
        yyyy += 1
        points = min(0, max(points + 2, (points + 1) // 2))
        if points < 0:
            print(
                "{:04d}-{:02d}-{:02d} {} demerit point(s).".format(
                    yyyy, mm, dd, -points
                )
            )
        elif points == 0:
            print(
                "{:04d}-{:02d}-{:02d} No merit or demerit points.".format(yyyy, mm, dd)
            )

    while points >= 0 and points + 1 <= 5:
        yyyy += 2
        points += 1
        print("{:04d}-{:02d}-{:02d} {} merit point(s).".format(yyyy, mm, dd, points))


if __name__ == "__main__":
    T = int(input())
    _ = input()
    for i in range(T):
        if i:
            print("")
        run()
