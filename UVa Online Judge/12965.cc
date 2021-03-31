#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int NP, NC;
vector <int> P, C;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        string tmp;
        istringstream iss;

        cin >> NP >> NC;
        getline(cin, tmp);

        P.clear();
        C.clear();

        getline(cin, tmp);
        iss.clear();
        iss.str(tmp);
        for(int i=1;i<=NP;i++){
            int tmp;
            iss >> tmp;
            P.push_back(tmp);
        }

        getline(cin, tmp);
        iss.clear();
        iss.str(tmp);
        for(int i=1;i<=NC;i++){
            int tmp;
            iss >> tmp;
            C.push_back(tmp);
        }

        sort(P.begin(), P.end());
        sort(C.begin(), C.end());

        int best_cost, best_n_angry;

        // ignore all producers by selecting the cheapest price
        best_cost = 0;
        best_n_angry = 0;
        for(int i=0;i<P.size();i++) best_n_angry += (P[i] > best_cost);

        // cout << "\t" << best_cost << " " << best_n_angry << endl;
        for(int i=0;i<P.size();i++){
            int n_angry_producers = P.size() - i - 1;
            int n_angry_consumers = lower_bound(C.begin(), C.end(), P[i]) - C.begin(); 

            if(n_angry_producers + n_angry_consumers < best_n_angry or \
               (n_angry_producers + n_angry_consumers == best_n_angry and P[i] < best_cost)
            ){
                best_n_angry = n_angry_producers + n_angry_consumers;
                best_cost = P[i];
            }
        }
        cout << best_cost << " " << best_n_angry << endl;
    }
    return 0;
}
