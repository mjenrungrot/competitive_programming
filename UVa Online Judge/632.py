# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        632.py
#  Description:     UVa Online Judge - 632
# =============================================================================

def run():
    N = int(input())
    S0 = ""

    while True:
        try:
            line = input()
        except EOFError:
            break

        if len(line) == 0:
            break

        S0 += line

    all_words = []
    for i in range(len(S0)):
        word = S0[i:] + S0[:i]
        all_words.append((word, i))

    all_words.sort()

    S1_idx = -1
    last_column = ""
    for i in range(len(all_words)):
        last_column += "{}".format(all_words[i][0][-1])
        if all_words[i][1] == 1:
            S1_idx = i

    print(S1_idx)
    for i in range(0, len(last_column), 50):
        ending_idx = min(len(last_column), i+50)
        print(last_column[i:ending_idx])

if __name__ == '__main__':
    T = int(input())
    _ = input()
    for i in range(T):
        if(i):
            print("")
        run()