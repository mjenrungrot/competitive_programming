def run():
    line = input()
    curr = 0
    n = len(line)

    while curr < n:
        ch = line[curr]
        curr += 1
        num = 0
        while curr < n and line[curr].isdigit():
            num *= 10
            num += int(line[curr])
            curr += 1
        print("{}".format(ch) * num, end="")
    print("")

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print("Case {}: ".format(i+1), end="")
        run()