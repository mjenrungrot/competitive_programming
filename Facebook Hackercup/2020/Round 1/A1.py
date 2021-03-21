import math
from collections import deque

def run():
    N, K, W = list(map(int, input().split()))
    Ls = list(map(int, input().split()))
    A_L, B_L, C_L, D_L = list(map(int, input().split()))
    Hs = list(map(int, input().split()))
    A_H, B_H, C_H, D_H = list(map(int, input().split()))
    for i in range(K+1, N+1):
        Li = ((A_L * Ls[-2] + B_L * Ls[-1] + C_L) % D_L) + 1
        Ls.append(Li)
        Hi = ((A_H * Hs[-2] + B_H * Hs[-1] + C_H) % D_H) + 1
        Hs.append(Hi)

    MODULO = 1000000007
    height_queue = deque()
    curr_perim = 2 * W + 2 * Hs[0]
    ending_x = Ls[0] + W
    height_queue_len = 1
    height_queue.append((Hs[0], ending_x))
    ans = curr_perim
    # print("\ti = 0 curr = {}".format(curr_perim))
    for i in range(1, N):
        starting_x = Ls[i]
        while height_queue_len > 0 and height_queue[0][1] < starting_x:
            height_queue.popleft()
            height_queue_len -= 1

        # print(height_queue)

        if starting_x > ending_x:
            ending_x = Ls[i] + W
            curr_perim += 2 * W + 2 * Hs[i]
            height_queue.append((Hs[i], ending_x))
            height_queue_len += 1
        else:
            # print("\tCase 2 [Adding = {} {} {}]".format(Ls[i], W, Hs[i]))
            new_ending_x = Ls[i] + W
            excess_x = (ending_x - starting_x)
            curr_perim -= 2 * excess_x
            # print("-2*{}".format(excess_x))
            curr_perim += 2 * W
            # print("+2*{}".format(W))


            """
                2         5
                ___________
                |       ___|_________
                |       |            |
               4|       |            | 3
                |_______|____________|
                        4            7
            """
            max_height = -1
            while height_queue_len > 0 and Hs[i] >= height_queue[0][0]:
                max_height = max(max_height, height_queue[0][0])
                height_queue.popleft()
                height_queue_len -= 1

            height_queue.append((Hs[i], new_ending_x))
            height_queue_len += 1

            if max_height > -1:
                curr_perim -= max_height
                curr_perim += abs(Hs[i] - max_height) + Hs[i]
                # print("adding {} {}".format(abs(Hs[i] - max_height), Hs[i]))



            """            ________________
                           |              |
                2         5|              |
                ___________|              |
                |       ___|_________     | 6
                |       |  |         |    |
               4|       |  |         | 3  |
                |_______|__|_________|____|
                3       4  5         7    8
            """
            ending_x = new_ending_x
        # print("\ti = {} {}".format(i, curr_perim))
        ans = (ans * curr_perim) % MODULO
    return ans

if __name__ == '__main__':
    T = int(input())
    for i in range(1, T+1):
        print("Case #{}: {}".format(i, run()))