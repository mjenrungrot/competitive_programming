# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10850.py
#  Description:     UVa Online Judge - 10850
# =============================================================================


def update(curr_time, instant):
    if curr_time % 100 < instant:
        return curr_time - (curr_time % 100) + instant
    else:
        return curr_time + (100 - curr_time % 100) + instant


def run():
    M, K = list(map(int, input().split()))

    data = [[] for i in range(M)]
    for i in range(K):
        G1, G2, V = list(map(int, input().split()))
        G1 -= 1
        G2 -= 1
        instants = list(map(int, input().split()))
        for instant in instants:
            data[G1].append((G2, instant))
            data[G2].append((G1, instant))

    for i in range(M):
        if len(data[i]) == 0:
            print("-1")
            return

    curr_time = 0
    known = [False for i in range(M)]
    known[0] = True
    known_list = [0]

    while len(known_list) < M:
        best_instant = 1e9
        for u in known_list:
            for v, instant in data[u]:
                if not known[v] and update(curr_time, instant) < best_instant:
                    best_instant = update(curr_time, instant)

        for u in known_list:
            for v, instant in data[u]:
                if not known[v] and update(curr_time, instant) == best_instant:
                    known[v] = True
                    known_list.append(v)

        curr_time = best_instant
        if best_instant == 1e9:
            print("-1")
            return

    print(curr_time)


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        run()
