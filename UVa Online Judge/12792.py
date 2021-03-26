import sys

def func(line):
    N = int(line)

    counter = 0
    curr = 1
    while True:
        counter += 1
        if curr <= N // 2:
            curr *= 2
        else:
            curr = (curr - N // 2) * 2 - 1

        if curr == 1:
          break
    print(counter)

lines = sys.stdin.readlines()
for line in lines:
    func(line)