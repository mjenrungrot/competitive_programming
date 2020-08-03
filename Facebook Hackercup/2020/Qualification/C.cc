#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


const int MAXN = 8e5 + 100;
int N;
int P[2*MAXN], H[2*MAXN];
int dp[2*MAXN];

void run(){
    scanf("%d", &N);
    memset(dp, 0, sizeof(dp));

    int ans = 0;
    map <int,int> valToIdx;
    vector <ii> V;
    for(int i=1; i<=N; i++){
        scanf("%d %d", &P[i], &H[i]);
        P[N+i] = P[i] - H[i];
        H[N+i] = H[i];
        valToIdx[P[i]] = 0;
        valToIdx[P[N+i]] = 0;
        ans = max(ans, H[i]);
    }

    // compute index
    int counter = 0;
    vector <int> val;
    for(map<int,int>::iterator it=valToIdx.begin(); it!=valToIdx.end(); it++){
        valToIdx[it->first] = counter;
        val.push_back(it->first);
        counter++;
    }

    printf("%d\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        printf("Case #%d: ", i);
        run();
    }
    return 0;
}


0 5 
5 5 
10 5
15 10

=> [0,5] + [5,10] + [10,15]