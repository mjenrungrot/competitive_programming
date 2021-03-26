while True:
    try:
        line = input()
    except EOFError:
        break

    if '/' in line:
        a,b  = list(map(int, line.split('/')))
        print(a // b)
    else:
        a,b  = list(map(int, line.split('%')))
        print(a % b)
