ans = [0, 0]
for i in range(2, 1001):
    offset = 1 if i % 2 == 0 else -1
    ans.append(ans[-1] * 2 + offset)

while True:
    try:
        N = int(input())
    except EOFError:
        break

    print(ans[N])