#include <bits/stdc++.h>
using namespace std;

struct data {
    int val, pos;
    bool operator < (const data &o) const {
        return val > o.val;
    }
};

int K;
int L1[760], L2[760];

int main(){
    while(scanf("%d", &K) == 1){
        for(int i=1;i<=K;i++) scanf("%d", &L1[i]);
        sort(&L1[1], &L1[K+1]);

        for(int i=1;i<=K-1;i++){
            for(int j=1;j<=K;j++) scanf("%d", &L2[j]);
            sort(&L2[1], &L2[K+1]);

            priority_queue <data> pq;
            for(int j=1;j<=K;j++) pq.push({L1[j]+L2[1], 1});

            for(int j=1;j<=K;j++){
                data tmp = pq.top(); pq.pop();
                L1[j] = tmp.val;
                if(tmp.pos + 1 <= K){
                    pq.push({tmp.val - L2[tmp.pos] + L2[tmp.pos+1], tmp.pos+1});
                }
            }
        }
        for(int i=1;i<=K;i++){
            if(i > 1) printf(" ");
            printf("%d", L1[i]);
        }
        printf("\n");
    }
    return 0;
}