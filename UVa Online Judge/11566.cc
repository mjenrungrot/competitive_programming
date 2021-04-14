#include <bits/stdc++.h>
using namespace std;

const int MAX_TOTALPRICE = 1105;
const int MAX_ITEMS = 25;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K; 
    double x, T;
    while(cin >> N >> x >> T >> K){
        if(N == 0) break;

        const double limit = (double)(N+1)*x;
        vector < vector<int> > dp_favors(MAX_ITEMS, vector<int>(MAX_TOTALPRICE, -1));
        dp_favors[0][0] = 0;

        auto extra = [](double dim_sum, double tea){
            double service = ceil((dim_sum + tea) * 0.1);
            return dim_sum + tea + service;
        };

        int max_favors = 0;
        for(int i=1;i<=K;i++){
            int price;
            cin >> price;
            
            int total_favors = 0;
            for(int j=1;j<=N+1;j++){
                int x;
                cin >> x;
                total_favors += x;
            }

            for(int tt=1;tt<=2;tt++){
                for(int n_item=2*i;n_item>=0;n_item--){
                    if(n_item + 1 > 2*(N+1)) continue;
                    for(int j=MAX_TOTALPRICE-1;j>=0;j--){
                        if(dp_favors[n_item][j] == -1) continue;

                        if(extra(j+price, T*(N+1)) > limit) continue;
                        if(j+price >= MAX_TOTALPRICE) continue;

                        dp_favors[n_item+1][j+price] = max(dp_favors[n_item+1][j+price], dp_favors[n_item][j] + total_favors);
                        max_favors = max(max_favors, dp_favors[n_item+1][j+price]);
                    }
                }
            }
        }
        double rounded_max_favors = round((double)max_favors / (N+1) * 100.0) / 100.0;
        cout << fixed << setprecision(2) << rounded_max_favors << endl;
    }
    return 0;
}