#include <cstdio>

int R, C;
char A[200][200];


int main(){
    while(scanf("%d %d", &R, &C) == 2){
        double ans = 0.0;
        for(int i=1;i<=R;i++){
            scanf("%s", &A[i][1]);

            bool outside = true;
            for(int j=1;j<=C;j++){
                if(A[i][j] == '.'){
                    if(not outside) ans += 1.0;
                }else{
                    ans += 0.5;
                    outside = (not outside);
                }
            }
        }
        printf("%.0lf\n", ans);
    }
    return 0;
}