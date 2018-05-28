"""
Problem: Falling Balls
Link: https://codejam.withgoogle.com/2018/challenges/0000000000007706/dashboard
Source: Google Code Jam 2018 Round 2
"""
T = int(input())

def check(A):
    if A[0] == 0 or A[-1] == 0:
        return None
    if sum(A) != len(A):
        return None

    B = ["." * len(A) for i in range(len(A))]

    mapping = [] # (start, end, target_idx)
    start, end, target_idx = (0, 0, 0)

    currentQueueIdx = 0
    queue = []
    for i in range(len(A)):
        if A[i] > 0:
            queue.append((A[i]-1, i))

    while currentQueueIdx < len(queue):
        if queue[currentQueueIdx][0] > 0:
            end += 1
            tmpValue, tmpIdx = queue[currentQueueIdx]
            queue[currentQueueIdx] = (tmpValue-1, tmpIdx)
        else:
            mapping.append((start, end, queue[currentQueueIdx][1]))
            start = end + 1
            end = start
            currentQueueIdx += 1

    minRows = 0
    for i in range(len(mapping)):
        minRows = max(minRows, mapping[i][1] - mapping[i][2] + 1)
        minRows = max(minRows, mapping[i][2] - mapping[i][0] + 1)

    B = [list("." * len(A)) for i in range(minRows)]
    for i in range(len(mapping)):
        diff = mapping[i][1] - mapping[i][2]
        for j in range(0, diff):
            B[j][mapping[i][1] - j] = '/'
        diff = mapping[i][2] - mapping[i][0]
        for j in range(0, diff):
            B[j][mapping[i][0] + j] = '\\'

    return B

for i in range(1,T+1):
    N = int(input())
    A = list(map(int, input().split()))

    answer = check(A)
    if not answer:
        print("Case #{:}: IMPOSSIBLE".format(i))
    else:
        print("Case #{:}: {:}".format(i, len(answer)))
        for i in range(len(answer)):
            print(''.join(answer[i]))
