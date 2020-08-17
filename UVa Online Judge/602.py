import datetime

while True:
    M, D, Y = list(map(int, input().split()))
    if (Y, M, D) < (1752, 9, 14):
        if D == 29 and M == 2 and Y % 4 == 0 and Y % 100 != 0:
            pass
        else:
            isodate = (365 * (Y-1)) + () + D 

    else:
        date = datetime.datetime(Y, M, D)
        print("{} {}, {} is a {}".format(date.strftime('%B'),
                                         date.strftime('%-d'), 
                                         date.strftime('%Y'), 
                                         date.strftime('%A')))
    except ValueError:
        print("{}/{}/{} is an invalid date.".format(M, D, Y))
        continue

    if date < datetime.datetime(1752, 9, 14):
        new_date = date + datetime.timedelta(days=11)
    else:
        new_date = date

