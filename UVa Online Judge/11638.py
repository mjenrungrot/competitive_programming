import math


def run():
    M = int(input())
    S = int(input())
    thresh = list(map(int, input().split()))
    C = int(input())
    K = int(input())

    # parse config
    isOn = [None for i in range(4)]
    isHighTriggered = [None for i in range(4)]
    for i in range(4):
        if (1<<i) & C: isOn[i] = True
        else: isOn[i] = False

        if (1<<(i+4)) & C: isHighTriggered[i] = True
        else: isHighTriggered[i] = False

    A = [tuple(map(int, input().split())) for i in range(K)]
    ans = ["no" for i in range(4)]

    curr_t = 0
    for (t, temp) in A:
        curr_t += t
        if curr_t < S: continue
        left_bound = curr_t - t
        right_bound = curr_t

        if t >= M: pass
        else:
            if (left_bound - S) % M == 0: pass
            elif (left_bound + t - S) % M < (left_bound - S) % M: pass
            else: continue

        for i in range(4):
            if not isOn[i]: continue
            if isHighTriggered[i] and temp > thresh[i]: ans[i] = "yes"
            if not isHighTriggered[i] and temp < thresh[i]: ans[i] = "yes"

    for i in range(4):
        print(" {}".format(ans[i]), end="")
    print("")

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print("Case {}:".format(i+1), end="")
        run()