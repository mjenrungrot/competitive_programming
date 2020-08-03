def check_set(tuple_x):
    if tuple_x[0] == tuple_x[1] and tuple_x[1] == tuple_x[2]: return (True, tuple_x[0])
    return (False, None)

def check_pair(tuple_x):
    if tuple_x[0] == tuple_x[1]: return (True, tuple_x[0], tuple_x[2])
    if tuple_x[0] == tuple_x[2]: return (True, tuple_x[0], tuple_x[1])
    if tuple_x[1] == tuple_x[2]: return (True, tuple_x[1], tuple_x[0])
    return (False, None, None)

def win(tuple1, tuple2):
    set1, rank1 = check_set(tuple1)
    set2, rank2 = check_set(tuple2)

    if set1 and set2: return rank1 > rank2
    elif set1: return True
    elif set2: return False

    pair1, rank_matched1, ranked_unmatched1 = check_pair(tuple1)
    pair2, rank_matched2, ranked_unmatched2 = check_pair(tuple2)

    if pair1 and pair2:
        if rank_matched1 != rank_matched2: return rank_matched1 > rank_matched2
        return ranked_unmatched1 > ranked_unmatched2
    elif pair1: return True
    elif pair2: return False

    return False

while True:
    A, B, C = list(map(int, input().strip().split()))

    if A == B == C == 0:
        break

    done = False
    for rank_matched in range(1, 14):
        for rank_unmatched in range(1, 14):
            if rank_matched == rank_unmatched: continue
            if win((rank_matched, rank_matched, rank_unmatched), (A, B, C)):
                if rank_matched < rank_unmatched: print("{} {} {}".format(rank_matched, rank_matched, rank_unmatched))
                else: print("{} {} {}".format(rank_unmatched, rank_matched, rank_matched))
                done = True
                break
        if done: break

    if not done:
        for i in range(1, 14):
            if win((i, i, i), (A, B, C)):
                print("{} {} {}".format(i, i, i))
                done = True
                break

    if not done:
        print("*")