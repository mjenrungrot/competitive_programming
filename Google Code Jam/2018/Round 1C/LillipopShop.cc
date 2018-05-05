/*
 * Problem: Lollipop Shop
 * Link: https://codejam.withgoogle.com/2018/challenges/0000000000007765/dashboard/000000000003e06
 * Source: Google Codejam 2018 1C
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int N;
 
int can[300];
int ccounter[300];
int D, A[300];
 
typedef pair<int,int> ii;
 
bool cmp(ii a, ii b){
    if(a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}
 
int main(){
    int T; scanf("%d", &T);
    for(int id=1;id<=T;id++){
        scanf("%d", &N);
        for(int i=0;i<N;i++){
            can[i] = 1;
            ccounter[i] = 0;
        }
        for(int i=1;i<=N;i++){
            scanf("%d", &D);
            if(D == -1){
                return 0;
            }
            vector <ii> V;
            for(int j=1;j<=D;j++){
                scanf("%d", &A[j]);
                ccounter[A[j]]++;
                if(can[A[j]]) V.push_back(ii(ccounter[A[j]], A[j]));
            }
            if(V.size() > 0){
                sort(V.begin(), V.end(), cmp);
                int idx = 0;
                printf("%d\n", V[idx].second);
                can[V[idx].second] = 0;
                fflush(stdout);
            }else{
                printf("-1\n");
                fflush(stdout);
            }
        }
    }
    return 0;
}
