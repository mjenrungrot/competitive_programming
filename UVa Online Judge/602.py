import datetime

day_name = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Sunday', 'Saturday']
month_name = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']

while True:
    M, D, Y = list(map(int, input().split()))
    if M == D == Y == 0:
        break

    try:
        date = datetime.datetime(Y, M, D)
    except ValueError:
        print("{}/{}/{} is an invalid date.".format(M, D, Y))
        continue

    print("{} {}, {} is a {}".format(month_name[M-1], D, Y, day_name[date.isoweekday()]))
