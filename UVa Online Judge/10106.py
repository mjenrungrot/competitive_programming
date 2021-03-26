while True:
    try:
        a = int(input())
        b = int(input())
    except EOFError:
        break

    print(a*b) 