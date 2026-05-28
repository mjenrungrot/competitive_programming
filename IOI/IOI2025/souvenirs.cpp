#include <cassert>
#include <utility>
#include <vector>
using namespace std;

pair<vector<int>, long long> transaction(long long M);

namespace {

const int MAX_N = 100;

struct Transaction {
    long long M = 0;
    vector<int> L;
    long long R = 0;
    long long spent = 0;
    int lead = -1;
};

int currentN;
Transaction leaderTransactions[MAX_N];
bool hasLeader[MAX_N];

long long price[MAX_N];
bool knownPrice[MAX_N];

int bought[MAX_N];

Transaction runTransaction(long long M) {
    auto result = transaction(M);
    const vector<int>& L = result.first;
    long long R = result.second;

    for (int t : L) {
        bought[t]++;
    }

    Transaction newTransaction;
    newTransaction.M = M;
    newTransaction.L = L;
    newTransaction.R = R;
    newTransaction.spent = M - R;
    newTransaction.lead = L[0];
    return newTransaction;
}

int discoverLeader(long long M) {
    Transaction tx = runTransaction(M);
    int a = tx.lead;

    assert(!hasLeader[a]);

    leaderTransactions[a] = tx;
    hasLeader[a] = true;

    return a;
}

long long nextAmountFromWhole(const Transaction& tx) {
    int k = (int)tx.L.size();
    long long S = tx.spent;

    if (k == 1) {
        return S - 1;
    }
    return S / k;
}

vector<int> buildSpine(long long P0) {
    vector<int> spine;
    int a = discoverLeader(P0 - 1);
    spine.push_back(a);

    while (spine.back() != currentN - 1) {
        const Transaction& tx = leaderTransactions[spine.back()];
        long long M = nextAmountFromWhole(tx);

        int b = discoverLeader(M);
        assert(b > spine.back());

        spine.push_back(b);
    }

    return spine;
}

void recoverPrice(int i) {
    long long val = leaderTransactions[i].spent;
    for (int t : leaderTransactions[i].L) {
        if (t > i) {
            assert(knownPrice[t]);
            val -= price[t];
        }
    }

    price[i] = val;
    knownPrice[i] = true;
}

pair<long long, int> partialUnknownPart(const Transaction& tx, int boundary) {
    long long remSum = tx.spent;
    int cnt = 0;

    for (int t : tx.L) {
        if (t >= boundary) {
            assert(knownPrice[t]);
            remSum -= price[t];
        } else {
            cnt++;
        }
    }

    return {remSum, cnt};
}

int makeLeaderBetween(int left, int right) {
    const Transaction& tx = leaderTransactions[left];
    pair<long long, int> unknown = partialUnknownPart(tx, right);
    long long remSum = unknown.first;
    int cnt = unknown.second;

    long long M;
    if (cnt == 1) {
        M = remSum - 1;
    } else {
        M = remSum / cnt;
    }

    int mid = discoverLeader(M);
    return mid;
}

void fillGap(int left, int right) {
    if (left + 1 == right) {
        recoverPrice(left);
        return;
    }

    int mid = makeLeaderBetween(left, right);

    fillGap(mid, right);
    recoverPrice(mid);
    fillGap(left, mid);
}

}  // namespace

void buy_souvenirs(int N, long long P0) {
    currentN = N;

    for (int i = 0; i < N; i++) {
        leaderTransactions[i] = Transaction();
        hasLeader[i] = false;
        knownPrice[i] = false;
        bought[i] = 0;
    }

    price[0] = P0;
    knownPrice[0] = true;

    vector<int> spine = buildSpine(P0);

    recoverPrice(spine.back());

    for (int i = (int)spine.size() - 2; i >= 0; i--) {
        int left = spine[i];
        int right = spine[i + 1];
        fillGap(left, right);
        recoverPrice(left);
    }

    for (int i = 1; i < N; i++) {
        while (bought[i] < i) {
            runTransaction(price[i]);
        }
    }
}
