#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


vector<string> get_remaining_cards(vector<string> cards){
    const string rank = "A23456789TJQK";
    const string suit = "SHDC";
    vector <string> x;
    for(auto it1=rank.cbegin(); it1!=rank.cend(); it1++){
        for(auto it2=suit.cbegin(); it2!=suit.cend(); it2++){
            string candidate = "";
            candidate = candidate + *it1 + *it2;
            bool found = false;
            for(auto card: cards){
                if(candidate == card){
                    found = true;
                    break;
                }
            }
            if(not found) x.push_back(candidate);
        }
    }
    return x;
}

int get_rank(string card){
    if(card[0] == 'A') return 0;
    else if(card[0] >= '2' and card[0] <= '9') return card[0] - '1';
    else if(card[0] == 'T') return 9;
    else if(card[0] == 'J') return 10;
    else if(card[0] == 'Q') return 11;
    else return 12;
}

int next_rank(int rank){
    return (rank + 1) % 13;
}

int evaluate(vector<string> cc){
    vector <int> ranks;
    for(int i=0; i<5; i++){
        ranks.push_back(get_rank(cc[i]));
    }
    if(next_rank(ranks[0]) == ranks[1]){
        if(next_rank(ranks[1]) == ranks[2]){
            if(next_rank(ranks[2]) == ranks[3]){
                if(next_rank(ranks[3]) == ranks[4]) return 100;
                return 10;
            }
            if(next_rank(ranks[3]) == ranks[4]) return 5;
            return 3;
        }
        if(next_rank(ranks[2]) == ranks[3]) return 1;
        return 0;
    }
    return 0;
}

int evaluate_wrapper(vector<string> cc){
    int ans = 0;
    sort(cc.begin(), cc.end());
    do{
        ans = max(ans, evaluate(cc));
    }while(next_permutation(cc.begin(), cc.end()));
    return ans;
}

int main(){
    string card;
    vector <string> cards;
    while(cin >> card){
        if(card == "#") break;
        cards.clear();
        cards.push_back(card);
        for(int i=1; i<5; i++){
            cin >> card;
            cards.push_back(card);
        }
        int curr_score = evaluate_wrapper(cards);
        vector<string> rem_cards = get_remaining_cards(cards);
        vector<string> tmp_cards = cards;

        double expectation, best_expectation = -1e9;
        int best_card, score;
        for(int i=0; i<5; i++){
            expectation = -curr_score - 1.0;
            for(auto x: rem_cards){
                tmp_cards[i] = x;
                score = evaluate_wrapper(tmp_cards);
                expectation += 1.0 / 47.0 * score;
            }
            tmp_cards[i] = cards[i];

            if(expectation > best_expectation){
                best_expectation = expectation;
                best_card = i;
            }
        }

        if(best_expectation < 0.0) printf("Stay\n");
        else printf("Exchange %s\n", cards[best_card].c_str());
    }
    return 0;
}

// TH JH QH KH AH
// 2H TC 5D 3S 6C