#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, u, v;
    while(cin >> a >> u >> v){
        int k = 0, max_amount = 0;
        int thief_distance;

        int ans = -1;
        // horizontal
        while(true){
            max_amount = k * (k+1) / 2;
            thief_distance = a + u * k;
            if(max_amount >= thief_distance){
                ans = max(ans, k);
                break;
            }
            k++;
        }
        
        // vertical
        while(true){
            max_amount = k * (k+1) / 2;
            thief_distance = v * k;
            if(max_amount >= thief_distance){
                ans = max(ans, k);
                break;
            }
            k++;
        }

        cout << ans << endl;
    }
    return 0;
}