T = int(input())
for _ in range(T):
    A = input()

    S = []
    pos = 0
    ans = 0
    for i in range(len(A)):
        if A[i] == '/':
            if len(S) > 0:
                ans += (pos - S[-1])
                S.pop()
        elif A[i] == '\\':
            S.append(pos)
        else:
            pass

        pos += 1
    print(ans)