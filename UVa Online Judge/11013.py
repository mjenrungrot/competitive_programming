# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11013.py
#  Description:     UVa Online Judge - 11013
# =============================================================================
import sys

def get_rank(card):
    if card[0] == 'A': return 0
    if card[0] == 'T': return 9
    if card[0] == 'J': return 10
    if card[0] == 'Q': return 11
    if card[0] == 'K': return 12
    return ord(card[0]) - ord('1')

memory = {}

def evaluate(cards):
    ranks = list(map(get_rank, cards))
    sorted_ranks = tuple(sorted(ranks))

    if sorted_ranks in memory:
        return memory[sorted_ranks]

    bins = [0 for i in range(13)]
    for rank in ranks:
        bins[rank] += 1

    start = 0
    while bins[start] > 0:
        start = (start + 1) % 13
    while bins[start] == 0:
        start = (start + 1) % 13

    consec_bins = []
    n_cards = 0
    counter = 0
    curr = start
    while n_cards < 5:
        if bins[curr] > 0:
            bins[curr] -= 1
            counter += 1
        else:
            if counter > 0:
                consec_bins.append(counter)
                n_cards += counter
            counter = 0
        curr = (curr + 1) % 13
    consec_bins.sort(reverse=True)
    best_score = 0
    if consec_bins[0] == 5: best_score = 100
    elif consec_bins[0] == 4: best_score = 10
    elif len(consec_bins) >= 2 and consec_bins[0] == 3 and consec_bins[1] == 2: best_score = 5
    elif consec_bins[0] == 3: best_score = 3
    elif len(consec_bins) >= 2 and consec_bins[0] == 2 and consec_bins[1] == 2: best_score = 1
    memory[sorted_ranks] = best_score
    return best_score

if __name__ == '__main__':
    all_cards = ["{}{}".format(rank, suit) for rank in "A23456789TJQK" for suit in "SHDC"]
    while True:
        line = sys.stdin.readline()
        if line.strip() == "#":
            break
        cards = line.strip().split()

        remaining_cards = list(filter(lambda x: x not in cards, all_cards[:]))
        best_expectation = -1e9
        best_choice = None

        curr_money = evaluate(cards)

        for idx in range(len(cards)):
            expectation = -47
            for rem_card in remaining_cards:
                new_decks = cards[:]
                new_decks[idx] = rem_card
                score = evaluate(new_decks)
                expectation += score
            expectation /= 47.0

            if expectation > curr_money and expectation > best_expectation:
                best_expectation = expectation
                best_choice = cards[idx]

        if best_choice:
            print("Exchange {}".format(best_choice))
        else:
            print("Stay")