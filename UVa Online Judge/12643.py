import sys

lines = sys.stdin.readlines()

for line in lines:
    line = line.strip()
    N, i, j = list(map(int, line.split()))

    ans = 0
    while i != j:
        if i % 2: i = (i+1) // 2
        else: i = i // 2

        if j % 2: j = (j+1) // 2
        else: j = j // 2
        ans += 1
    print(ans)