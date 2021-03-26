import datetime
from itertools import accumulate

date = ['Saturday', 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday']
month = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
n_days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
n_days_accum = list(accumulate(n_days))

def n_days(D, M, Y, system="old"):
    """
    January 1, 1 = day 0
    """
    if system == "old":
        leap = (Y % 4 == 0)
        output = 0
        output += 365 * (Y-1) + (Y-1) // 4
        output += n_days_accum[M-1] + 1 if (leap and M > 2) else n_days_accum[M-1]
        output += (D-1)
        return output
    else:
        leap = (Y % 400 == 0) or (Y % 4 == 0 and Y % 100 != 0)
        output = 0
        output += 365 * (Y-1) + (Y-1) // 4 - (Y-1) // 100 + (Y-1) // 400
        output += n_days_accum[M-1] + 1 if (leap and M > 2) else n_days_accum[M-1]
        output += (D-1)
        return output

def run(x):
    x = x.split()
    input_date = date.index(x[0])
    D = int(x[1])
    M = 1 + month.index(x[2])
    Y = int(x[3])

    old_system = n_days(D, M, Y, 'old')
    new_system = n_days(D, M, Y, 'new')
    if input_date == old_system % 7:
        # old -> new
        year_parity = 4 if (Y % 4 == 0) else 3
        curr_date = datetime.date(year_parity, M, D)
        if Y % 400 == 0:
            offset = (Y-1) // 100 - (Y-1) // 400 - 2
        elif Y % 100 == 0:
            offset = (Y-1) // 100 - (Y-1) // 400 + (1 if M > 2 else 0) - 2
        elif Y % 4 == 0:
            offset = (Y-1) // 100 - (Y-1) // 400 - 2
        else:
            offset = (Y-1) // 100 - (Y-1) // 400 - 2
        new_date = curr_date + datetime.timedelta(days=offset)
        year_offset = new_date.year - curr_date.year
        print(date[input_date], new_date.strftime("%-d %B"), Y + year_offset)
    else:
        # new -> old
        year_parity = 4 if (Y % 4 == 0) else 3
        curr_date = datetime.date(year_parity, M, D)
        if Y % 400 == 0:
            offset = (Y-1) // 100 - (Y-1) // 400 - 2
        elif Y % 100 == 0:
            offset = (Y-1) // 100 - (Y-1) // 400 + (1 if M > 2 else 0) - 2
        elif Y % 4 == 0:
            offset = (Y-1) // 100 - (Y-1) // 400 - 2
        else:
            offset = (Y-1) // 100 - (Y-1) // 400 - 2
        new_date = curr_date - datetime.timedelta(days=offset)
        year_offset = curr_date.year - new_date.year
        print(date[input_date], new_date.strftime("%-d* %B"), Y - year_offset)

if __name__ == '__main__':
    while True:
        x = input()
        if x == '#': break
        run(x)