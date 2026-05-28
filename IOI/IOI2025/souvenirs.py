N = 100


class Transaction:
    def __init__(self, M=None, L=None, R=None, spent=None, lead=None):
        self.M: int = M  # coins given
        self.L: list[int] = L  # bought type
        self.R: int = R  # returned coins
        self.spent: int = spent  # M - R = sum of prices in L
        self.lead: int = lead  # L[0]


leaderTransactions: list[Transaction] = [
    Transaction() for _ in range(N)
]  # meaningful only if hasLeader[i] is True
hasLeader: list[bool] = [False for _ in range(N)]

price: list[int] = [0 for _ in range(N)]  # recovered price
knownPrice: list[bool] = [False for _ in range(N)]

bought: list[int] = [0 for _ in range(N)]  # current bought count per type


def transaction(M: int) -> tuple[list[int], int]:
    # This function is a placeholder for the actual transaction logic.
    # It should return a tuple containing a list of bought types and the number of returned coins based on the input M.
    pass


def runTransaction(M: int) -> Transaction:
    (L, R) = transaction(M)

    for t in L:
        bought[t] += 1

    newTransaction = Transaction(M=M, L=L, R=R, spent=M - R, lead=L[0])
    return newTransaction


def discoverLeader(M: int) -> int:
    transaction = runTransaction(M)
    a = transaction.lead

    assert hasLeader[a] == False

    leaderTransactions[a] = transaction
    hasLeader[a] = True

    return a


def nextAmountFromWhole(transaction: Transaction) -> int:
    k = len(transaction.L)
    S = transaction.spent

    if k == 1:
        return S - 1
    else:
        return S // k


def buildSpine(P0: int) -> list[int]:
    spine = []
    a = discoverLeader(P0 - 1)
    spine.append(a)

    while spine[-1] != N - 1:
        transaction = leaderTransactions[spine[-1]]
        M = nextAmountFromWhole(transaction)

        b = discoverLeader(M)
        assert b > spine[-1]

        spine.append(b)

    return spine


def recoverPrice(i: int) -> None:
    val = leaderTransactions[i].spent
    for t in leaderTransactions[i].L:
        if t > i:
            assert knownPrice[t]
            val -= price[t]

    price[i] = val
    knownPrice[i] = True


def partialUnknownPart(transaction: Transaction, boundary: int) -> tuple[int, int]:
    sum = transaction.spent
    cnt = 0

    for t in transaction.L:
        if t >= boundary:
            assert knownPrice[t]
            sum -= price[t]
        else:
            cnt += 1

    return (sum, cnt)


def makeLeaderBetween(left: int, right: int) -> int:
    transaction = leaderTransactions[left]
    (sum, cnt) = partialUnknownPart(transaction, right)

    if cnt == 1:
        M = sum - 1
    else:
        M = sum // cnt

    mid = discoverLeader(M)

    return mid


def fillGap(left: int, right: int) -> None:
    if left + 1 == right:
        recoverPrice(left)
        return

    mid = makeLeaderBetween(left, right)

    fillGap(mid, right)
    recoverPrice(mid)
    fillGap(left, mid)


def buy_souvenirs(N: int, P0: int) -> None:
    # init
    for i in range(N):
        hasLeader[i] = False
        knownPrice[i] = False
        bought[i] = 0

    price[0] = P0
    knownPrice[0] = True

    spine = buildSpine(P0)

    recoverPrice(spine[-1])

    for i in range(len(spine) - 2, -1, -1):
        left = spine[i]
        right = spine[i + 1]
        fillGap(left, right)
        recoverPrice(left)

    # finish purchase
    for i in range(N):
        while bought[i] < 1:
            runTransaction(price[i])
