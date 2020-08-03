import sys

def get_rank(card):
    if card[0] == 'A': return 0
    if card[0] == 'T': return 9
    if card[0] == 'J': return 10
    if card[0] == 'Q': return 11
    if card[0] == 'K': return 12
    return ord(card[0]) - ord('1')

def evaluate(cards):
    ranks = list(map(get_rank, cards))

    bins = [0 for i in range(13)]
    for rank in ranks:
        bins[rank] += 1

    start = 0
    while bins[start] == 1:
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
    if consec_bins[0] == 5: best_score = max(best_score, 100)
    if consec_bins[0] == 4: best_score = max(best_score, 10)
    if len(consec_bins) >= 2 and consec_bins[0] == 3 and consec_bins[1] == 2: best_score = max(best_score, 5)
    if consec_bins[0] == 3: best_score = max(best_score, 3)
    if len(consec_bins) >= 2 and consec_bins[0] == 2 and consec_bins[1] == 2: best_score = max(best_score, 1)
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
        # print("Curr money = {}".format(curr_money))

        for idx in range(len(cards)):
            expectation = -47
            for rem_card in remaining_cards:
                new_decks = cards[:]
                new_decks[idx] = rem_card
                expectation += evaluate(new_decks)
                # print("\tDecks {} => {}".format(new_decks, evaluate(new_decks)))
            expectation /= 47.0
            # print("Expectation {} = {}".format(cards[idx], expectation))

            if expectation > curr_money and expectation > best_expectation:
                best_expectation = expectation
                best_choice = cards[idx]

        if best_choice:
            print("Exchange {}".format(best_choice))
        else:
            print("Stay")