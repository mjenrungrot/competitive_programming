def run():
    N = int(input())
    data = list(map(int, input().split()))

    turn = 0
    n_turn = 0
    ans = [0, 0]
    idx_l = 0
    idx_r = len(data)

    curr = 0
    prev_l = 0
    prev_r = 0
    while idx_l < idx_r:
        curr = 0
        if turn == 0:
            prev = prev_r
            idx = idx_l
            diff = 1
            diff_l = 1
            diff_r = 0
        else:
            prev = prev_l
            idx = idx_r - 1
            diff = -1
            diff_l = 0
            diff_r = -1

        while idx_l < idx_r and curr <= prev:
            curr += data[idx]
            ans[turn] += data[idx]
            idx += diff
            idx_l += diff_l
            idx_r += diff_r

        if turn == 0:
            prev_l = curr
        else:
            prev_r = curr
        turn = 1 - turn
        n_turn += 1

    print(n_turn, ans[0], ans[1])

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()