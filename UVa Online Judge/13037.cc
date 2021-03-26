#include <bits/stdc++.h>
using namespace std;

int T, N[3], ans[3][2], x;
map <int,int> chocolates;

int main(){
    scanf("%d", &T);
    for(int _i=1;_i<=T;_i++){
        chocolates.clear();
        printf("Case #%d:\n", _i);

        scanf("%d %d %d", &N[0], &N[1], &N[2]);
        for(int k=0;k<3;k++){
            for(int i=1;i<=N[k];i++){
                scanf("%d", &x);
                chocolates[x] |= (1<<k);
            }
        }

        memset(ans, 0, sizeof(ans));
        for(map<int,int>::iterator it=chocolates.begin();it!=chocolates.end();it++){
            for(int k=0;k<3;k++){
                int val_k = (1<<k) & (it->second);
                int val_others = ((0b111) - (1<<k)) & (it->second);
                if(val_k > 0 and val_others == 0){
                    // k has (it->second) and others don't have
                    ans[k][0]++;
                }
                if(val_k == 0 and val_others == (0b111 - (1<<k))){
                    // k doesn't have (it->second) but others have
                    ans[k][1]++;
                }
            }
        }
        for(int k=0;k<3;k++){
            printf("%d %d\n", ans[k][0], ans[k][1]);
        }
    }
    return 0;
}