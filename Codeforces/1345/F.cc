#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int A[100005];
int ans[100005];

struct D{
    D(long long a, int c, int d) : a(a), c(c), d(d){}
    long long a;
    int c,d;
    bool operator < (const struct D &other) const {
        return a < other.a;
    }
};

int main(){
    int N, K;
    scanf("%d %d", &N, &K);

    priority_queue <struct D> heap;
    for(int i=1;i<=N;i++) scanf("%d", &A[i]);

    for(int i=1;i<=N;i++){
        long long improvement = A[i] - 1;
        heap.push(D(improvement, 1, i));
    }

    int cnt = 0;
    memset(ans, 0, sizeof(ans));
    while(cnt < K){
        D best = heap.top();
        heap.pop();
        int b = best.c;
        int idx = best.d;
        ans[idx] += 1;

        int new_b = b+1;
        long long improvement = (long long)A[idx] - 3LL*new_b*new_b - 3LL*new_b - 1;
        if(new_b <= A[idx]){
            heap.push(D(improvement, new_b, idx));
        }

        cnt += 1;
    };

    for(int i=1;i<=N;i++){
        if(i > 1) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}