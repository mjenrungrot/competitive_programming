import sys

def match(str_A, idx):
    if idx + 5 > len(str_A): return "ERROR"
    if str_A[idx:idx+5] == "00001": return "0"
    if str_A[idx:idx+5] == "10001": return "1"
    if str_A[idx:idx+5] == "01001": return "2"
    if str_A[idx:idx+5] == "11000": return "3"
    if str_A[idx:idx+5] == "00101": return "4"
    if str_A[idx:idx+5] == "10100": return "5"
    if str_A[idx:idx+5] == "01100": return "6"
    if str_A[idx:idx+5] == "00011": return "7"
    if str_A[idx:idx+5] == "10010": return "8"
    if str_A[idx:idx+5] == "10000": return "9"
    if str_A[idx:idx+5] == "00100": return "-"
    if str_A[idx:idx+5] == "00110": return "START/STOP"
    return "ERROR"

def weight(ch):
    if len(ch) > 1:
        return -1

    if ord(ch) >= ord('0') and ord(ch) <= ord('9'):
        return ord(ch) - ord('0')
    elif ch == '-':
        return 10
    else:
        return -1

def ints():
    for line in sys.stdin:
         yield from (int(d) for d in line.split() if d.isdigit())

if __name__ == '__main__':
    counter = 1
    int_idx = 0
    all_ints = list(ints())

    while True:
        N = all_ints[int_idx]
        int_idx += 1
        if N == 0:
            break

        print("Case {}: ".format(counter), end="")
        counter += 1

        A = []
        for i in range(N):
            A.append(all_ints[int_idx])
            int_idx += 1

        if ((N + 1) % 6 != 0 or (N+1)//6 < 5):
            print("bad code")
            continue

        separator = float(min(A)) * 1.5
        lowest = 201
        highest = 0
        for i in range(N):
            x = A[i]
            if x < separator:
                x *= 2
            if x < lowest: lowest = x
            if x > highest: highest = x
        
        if not (lowest >= 95.0 * highest / 105.0):
            print("bad code")
            continue

        A = list(map(lambda x: str(1 * (x >= separator)), A))
        if A[1] == '1':
            A = A[::-1]
        A = "".join(A)

        invalid_space = False
        for i in range(5, len(A), 6):
            if A[i] == '1':
                invalid_space = True
                break

        if invalid_space:
            print("bad code")
            continue

        A = list(map(lambda i: match("".join(A), i*6), range((len(A) + 1) // 6)))
        n_start_stop = 0
        for i in range(len(A)):
            if A[i] == "START/STOP":
                n_start_stop += 1

        if n_start_stop != 2 or A[0] != "START/STOP" or A[-1] != "START/STOP":
            print("bad code")
            continue

        if "ERROR" in A:
            print("bad code")
            continue

        check_C = True
        check_K = True
        weights = list(map(weight, A))
        # print(weights)
        N = len(weights) - 4

        # check C
        weight_C = 0
        for i in range(1, N+1):
            weight_C += ((N - i) % 10 + 1) * weights[i]
        weight_C = weight_C % 11
        if weight_C != weights[-3]:
            check_C = False

        # check K
        weight_K = 0
        for i in range(1, N+2):
            weight_K += ((N - i + 1) % 9 + 1) * weights[i]
        weight_K = weight_K % 11
        if weight_K != weights[-2]:
            check_K = False

        if not check_C:
            print("bad C")
        elif not check_K:
            print("bad K")
        else:
            print("".join(A[1:-3]))
