def run():
    lv = 0
    prev_word = ""
    while True:
        try:
            line = input()
        except EOFError:
            return

        if line == "": return
        word = line

        if lv < len(word) and lv < len(prev_word) and word[:lv+1] == prev_word[:lv+1]:
            lv += 1
            print("{}{}".format(" " * lv, word))
        else:
            while lv >= len(word) or word[:lv+1] != prev_word[:lv+1]:
                lv -= 1
            if word[:lv+1] == prev_word[:lv+1]:
                lv += 1
            print("{}{}".format(" " * lv, word))

        prev_word = word



if __name__ == '__main__':
    T = int(input())
    _ = input()
    for i in range(T):
        if i: print("")
        run()