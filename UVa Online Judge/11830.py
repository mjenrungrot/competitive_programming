while True:
    D, N = input().split()
    D = int(D)
    if D == 0 and N == '0': break

    N = N.replace(chr(ord('0') + D), '')
    if N == "": N = '0'
    N = int(N)
    print(N)