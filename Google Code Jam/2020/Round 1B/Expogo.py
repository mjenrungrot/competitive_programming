import time
import pprint

global_sol = {}

def gen(x, y, step, s):
    if step >= 11:
        return
    if (x,y,step) in global_sol:
        return
    global_sol[(x, y, step)] = s

    gen(x + (1 << step), y, step+1, s + "E")
    gen(x - (1 << step), y, step+1, s + "W")
    gen(x, y + (1 << step), step+1, s + "N")
    gen(x, y - (1 << step), step+1, s + "S")

def run():
    x, y = input().strip().split()
    x = int(x)
    y = int(y)

    for s in range(13):
        if (x,y,s) in global_sol:
            return global_sol[(x,y,s)]

    return "IMPOSSIBLE"

if __name__ == '__main__':
    start_time = time.time()
    gen(0, 0, 0, "")
    end_time = time.time()
    print("Elapsed {}".format(end_time - start_time))

    T = int(input())
    for i in range(1, T+1):
        print("Case #{}: {}".format(i, run()))