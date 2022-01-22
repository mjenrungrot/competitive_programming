# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11056.py
#  Description:     UVa Online Judge - 11056
# =============================================================================
while True:
    try:
        N = int(input())
    except EOFError:
        break

    A = [] # (name, time)
    for i in range(N):
        line = input()
        
        name, time_str = line.split(" : ")
        time_token = time_str.split()
        time = 60 * 1000 * int(time_token[0]) + 1000 * int(time_token[2]) + int(time_token[4])

        A.append((name, time))

    A.sort(key=lambda x:(x[1], x[0].lower()))

    n_row = (len(A)+1)//2
    for i in range(n_row):
        start = 2*i
        end = min(start+2, len(A))
        print(f"Row {i+1}")
        for j in range(start, end):
            print(A[j][0])
    print("")


    try:
        input()
    except EOFError:
        break