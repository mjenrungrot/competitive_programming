#include <bits/stdc++.h>
using namespace std;

int T;
int N,K;

void run(){
    scanf("%d %d", &N, &K);

    if(N % 2 == 0){
        printf("%d\n", N + 2*K);
        return;
    }

    int curr = 2;
    while(N % curr != 0){
        curr++;
    }

    K--;
    N += curr;
    printf("%d\n", N + 2*K);
}

int main(){
    scanf("%d",&T);
    for(int i=1;i<=T;i++) run();
}