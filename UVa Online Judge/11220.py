def run():
    while True:
        try:
            line = input()
        except EOFError:
            break

        if len(line) == 0: break
        output = ""
        curr = 0
        words = line.split()
        for i in range(len(words)):
            if len(words[i]) <= curr: continue
            output += "{}".format(words[i][curr])
            curr += 1
        print(output)

if __name__ == '__main__':
    T = int(input())
    _ = input()
    for i in range(T):
        if(i): print("")
        print("Case #{}:".format(i+1))
        run()