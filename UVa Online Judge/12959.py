while True:
    try:
        J, R = list(map(int, input().split()))
        scores = list(map(int, input().split()))
    except EOFError:
        break

    person_scores = [0 for _ in range(J)]

    counter = 0
    winner = 0
    for r in range(R):
        for j in range(J):
            person_scores[j] += scores[counter]
            counter += 1
            if person_scores[j] >= person_scores[winner]:
                winner = j
    print(winner + 1)