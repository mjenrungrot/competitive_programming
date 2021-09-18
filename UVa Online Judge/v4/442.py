# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        442.py
#  Description:     UVa Online Judge - 442
# =============================================================================
N = int(input())
matrices = []
for i in range(N):
    line = input().split()
    matrix = tuple(map(int, line[1:]))
    matrices.append((line[0], matrix))

while True:
    try:
        line = input()
    except EOFError:
        break

    ans = 0

    try:
        curr = 0
        length = len(line)
        stack = []
        length_stack = 0
        while curr < length:
            if line[curr] == "(":
                stack.append((-1, -1))
                length_stack += 1
                curr += 1
            elif line[curr] == ")":
                if stack[-2] == (-1, -1):
                    top = stack[-1]
                    stack.pop()
                    stack.pop()
                    stack.append(top)
                    length_stack -= 1
                    curr += 1
                else:
                    raise ValueError
            else:
                matrix = None
                for k in range(N):
                    if line[curr] == matrices[k][0]:
                        matrix = matrices[k][1]
                        break

                stack.append(matrix)
                length_stack += 1
                curr += 1

            while length_stack >= 2 and stack[-1] != (-1, -1) and stack[-2] != (-1, -1):
                if stack[-2][1] != stack[-1][0]:
                    raise ValueError
                l = stack[-2][0]
                m = stack[-2][1]
                r = stack[-1][1]
                ans += l * m * r
                stack.pop()
                stack.pop()
                stack.append((l, r))
                length_stack -= 1

        print(ans)
    except ValueError:
        print("error")
