#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

long long INF = 4e18+100;

long long N, K;
int A[100005];
long long sum, tmp[100005];

bool test(long long d){
    long long l, r, m;
    sum = 0;
    for(int i=1;i<=N;i++){
        l = 0;
        r = A[i]+1;
        while(l < r){
            m = (l + r) / 2;
            // printf("test [%lld, %lld] %lld\n", l, r, m);
            if((long long)A[i] - (3LL*m*m - 3*m + 1) >= d) l = m+1;
            else r = m;
        }
        tmp[i] = l-1;
        sum += tmp[i];
    }
    return sum >= K;
}

long long searchHighestIncrement(){
    long long l = -INF, r = INF, m;
    // for(int tt = 0 ;tt < 63; tt++){
    while(l<r){
        m = (l+r)/2;
        if(m < 0 and m * 2 != (l+r)) m -= 1;
        // printf("test [%lld, %lld] %lld\n", l, r, m);
        if(test(m)){
            l = m+1;
        }else{
            r = m;
        }
    }
    return l - 1;
}

int main(){
    scanf("%lld %lld", &N, &K);

    for(int i=1;i<=N;i++) scanf("%d", &A[i]);
    long long l = searchHighestIncrement();
    test(l);
    // printf("l = %lld\n", l);
    for(int i=1;i<=N;i++){
        // printf("[%d] [%d] %lld\n",i, tmp[i], (long long)A[i] - (3LL*tmp[i]*tmp[i] - 3*tmp[i] + 1));

        if((long long)A[i] - (3LL*tmp[i]*tmp[i] - 3*tmp[i] + 1) == l && sum > K){
            sum--;
            tmp[i]--;
        }
        if(i > 1) printf(" ");
        printf("%lld", tmp[i]);
    }
    printf("\n");
    // printf("sum = %lld\n", sum);
    return 0;
}