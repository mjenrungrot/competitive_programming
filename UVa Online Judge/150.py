month_name = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
month_ndays = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def isLeapYear(year, system):
    if system == 'old':
        if year % 4 == 0: return True
        else: return False
    else:
        if year % 400 == 0: return True
        elif year % 100 == 0: return False
        elif year % 4 == 0: return True
        else: return False

def dayOfYear(day, month, year, system):
    curr = 0
    for i in range(12):
        if month == month_name[i]:
            curr += day - 1
            break
        else:
            curr += month_ndays[i]
            if i == 1 and isLeapYear(year, system): curr += 1

    return curr

def ndays(day, month, year, system):
    if system == 'old':
        n = 365 * year
        n += (year // 4) - (year // 100)
    else:
        n = 365 * year
        n += (year // 4) - (year // 100) + (year // 400)
    
    return n + dayOfYear(day, month, year, system)

while True:
    line = input()
    if line == '#': break

    weekday, day, month, year = input().split()
    day = int(day)
    year = int(year)

    ndays_old = ndays(day, month, year, 'old')
    ndays_new = ndays(day, month, year, 'new') 
    print(ndays_old, ndays_new)