#include <cstdio>

int T;
int N;
char tmp[5];
char A[1000];


int main(){
    scanf("%d", &T);
    for(int _i=1;_i<=T;_i++){
        scanf("%d", &N);
        scanf("%s", tmp);
        A[1] = tmp[0];

        scanf("%s", tmp);
        A[2] = tmp[0];

        int ans = -1;
        for(int i=3;i<=N;i++){
            scanf("%s", tmp);
            A[i] = tmp[0];
            if(ans == -1 and A[i-2] != 'W' and A[i-1] != 'W' and A[i] != 'W'){
                ans = i;
            }
        }

        if(ans == -1){
            printf("Case %d: Yay! Mighty Rafa persists!\n", _i);
        }else{
            printf("Case %d: %d\n", _i, ans);
        }
    }
    return 0;
}