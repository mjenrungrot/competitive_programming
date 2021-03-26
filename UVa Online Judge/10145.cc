#include <bits/stdc++.h>
using namespace std;

string line;
int T;
char mode;
int t_id, item_id;

map < int, set<int> > itemToExclusiveTransactions;
map < int, set<int> > itemToTransactions;
set <int> ignoredTransactions;

int main(){
    getline(cin, line);
    T = atoi(line.c_str());
    getline(cin, line);
    while(T--){
        itemToExclusiveTransactions.clear();
        itemToTransactions.clear();
        ignoredTransactions.clear();

        while(true){
            getline(cin, line);
            // printf("line = [%s]\n", line.c_str());
            if(line == "#") break;
            sscanf(line.c_str(), "%c %d %d", &mode, &t_id, &item_id);
            if(ignoredTransactions.count(t_id)){
                printf("IGNORED\n");
                continue;
            }

            if(mode == 'S'){
                map<int, set<int> >::iterator it = itemToExclusiveTransactions.find(item_id);
                if(it != itemToExclusiveTransactions.end()){ // found exclusive lock on this item id
                    int n_diff_transactions = itemToTransactions.count(item_id) ?
                                            (itemToTransactions[item_id].count(t_id) ?
                                                    itemToTransactions[item_id].size() - 1 :
                                                    itemToTransactions[item_id].size()
                                            ) : 0;
                    if(n_diff_transactions > 0){ // found exclusive lock with different transaction
                        ignoredTransactions.insert(t_id);
                        printf("DENIED\n");
                    }else{
                        itemToTransactions[item_id].insert(t_id);
                        printf("GRANTED\n");
                    }
                }else{
                    itemToTransactions[item_id].insert(t_id);
                    printf("GRANTED\n");
                }
            }else{
                int n_diff_transactions = itemToTransactions.count(item_id) ?
                                        (itemToTransactions[item_id].count(t_id) ?
                                                itemToTransactions[item_id].size() - 1 :
                                                itemToTransactions[item_id].size()
                                        ) : 0;
                if(n_diff_transactions > 0){ // found exclusive lock with different transaction
                    ignoredTransactions.insert(t_id);
                    printf("DENIED\n");
                    continue;
                }else{
                    itemToExclusiveTransactions[item_id].insert(t_id);
                    itemToTransactions[item_id].insert(t_id);
                    printf("GRANTED\n");
                }
            }
            if(cin.eof()) break;
        }
        if(T){
            getline(cin, line);
            printf("\n");
        }
    }
    return 0;
}