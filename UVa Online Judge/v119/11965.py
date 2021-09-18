# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11965.py
#  Description:     UVa Online Judge - 11965
# =============================================================================


def run():
    N = int(input())
    for _ in range(N):
        line = input()

        prev_ch = line[0]
        print(line[0], end="")
        for i in range(1, len(line)):
            if line[i] == line[i - 1] == " ":
                continue
            print(line[i], end="")
        print("")


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        if i:
            print("")
        print("Case {}:".format(i + 1))
        run()
