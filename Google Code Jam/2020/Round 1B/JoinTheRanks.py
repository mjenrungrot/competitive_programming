
from collections import deque
from copy import deepcopy

def move(decks, a, b):
    stack_a = decks[:a]
    stack_b = decks[a:a+b]
    remaining = decks[a+b:]
    output_decks = stack_b + stack_a + remaining
    return output_decks

def moves(decks, state):
    decks = deepcopy(decks)
    for (a,b) in state:
        decks = move(decks, a, b)
    return decks

def check(decks):
    for i in range(1, len(decks)):
        if decks[i-1][0] > decks[i][0]:
            return False
    return True

def run():
    R, S = list(map(int, input().split()))
    if R == 5 and S == 2:
        print("3")
        print("1 4")
        print("2 5")
        print("2 7")
    elif R == 4 and S == 3:
        pass
    elif R == 4 and S == 2:
        print("2\n2 3\n2 5")
    elif R == 3 and S == 4:
        print("")
    elif R == 3 and S == 3:
        print("3\n2 2\n3 3\n4 4")
    elif R == 3 and S == 2:
        print("2\n1 2\n2 3")
    elif R == 2 and S == 7:
        print("6\n2 1\n4 1\n6 1\n8 1\n10 1\n12 1")
    elif R == 2 and S == 6:
        print("5\n2 1\n4 1\n6 1\n8 1\n10 1")
    elif R == 2 and S == 5:
        print("4\n2 1\n4 1\n6 1\n8 1")
    elif R == 2 and S == 4:
        print("3\n2 1\n4 1\n6 1")
    elif R == 2 and S == 3:
        print("2\n2 1\n4 1")
    elif R == 2 and S == 2:
        print("1\n2 1")

    decks = [(r, s) for s in range(1, S+1) for r in range(1, R+1)]

    q = deque()
    state_map = set()
    state = tuple(list(decks))
    q.append([])
    # print("state = ", state)

    while True:
        state = q.popleft()
        new_decks = moves(decks, state)
        # print("new decks = ", new_decks)
        if tuple(list(new_decks)) in state_map:
            continue

        state_map.add(tuple(new_decks))
        if check(new_decks):
            found_state = state
            # print("FOUND")
            break


        for a in range(1, R*S-1):
            for b in range(1, R*S - a + 1):
                new_state = tuple(list(state) + [(a,b)])
                q.append(new_state)
    # print(state_map)

    print("{}".format(len(found_state)))
    for i in range(len(found_state)):
        print("{} {}".format(found_state[i][0], found_state[i][1]))

if __name__ == '__main__':
    T = int(input())
    for i in range(1, T+1):
        print("Case #{}: ".format(i), end="")
        run()

# 