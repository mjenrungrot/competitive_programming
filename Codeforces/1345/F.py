import heapq

def run():
    N, K = list(map(int, input().split()))
    A = list(map(int, input().split()))

    heap = []
    for i in range(N):
        score1 = A[i] - 1
        score0 = 0
        improvement = score1 - score0
        heapq.heappush(heap, (-improvement, score1, 1, i))

    cnt = 0
    ans = [0 for i in range(N)]
    while cnt < K:
        best = heapq.heappop(heap)
        (score, b, idx) = (best[1], best[2], best[3])
        ans[idx] += 1

        # print("assign {} get {} [improvement = {}]".format(idx, best[1], -best[0]))

        # score = b_i (a_i - b_i^2)
        new_b = b+1
        new_score = new_b * (A[idx] - new_b * new_b)
        improvement = new_score - score
        if new_b <= A[idx]:
            heapq.heappush(heap, (-improvement, new_score, new_b, idx))

        cnt += 1

    for i in range(N):
        if i: print(" ", end="")
        print(ans[i], end="")
    print("")

if __name__ == '__main__':
    run()