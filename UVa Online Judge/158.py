# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        158.py
#  Description:     UVa Online Judge - 158
# =============================================================================
import datetime
import re

Y = int(input())
newline = False
events = []
counter = 0
while True:
    line = input()
    if line == '#': break

    line = re.split(r'(\s+)', line)
    event = line[0]

    if event == 'A':
        D = int(line[2])
        M = int(line[4])
        P = int(line[6])
        date = datetime.date(Y, M, D)

        name = (''.join(line[8:]))
        counter += 1
        events.append((date, P, name, counter))

        leap = ((Y+1) % 400 == 0) or ((Y+1) % 100 != 0 and (Y+1)%4 == 0)
        if not leap and M == 2 and D == 29: continue
        new_date = datetime.date(Y+1, M, D)
        counter += 1
        events.append((new_date, P, name, counter))
    else:
        if newline: print("")
        newline = True

        D = int(line[2])
        M = int(line[4])
        date = datetime.date(Y, M, D)
        print("Today is:{:3d} {:2d}".format(date.day, date.month))

        outputs = []
        for event in events:
            event_date, event_P, event_name, event_id = event
            if event_date > date and event_P - (event_date - date).days + 1 > 0:
                outputs.append((event_date, event_P - (event_date - date).days + 1, event_name, event_id))
            elif event_date == date:
                outputs.append((event_date, 7, event_name, event_id))

        outputs.sort(key=lambda x: (x[0], -x[1], x[3]))

        for output in outputs:
            print("{:3d} {:2d} ".format(output[0].day, output[0].month), end="")
            if output[0] == date:
                print("*TODAY*", end="")
            else:
                print("*" * output[1], end="")
                print(" " * (7 - output[1]), end="")
            print(" {}".format(output[2]))