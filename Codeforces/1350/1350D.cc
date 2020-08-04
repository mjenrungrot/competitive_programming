#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[100005];

/*
{-1,0,1}


{0,1} => work
{-1,0,0} => work
{0,-1,-1,0,-1,0}
*/

void run(){
    scanf("%d %d", &N, &K);
    for(int i=1;i<=N;i++) scanf("%d",&A[i]);

    bool check = false;
    int max_val = A[1];
    for(int i=1;i<=N;i++){
        if(A[i] == K) check = true;
    }

    if(not check){
        printf("no\n");
        return;
    }

    if(N == 1){
        printf("yes\n");
        return;
    }
    
    for(int i=1; i<=N; i++){
        if(i+1 <= N and A[i] >= K and A[i+1] >= K){ printf("yes\n"); return;}
        else if(i+2 <= N and A[i] >= K and A[i+2] >= K){ printf("yes\n"); return;}
    }

    printf("no\n");
    return;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) run();
    return 0;
}