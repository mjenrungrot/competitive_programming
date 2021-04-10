#include <bits/stdc++.h>
using namespace std;

const int MAXVAL = 3010;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    vector <int> count(MAXVAL<<1);
    while(T--){
        string expr;
        cin >> expr;

        int N;
        cin >> N;

        // Read and counting sort
        for(int i=0;i<N;i++){
            int tmp;
            cin >> tmp;
            count[tmp+MAXVAL]++;
        }

        deque <int> xs(N);
        int curr = 0;
        for(int i=0;i<(MAXVAL<<1);i++){
            while(count[i]){
                xs[curr++] = i-MAXVAL;
                count[i]--;
            }
        }

        int ans = 0;
        stack <bool> is_positive;
        is_positive.push(true);
        bool positive = true;
        for(int i=0;i<expr.length();i++){
            if(expr[i] == '('){
                is_positive.push(positive);
            }else if(expr[i] == ')'){
                is_positive.pop();
            }else if(expr[i] == '+'){
                positive = is_positive.top(); // same as current
            }else if(expr[i] == '-'){
                positive = not is_positive.top(); // opposite as current
            }else{
                if(positive){
                    ans += xs.back();
                    xs.pop_back();
                }else{
                    ans -= xs.front();
                    xs.pop_front();
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}