import datetime

def check_julian(Y, M, D):
    if Y < 1752: return True
    elif Y == 1752:
        if M < 9: return True
        elif M == 9 and D < 14: return True
    return False

def valid(Y, M, D, julian):
    if Y <= 0: return False
    if M <= 0 or M >= 13: return False
    if Y == 1752 and M == 9 and 2 < D < 14: return False
    try:
        if julian:
            year_parity = 4 if Y % 4 == 0 else 1
            date = datetime.date(year_parity, M, D)
        else:
            date = datetime.date(Y, M, D)
    except ValueError:
        return False
    return True

def run(Y, M, D):
    julian = check_julian(Y, M, D)

    if not valid(Y, M, D, julian):
        print("{}/{}/{} is an invalid date.".format(M, D, Y))
        return

    if(julian):
        year_parity = 4 if Y % 4 == 0 else 1
        date = datetime.date(1, 1, 1) + \
                datetime.timedelta(days=365 * (Y-1) + 5) + \
                (datetime.date(year_parity, M, D) - datetime.date(year_parity, 1, 1)) + \
                datetime.timedelta(days=((Y-1)//4))
        print("{} {}, {} is a {}".format(datetime.date(1,M,1).strftime("%B"), D, Y, date.strftime("%A")))
    else:
        date = datetime.date(Y, M, D)
        print("{} {}, {} is a {}".format(date.strftime("%B"), D, Y, date.strftime("%A")))

while True:
    M, D, Y = list(map(int, input().split()))
    if Y == M == D == 0: break
    run(Y, M, D)
