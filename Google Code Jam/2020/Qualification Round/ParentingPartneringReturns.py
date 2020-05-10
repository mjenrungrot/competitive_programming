"""
Problem: Parenting Partnering Returns
Google Codejam - Qualification Round 2020
Link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9?show=progress
"""

def overlap(task1, task2):
    return max(task1[1], task2[1]) - min(task1[0], task2[0]) < (task1[1] - task1[0]) + (task2[1] - task2[0])

def run(idx):
    N = int(input())

    A = []
    for _ in range(N):
        start, end = list(map(int, input().split()))
        A.append((start, end))

    output = [i for i in sorted(enumerate(A), key=lambda x: x[1][0])]
    mapping, _ = zip(*output)

    impossible = False
    assignments = ['_' for _ in range(N)]
    for i in range(N):
        possible_C = True
        possible_J = True
        # Check overlap
        for j in range(i):
            if assignments[mapping[j]] == 'C' and overlap(A[mapping[i]], A[mapping[j]]):
                possible_C = False
            elif assignments[mapping[j]] == 'J' and overlap(A[mapping[i]], A[mapping[j]]):
                possible_J = False

        if possible_C:
            assignments[mapping[i]] = 'C'
        elif possible_J:
            assignments[mapping[i]] = 'J'
        else:
            impossible = True
            break

    if impossible:
        print("Case #{}: IMPOSSIBLE".format(idx))
    else:
        print("Case #{}: ".format(idx), end="")
        for i in range(len(assignments)):
            print("{}".format(assignments[i][0]), end="")
        print("")

if __name__ == '__main__':
    T = int(input())
    for i in range(1, T+1):
        run(i)
