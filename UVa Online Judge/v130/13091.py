# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        13091.py
#  Description:     UVa Online Judge - 13091
# =============================================================================


def run():
    ans = None
    for i in range(5):
        line = input()
        line_loc = line.find("|")
        l_arrow_loc = line.find("<")
        r_arrow_loc = line.find(">")

        if l_arrow_loc != -1 or r_arrow_loc != -1:
            if l_arrow_loc != -1:
                if l_arrow_loc > line_loc:
                    ans = False
                else:
                    ans = True
            else:
                if r_arrow_loc < line_loc:
                    ans = False
                else:
                    ans = True

    if ans:
        print("No Ball")
    else:
        print("Thik Ball")

    try:
        _ = input()
    except EOFError:
        return


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        print("Case {}: ".format(i + 1), end="")
        run()
